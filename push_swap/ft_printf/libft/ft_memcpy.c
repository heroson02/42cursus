/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:46:22 by yson              #+#    #+#             */
/*   Updated: 2021/07/20 00:06:08 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, unsigned int n)
{
	unsigned int	i;
	unsigned char	*result;
	unsigned char	*from;

	i = 0;
	result = (unsigned char *)dst;
	from = (unsigned char *)src;
	if (result == from)
		return (0);
	while (i < n)
	{
		result[i] = from[i];
		i++;
	}
	return (result);
}
