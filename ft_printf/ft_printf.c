/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:21:33 by yson              #+#    #+#             */
/*   Updated: 2021/07/20 00:49:11 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	print_it(char target, va_list ap)
{
	int	count;

	count = 0;
	if (target == 'c')
		count += print_char(va_arg(ap, int));
	else if (target == 's')
		count += print_string(va_arg(ap, char *));
	else if (target == 'p')
		count += print_ptr(va_arg(ap, unsigned long long));
	else if (target == 'd')
		count += print_int(va_arg(ap, int));
	else if (target == 'i')
		count += print_int(va_arg(ap, int));
	else if (target == 'u')
		count += print_uint(va_arg(ap, unsigned int));
	else if (target == 'x')
		count += print_hex(va_arg(ap, unsigned int), 0);
	else if (target == 'X')
		count += print_hex(va_arg(ap, unsigned int), 1);
	else if (target == '%')
		count += print_percent();
	return (count);
}

int	read_and_print(const char *str, va_list ap)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			if (ft_strchr("cspdiuxX%%", str[i]))
				count += print_it(str[i], ap);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}
