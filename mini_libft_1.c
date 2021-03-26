/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 20:11:11 by fmai              #+#    #+#             */
/*   Updated: 2021/03/26 20:11:36 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_atoi(const char *str)
{
	int				sign;
	unsigned int	n;

	sign = *str == '-' ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	n = 0;
	while (ft_isdigit(*str))
	{
		if (sign == 1 && ((unsigned int)10 * n + (*str - '0')) > 2147483647)
			return (-1);
		if (sign == -1 && ((unsigned int)10 * n + (*str - '0')) > 2147483648)
			return (0);
		n = 10 * n + (*str - '0');
		str++;
	}
	return (sign * n);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	char *str;

	str = (char *)s;
	while (1)
	{
		if (*str == (char)c)
			return (str);
		if (*str == 0)
			return (NULL);
		str++;
	}
}

void	ft_putstr(char *s)
{
	if (s == NULL)
		return ;
	while (1)
	{
		if (*s == '\0')
			return ;
		ft_putchar(*s);
		s++;
	}
}
