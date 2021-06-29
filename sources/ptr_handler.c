/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:07:31 by echerell          #+#    #+#             */
/*   Updated: 2021/06/29 13:04:55 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	putpart_ptr(char *ptr, t_prop *props)
{
	int	count;

	count = 0;
	count += mod_putstr("0x", 2);
	if (props->prec >= 0)
	{
		count += width_handler(props->prec - ft_strlen(ptr), 1);
		count += mod_putstr(ptr, props->prec);
	}
	else
		count += mod_putstr(ptr, ft_strlen(ptr));
	return (count);
}

int	ptr_handler(unsigned long val, t_prop *props)
{
	char	*ptr;
	int		count;

	count = 0;
	if (val == 0 && props->prec <= 0)
	{
		count += mod_putstr("0x", 2);
		count += width_handler(props->width, 1);
		return (count);
	}
	ptr = atoi_base(val, 16);
	if ((size_t)props->prec < ft_strlen(ptr))
		props->prec = ft_strlen(ptr);
	if (props->minus)
		count += putpart_ptr(ptr, props);
	if (props->prec < 0)
		count += width_handler(props->width - ft_strlen(ptr) - 2, 0);
	else
		count += width_handler(props->width - (props->prec - ft_strlen(ptr)) -
		ft_strlen(ptr) - 2, 0);
	if (!props->minus)
		count += putpart_ptr(ptr, props);
	free(ptr);
	return (count);
}
