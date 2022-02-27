#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flag
{
	int		wildcard;
	int		minus;
	int		zero;
	int		width;
	int		precision;
	char	type;
}				t_flag;
int		ft_printf(const char *str, ...);
void	init_flag(t_flag *flag);
int		check_flag(int start, const char *str, va_list ap, t_flag *flag);
int		print_it(char target, va_list ap, t_flag flag);
int		read_and_print(const char *str, va_list *ap);
int		print_char(char c, t_flag flag);
void	flag_width(char c, t_flag *flag);
void	flag_minus(t_flag *flag);
void	flag_dot(va_list ap, const char *str, int index, t_flag *flag);
void	flag_wc(va_list ap, t_flag *flag);
int		apply_flag_width(int width, int minus, int zero);
int		is_format(char c);
int		is_flag(char c);
#endif