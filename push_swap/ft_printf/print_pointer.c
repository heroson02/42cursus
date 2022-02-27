/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 21:20:48 by yson              #+#    #+#             */
/*   Updated: 2021/07/25 12:51:11 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	print_ptr(unsigned long long ptr)
{
	char	*pointer;
	int		result;
	char	*decimal;

	result = 2;
	ft_putstr_fd("0x", 1);
	decimal = ft_ulltoa(ptr);
	pointer = ft_convert_base(decimal,
			"0123456789", "0123456789abcdef");
	ft_putstr_fd(pointer, 1);
	result += ft_strlen(pointer);
	free(decimal);
	free(pointer);
	return (result);
}
