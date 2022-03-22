/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ad_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:42:03 by yson              #+#    #+#             */
/*   Updated: 2022/03/22 17:54:45 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

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

static unsigned long long	ft_atoi(char *str)
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
			exit(0);
		if (is_contain("0123456789", str[i]) != -1)
			result = result * base_len + (is_contain("0123456789", str[i++]));
	}
	return (result * minus);
}

int	ft_atoi_ad(char *str)
{
	long long	num;

	num = ft_atoi(str);
	if (num > 2147483647 || num < -2147483648)
		exit(0);
	return ((int)num);
}
