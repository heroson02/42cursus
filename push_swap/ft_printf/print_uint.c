/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 00:04:41 by sonhero           #+#    #+#             */
/*   Updated: 2021/07/25 12:49:25 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	print_uint(unsigned int u)
{
	int		len;
	char	*result;

	result = ft_ulltoa((unsigned long long)u);
	ft_putstr_fd(result, 1);
	len = ft_strlen(result);
	free(result);
	return (len);
}
