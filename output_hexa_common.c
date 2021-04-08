/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_hexa_common.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 20:09:43 by fmai              #+#    #+#             */
/*   Updated: 2021/04/08 21:03:18 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		calc_hex_digit(unsigned long decimal)
{
	int hex_digit;

	if (decimal == 0)
		return (1);
	hex_digit = 0;
	while (decimal > 0)
	{
		decimal /= 16;
		hex_digit++;
	}
	return (hex_digit);
}

int		set_hex_str(unsigned long decimal, char *hex_num, char *hex)
{
	int		tmp;
	int		i;

	i = 0;
	while (decimal >= 0)
	{
		tmp = decimal % 16;
		decimal /= 16;
		hex[i++] = hex_num[tmp];
		if (decimal == 0)
			break ;
	}
	return (i);
}
