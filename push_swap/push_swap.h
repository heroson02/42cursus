/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:59:37 by yson              #+#    #+#             */
/*   Updated: 2022/02/25 17:15:51 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef struct s_info
{
	t_stack	*a;
	t_stack	*b;
	int		size_a;
	int		size_b;
	int		check;
}	t_info;

typedef struct s_value
{
	int	pivot1;
	int	pivot2;
	int	ra;
	int	rb;
	int	pa;
	int	pb;
}	t_value;
/*
** parsing function 
*/
int					number_check(char *source);
void				source_condition_check(t_stack *a);
int					sort_check(t_stack *a);
unsigned long long	ft_atoi_ad(char *str);
void				free_exit(t_stack *stack);
void				free_lst(t_node *head);
void				free_stack(t_stack *stack);
void				free_all(char **str);
void				error(void);
/*
** advanced list functions
*/
t_node				*aft_lstnew(int content);
t_node				*aft_lstlast(t_node *lst);
void				aft_lstadd_front(t_node **lst, t_node *new);
void				aft_lstadd_back(t_node **lst, t_node *new);
void				aft_lstread(t_node **lst);
void				aft_lstread_rev(t_node **lst);
int					aft_lstsize(t_node *lst);
int					aft_lstdata(t_node *lst, int index);
/*
** operations
*/
void				op_sa(t_info *info);
void				op_sb(t_info *info);
void				op_ss(t_info *info);
void				ft_swap_int(int *a, int *b);
void				swap_stack(t_stack *stack, int size);
void				op_pa(t_info *info);
void				op_pb(t_info *info);
void				push_top(t_stack *send, t_stack *receive);
void				push_stack(t_info *info, char *data);
t_node				*ft_pop(t_stack *stack);
void				op_ra(t_info *info);
void				op_rb(t_info *info);
void				op_rr(t_info *info);
void				rotate_stack(t_stack *stack, int size);
void				op_rra(t_info *info);
void				op_rrb(t_info *info);
void				op_rrr(t_info *info);
void				rev_rotate_stack(t_stack *stack, int size);
/*
** sort arg 3
*/
void				sort_case321_a(t_info *info);
void				sort_case312_a(t_info *info);
void				sort_case213_a(t_info *info);
void				sort_case231_a(t_info *info);
void				sort_case132_a(t_info *info);
void				sort_case123_b(t_info *info);
void				sort_case312_b(t_info *info);
void				sort_case213_b(t_info *info);
void				sort_case231_b(t_info *info);
void				sort_case132_b(t_info *info);
/*
** sort normal arg
*/
void				set_pivot(t_stack *stack, int size, t_value *var);
void				init_value(t_value *value);
void				sort_a_to_b(t_info *info, int size);
void				sort_b_to_a(t_info *info, int size);
void				sort(t_info *info, int size);
void				send_b_to_a(t_info *info, t_value *var);
void				send_a_to_b(t_info *info, t_value *var);
void				recover_stack_rb(t_info *info, t_value *var);
void				recover_stack_ra(t_info *info, t_value *var);
/*
** find max or min data in lst 
*/
int					get_max_data(t_node *lst, int size);
int					get_min_data(t_node *lst, int size);
/*
** sort low number
*/
int					sort_low_num(t_info *info, int size, int stack);
void				sort_two(t_info *info, int stack);
void				sort_three_a(t_info *info);
void				sort_three_b(t_info *info);
void				sort_five(t_info *info, int size, int min, int max);
int					check_special_num(t_info *info, int size, int stack);
void				hanlde_sort_five(int size, t_info *info, int stack);
void				sort_three_a(t_info *info);
void				sort_three_b(t_info *info);
#endif
