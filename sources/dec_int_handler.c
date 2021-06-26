/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_int_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 18:35:32 by echerell          #+#    #+#             */
/*   Updated: 2021/06/26 20:03:13 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int put_space_width(int i, t_prop *props)
{
	int	count;

	count = 0;
	while (props->width > i)
	{
		ft_putchar_fd(' ', 1);
		props->width--;
		count++;
	}
	return (count);
}

int	put_zero_prec(int i, t_prop *props)
{
	int	count;

	count = 0;
	while (props->prec > i)
	{
		ft_putchar_fd('0', 1);
		props->prec--;
		count++;
	}
	return (count);
}

int	dec_int_handler(va_list args, t_prop *props)
{
	int	count;
	int	number;
	int	save;
	int	i;

	count = 0;
	number = va_arg(args, int);
	save = number;
	while(number >= 10)
	{
		number /= 10;
		count++;
	}
	count++;
	i = count;
	if (props->prec > i)
	{
		if (props->width > props->prec)
		{
			if (props->minus)
			{
				count += put_zero_prec(i, props);
				ft_putnbr_fd(save, 1);
				count += put_space_width(i, props);
			}
			else
			{
				count += put_space_width(i, props);
				count += put_zero_prec(i, props);
				ft_putnbr_fd(save, 1);
			}
		}
		else
		{
			count += put_zero_prec(i, props);
			ft_putnbr_fd(save, 1);
		}
	}
	else
		ft_putnbr_fd(save, 1);
	return (count);
}
