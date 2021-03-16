#include "ft_printf.h"

int output_spaces(int num)
{
	if (num <= 0)
		return (0);
	while (num--)
		ft_putchar(' ');
	return (num);
}

int output_zeros(int num)
{
	if (num <= 0)
		return (0);
	while (num--)
		ft_putchar('0');
	return (num);
}