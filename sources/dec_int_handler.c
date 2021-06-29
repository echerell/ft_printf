/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_int_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 18:35:32 by echerell          #+#    #+#             */
/*   Updated: 2021/06/29 16:50:35 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	put_prec_int(char *str, int save, t_prop *props)
{
	int	count;

	count = 0;
	if (save < 0 && props->prec >= 0 && save > INT_MIN)
		ft_putchar_fd('-', 1);
	if (props->prec >= 0)
		count += width_handler(props->prec - ft_strlen(str), 1);
	count += mod_putstr(str, ft_strlen(str));
	return (count);
}

int	putpart_int(char *str, int save, t_prop *props)
{
	int	count;

	count = 0;
	if (props->minus)
		count += put_prec_int(str, save, props);
	if (props->prec >= 0 && (size_t)props->prec < ft_strlen(str))
		props->prec = ft_strlen(str);
	if (props->prec >= 0)
	{
		props->width -= props->prec;
		if (save == INT_MIN)
			count += width_handler(props->width + 1, 0) - 1;
		else
			count += width_handler(props->width, 0);
	}
	else
		count += width_handler(props->width - ft_strlen(str), props->zero);
	if (!props->minus)
		count += put_prec_int(str, save, props);
	return (count);
}

int	dec_int_handler(int val, t_prop *props)
{
	char	*str;
	int		save;
	int		count;

	count = 0;
	save = val;
	if (!props->prec && !val)
	{
		count += width_handler(props->width, 0);
		return (count);
	}
	if (val < 0 && (props->prec >= 0 || props->zero))
	{
		if (props->zero && props->prec < 0)
			ft_putchar_fd('-', 1);
		val *= -1;
		props->zero = 1;
		props->width--;
		count++;
	}
	str = ft_itoa(val);
	count += putpart_int(str, save, props);
	free(str);
	return (count);
}
