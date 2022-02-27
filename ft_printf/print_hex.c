/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 02:04:41 by yson              #+#    #+#             */
/*   Updated: 2021/07/20 00:05:17 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	print_hex(unsigned int uint, int capital)
{
	char	*result;
	int		len;
	char	*decimal;

	decimal = ft_ulltoa(uint);
	if (!capital)
		result = ft_convert_base(decimal,
				"0123456789", "0123456789abcdef");
	else
		result = ft_convert_base(decimal,
				"0123456789", "0123456789ABCDEF");
	ft_putstr_fd(result, 1);
	len = ft_strlen(result);
	free(decimal);
	free(result);
	return (len);
}
