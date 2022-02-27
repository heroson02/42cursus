/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:38:32 by yson              #+#    #+#             */
/*   Updated: 2021/10/12 13:28:27 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	*cur;
	unsigned char	target;

	target = (unsigned char)c;
	cur = (unsigned char *)str;
	while (1)
	{
		if (*cur == target)
			return ((char *)cur);
		if (!*cur)
			return (0);
		cur++;
	}
}

int	put_line(char **line, char *nl_next, char **backup)
{
	char	*temp;

	if (nl_next)
	{
		nl_next[0] = '\0';
		temp = ft_strdup(nl_next + 1);
		*line = ft_strdup(*backup);
		free(*backup);
		*backup = temp;
		return (1);
	}
	else if (*backup)
	{
		*line = ft_strdup(*backup);
		free(*backup);
		*backup = 0;
	}
	else
		*backup = ft_strdup("");
	return (0);
}

int	check_file_len(int fd, char *buffer, int *file_len)
{
	*file_len = read(fd, buffer, 1);
	if (*file_len > 0)
		return (1);
	else
		return (0);
}

int	check_next_newline(int fd, char **nl_next, char **backup)
{
	*nl_next = ft_strchr(backup[fd], '\n');
	if (*nl_next == 0)
		return (1);
	else
		return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*backup[MAX_FD];
	char		*nl_next;
	char		*temp;
	int			file_len;

	if (fd < 0 || !line || fd > MAX_FD)
		return (-1);
	buffer = malloc(2);
	if (!buffer)
		return (-1);
	if (!backup[fd])
		backup[fd] = ft_strdup("");
	while (check_next_newline(fd, &nl_next, backup)
		&& check_file_len(fd, buffer, &file_len))
	{
		buffer[file_len] = '\0';
		temp = ft_strjoin(backup[fd], buffer);
		free(backup[fd]);
		backup[fd] = temp;
	}
	free(buffer);
	if (file_len == -1)
		return (-1);
	return (put_line(line, nl_next, &backup[fd]));
}
