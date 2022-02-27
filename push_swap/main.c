/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:59:25 by yson              #+#    #+#             */
/*   Updated: 2022/02/25 12:48:31 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *stack)
{
	stack->top = NULL;
}

void	stack_input(t_info *info, int argc, char **argv)
{
	char	**input;
	int		i;
	int		j;

	i = 0;
	stack_init(info->a);
	stack_init(info->b);
	while (++i <= argc - 1)
	{
		j = -1;
		input = ft_split(argv[i], ' ');
		while (1)
		{
			if (input[++j])
				push_stack(info, input[j]);
			else
				break ;
		}
		free_all(input);
	}
	source_condition_check(info->a);
}

void	info_init(t_info *info)
{
	info->size_a = 0;
	info->size_b = 0;
	info->check = 0;
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_stack	a;
	t_stack	b;

	info_init(&info);
	info.a = &a;
	info.b = &b;
	if (argc < 2)
		exit(0);
	stack_input(&info, argc, argv);
	sort(&info, info.size_a);
	free_stack(info.a);
	exit(0);
}
