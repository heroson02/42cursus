/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:48:27 by yson              #+#    #+#             */
/*   Updated: 2022/02/25 12:11:25 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_contain(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

unsigned long long	ft_atoi_ad(char *str)
{
	int					i;
	int					minus;
	unsigned long long	result;
	unsigned long long	base_len;

	result = 0;
	minus = 1;
	i = 0;
	base_len = 10;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			error();
		if (is_contain("0123456789", str[i]) != -1)
			result = result * base_len + (is_contain("0123456789", str[i++]));
	}
	return (result * minus);
}
