/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_common.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 20:10:06 by fmai              #+#    #+#             */
/*   Updated: 2021/03/26 20:10:21 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		output_spaces(int num)
{
	if (num <= 0)
		return (0);
	while (num--)
		ft_putchar(' ');
	return (num);
}

int		output_zeros(int num)
{
	if (num <= 0)
		return (0);
	while (num--)
		ft_putchar('0');
	return (num);
}

int		proc_empty(t_format format)
{
	if (format.field >= 0)
	{
		output_spaces(format.field);
		return (format.field);
	}
	return (0);
}

int		max(int a, int b)
{
	return (a > b ? a : b);
}
