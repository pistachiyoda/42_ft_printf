#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
int ft_printf(const char *fmt, ...);
typedef struct s_format
{
	int flag_minus;
	int	flag_zero;
	int field;
	int	precision;
	char type;
}				t_format;

int	ft_isdigit(int c);
int	ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
void ft_proc_percent(char **fmt);
void ft_putchar(char c);
#endif