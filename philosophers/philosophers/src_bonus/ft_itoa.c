/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:24:45 by yson              #+#    #+#             */
/*   Updated: 2022/03/22 18:19:22 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher_bonus.h"

static int	ft_numlen(int n)
{
	int	len;

	if (n > 0)
		len = 0;
	else
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static unsigned int	ft_strlen(const char *str)
{
	unsigned int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

static char	*ft_strdup(const char *src)
{
	int		size;
	int		i;
	char	*str;

	i = 0;
	size = ft_strlen((char *)src);
	str = malloc(size + 1);
	if (!str)
		return (0);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		n_len;
	int		i;
	char	*result;

	n_len = ft_numlen(n);
	i = n_len - 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
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
