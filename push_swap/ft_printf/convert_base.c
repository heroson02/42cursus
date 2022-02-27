/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 02:00:50 by yson              #+#    #+#             */
/*   Updated: 2021/07/20 00:05:28 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

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

static int	num_len_base(unsigned long long nbr, char *base)
{
	int					count;
	unsigned long long	base_len;

	base_len = ft_strlen(base);
	if (nbr > 0)
		count = 0;
	else
		count = 1;
	while (nbr != 0)
	{
		nbr /= base_len;
		count++;
	}
	return (count);
}

static unsigned long long	ft_atoi_base(char *str, char *base)
{
	int					i;
	int					minus;
	unsigned long long	result;
	unsigned long long	base_len;

	result = 0;
	minus = 1;
	i = 0;
	base_len = (unsigned long long)ft_strlen(base);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (is_contain(base, str[i]) != -1)
		result = result * base_len + (is_contain(base, str[i++]));
	return (result * minus);
}

static char	*ft_itoa_base(unsigned long long nbr, char *base)
{
	int		nbr_len;
	int		base_len;
	int		i;
	char	*result;

	nbr_len = num_len_base(nbr, base);
	base_len = ft_strlen(base);
	i = nbr_len - 1;
	result = malloc(nbr_len + 1);
	if (result == NULL)
		return (0);
	if (nbr_len == 1)
		result[0] = base[0];
	if (nbr < 0)
		result[0] = '-';
	while (nbr != 0)
	{
		if (nbr > 0)
			result[i--] = base[nbr % (unsigned long long)base_len];
		else
			result[i--] = base[-nbr % (unsigned long long)base_len];
		nbr /= (unsigned long long)base_len;
	}
	result[nbr_len] = '\0';
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	unsigned long long	nbr_ull;

	nbr_ull = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(nbr_ull, base_to));
}
