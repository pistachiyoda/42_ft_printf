/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 20:10:44 by fmai              #+#    #+#             */
/*   Updated: 2021/03/26 20:16:50 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_n(char *s, int len)
{
	if (s == NULL)
		return ;
	while (len--)
	{
		if (*s == '\0')
			return ;
		ft_putchar(*s);
		s++;
	}
}

void	rev_str(char *str, int i)
{
	while (i > -1)
	{
		ft_putchar(str[i]);
		i--;
	}
}

void	ft_putnbr(int n)
{
	char	ret[50];
	int		i;

	if (n == 0)
		ft_putstr("0");
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	i = 0;
	while (n)
	{
		ret[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	rev_str(ret, i - 1);
}

void	ft_putunbr(unsigned int n)
{
	char			ret[50];
	unsigned int	i;

	if (n == 0)
		ft_putstr("0");
	i = 0;
	while (n)
	{
		ret[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	rev_str(ret, i - 1);
}

size_t	ft_strlen(const char *str)
{
	size_t cnt;

	if (str == NULL)
		return (1);
	cnt = 0;
	while (1)
	{
		if (*str == '\0')
			break ;
		str++;
		cnt++;
	}
	return (cnt);
}
