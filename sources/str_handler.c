/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 21:12:23 by echerell          #+#    #+#             */
/*   Updated: 2021/06/29 11:54:01 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	putpart_str(char *str, t_prop *props)
{
	int	count;

	count = 0;
	if (props->prec >= 0)
	{
		count += width_handler(props->prec - ft_strlen(str), 0);
		count += mod_putstr(str, props->prec);
	}
	else
		count += mod_putstr(str, ft_strlen(str));
	return (count);
}

int	str_handler(char *str, t_prop *props)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	if (props->prec >= 0 && (size_t)props->prec > ft_strlen(str))
		props->prec = ft_strlen(str);
	if (props->minus)
		count += putpart_str(str, props);
	if (props->prec >= 0)
		count += width_handler(props->width - props->prec, 0);
	else
		count += width_handler(props->width - ft_strlen(str), 0);
	if (!props->minus)
		count += putpart_str(str, props);
	return (count);
}
