/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:20:43 by gpaeng            #+#    #+#             */
/*   Updated: 2022/03/17 14:07:57 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 5 && argc != 6)
		return (ft_error("[Error] check argc"));
	if (ft_philo_input(&game, argv, argc))
		return (ft_error("[Error] check philo input"));
	if (ft_philo_start(&game, (&game)->philo))
		return (ft_error("[Error] check philo start"));
	return (0);
}
