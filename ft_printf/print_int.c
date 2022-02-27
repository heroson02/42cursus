/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 21:35:36 by yson              #+#    #+#             */
/*   Updated: 2021/07/25 12:49:28 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	print_int(int n)
{
	char	*result;
	int		len;

	result = ft_itoa(n);
	ft_putstr_fd(result, 1);
	len = ft_strlen(result);
	free(result);
	return (len);
}
