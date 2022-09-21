#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

typedef struct s_list
{
    int     pipe[2];
    int     read_pipe;
    int     write_pipe;
    int     argc;
    char    **argv;
    struct s_list *prev;
    struct s_list *next;

}   t_list;

int ft_strlen(char *str)
{
    int i = 0;

    while (*str)
    {
        i++;
        str++;
    }
    return (i);
}

void ft_putstr_fd(char *str)
{
    write(2, str, ft_strlen(str));
}

void fatal_error()
{
    ft_putstr_fd("error: fatal\n");
    exit(1);
}



char *ft_strdup(char *str)
{
    char    *ret;
    int     size = ft_strlen(str);
    int     i = 0;

    if (!(ret = malloc(size + 1)))
        fatal_error();
    for (; i <= size; i++)
        ret[i] = str[i];
    return (ret);
}

t_list *ft_lstnew()
{
    t_list *ret;

    if (!(ret = malloc(sizeof(t_list))))
        fatal_error();
    ret->read_pipe = 0;
    ret->write_pipe = 0;
    ret->argc = 0;
    ret->argv = NULL;
    ret->prev = NULL;
    ret->next = NULL;

    return (ret);
}

t_list *ft_lstlast(t_list *lst)
{
    if (lst && lst->next)
        lst = lst->next;
    return (lst);
}

void    ft_lstclear(t_list *lst)
{
    t_list *temp;

    while (lst)
    {
        temp = lst;
        lst = lst->next;
        if (temp->argc > 0)
            for (int i = 0; temp->argc > i; i++)
                free(temp->argv[i]);
        free(temp->argv);
        free(temp);
    }
}

void ft_pushback(t_list **lst, t_list *input)
{
    if (!*lst)
    {
        *lst = input;
        return ;
    }
    t_list *last = ft_lstlast(*lst);
    last->next = input;
    input->prev = last;
}

void add_arg(t_list *lst, char *input)
{
    char **new_argv;

    if (!(new_argv = malloc((lst->argc + 2) * sizeof(char *))))
        fatal_error();
    for (int i = 0; lst->argc > i; i++)
        new_argv[i] = lst->argv[i];
    new_argv[lst->argc] = ft_strdup(input);
    new_argv[lst->argc + 1] = NULL;
    free(lst->argv);
    lst->argv = new_argv;
    lst->argc++;
}

t_list *parser(int argc, char **argv)
{
    static int idx = 1;
    t_list *result;
    t_list *temp;

    result = NULL;
    while (idx < argc)
    {
        if (!strcmp(argv[idx], ";"))
        {
            if (result)
            {
                idx++;
                return (result);
            }
        }
        else if (!strcmp(argv[idx], "|"))
        {
            if (!result)
                fatal_error();
            temp = ft_lstlast(result);
            temp->write_pipe = 1;
            temp = ft_lstnew();
            temp->read_pipe = 1;
            ft_pushback(&result, temp);
        }
        else
        {
            if (!result)
                result = ft_lstnew();
            add_arg(ft_lstlast(result), argv[idx]);
        }
        idx++;
    }
    return (result);
}

int builtin_cd(t_list *lst)
{
    if (lst->argc != 2)
    {
        ft_putstr_fd("error: cd: bad arguments\n");
        return (1);
    }
    else if (chdir(lst->argv[1]))
    {
        ft_putstr_fd("error: cd: cannot change directory to ");
        ft_putstr_fd(lst->argv[1]);
        ft_putstr_fd("\n");
        return (1);
    }
    return (0);
}

int exec_cmd(t_list *lst, char **envp)
{
    int status;
    pid_t pid;
    int ret;

    if (lst->write_pipe && (pipe(lst->pipe) < 0))
        fatal_error();
    if ((pid = fork()) < 0)
        fatal_error();
    if (pid == 0)
    {
        if (lst->write_pipe && (dup2(lst->pipe[1], 1) < 0))
            fatal_error();
        else if (lst->read_pipe && (dup2(lst->prev->pipe[0], 0) < 0))
            fatal_error();
        if ((ret = execve(lst->argv[0], lst->argv, envp)))
        {
            ft_putstr_fd("error: cannot execute ");
            ft_putstr_fd(lst->argv[0]);
            ft_putstr_fd("\n");
        }
        exit(ret);
    }
    else
    {
        waitpid(pid, &status, 0);
        if (lst->write_pipe && (close(lst->pipe[1]) < 0))
            fatal_error();
        else if (lst->read_pipe && (close(lst->prev->pipe[0]) < 0))
            fatal_error();
        if (WIFEXITED(status))
            return (WEXITSTATUS(status));
        return (1);
    }
}

int execute(t_list *lst, char **envp)
{
    int ret;

    while (lst)
    {
        if (!strcmp(lst->argv[0], "cd"))
            ret = builtin_cd(lst);
        else
            ret = exec_cmd(lst, envp);
        lst = lst->next;
    }
    return (ret);
}

#include <stdio.h>
void print_all(char **str)
{
    for (int i = 0; str[i]; i++)
    {
        printf("%s\n", str[i]);
    }
}

int main(int argc, char **argv, char **envp)
{
    t_list  *result;
    int     ret = 0;

    (void)envp;
    while ((result = parser(argc, argv)))
    {
        // print_all(result->argv);
        ret = execute(result, envp);
        ft_lstclear(result);
    }
#ifdef TEST_SH
	while (1);
#endif
	return (ret);
}
