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
	int	dot_only;
	int	precision;
	char type;
}				t_format;

int	ft_isdigit(int c);
int	ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
int ft_proc_percent(char **fmt, va_list ap);
void ft_putchar(char c);
int	ft_isalpha(int c);
char	*ft_strchr(const char *s, int c);
int	ft_output(t_format format, va_list ap);
int	ft_output_char(t_format format, va_list ap);
int	output_spaces(int num);
void	ft_putstr(char *s);
void		ft_putnbr(int n);
void proc_flags(char **fmt, t_format *format);
void proc_field(char **fmt, t_format *format, va_list ap);
void proc_precision(char **fmt, t_format *format, va_list ap);
int output_zeros(int num);
int	output_string(t_format format, va_list ap);
size_t	ft_strlen(const char *str);
void	ft_putstr_n(char *s, int len);
int output_integer(t_format format, va_list ap);
int output_hexadecimal(t_format format, va_list ap);
int	print_hex(t_format format, unsigned int decimal, int hex_digit, char *hex_num);
int print_pointer_hex(t_format format, unsigned long long decimal, int digit, char *hex_num);
int output_pointer(t_format format, va_list ap);
int proc_total_digit(t_format format, int hex_digit);
int proc_zero_digit(t_format format, int total_digit, int hex_digit);
int	proc_empty(t_format format);
int calc_hex_digit(unsigned long long decimal);
int set_hex_str(unsigned long long decimal, char *hex_num, char *hex);
int max(int a, int b);
#endif