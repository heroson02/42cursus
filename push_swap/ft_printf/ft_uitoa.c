/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 22:05:14 by yson              #+#    #+#             */
/*   Updated: 2021/07/20 00:05:24 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_numlen(unsigned long long n)
{
	unsigned long long	len;

	if (n > 0)
		len = 0;
	else
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return ((int)len);
}

char	*ft_ulltoa(unsigned long long n)
{
	unsigned long long	n_len;
	unsigned long long	i;
	char				*result;

	n_len = ft_numlen(n);
	i = n_len - 1;
	result = malloc(n_len + 1);
	if (!result)
		return (0);
	if (n_len == 1)
		result[0] = '0';
	if (n < 0)
		result[0] = '-';
	while (n != 0)
	{
		if (n > 0)
			result[i--] = 48 + n % 10;
		else
			result[i--] = 48 + -n % 10;
		n /= 10;
	}
	result[n_len] = '\0';
	return (result);
}
