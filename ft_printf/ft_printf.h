/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 00:08:19 by yson              #+#    #+#             */
/*   Updated: 2021/07/20 17:20:11 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		print_percent(void);
int		print_it(char target, va_list ap);
int		read_and_print(const char *str, va_list ap);
int		print_char(char c);
int		print_int(int n);
int		print_uint(unsigned int u);
char	*ft_ulltoa(unsigned long long n);
int		print_string(char *str);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		print_hex(unsigned int uint, int capital);
int		print_ptr(unsigned long long ptr);
#endif