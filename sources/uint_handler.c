/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:38:45 by echerell          #+#    #+#             */
/*   Updated: 2021/06/29 21:06:39 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	put_prec_uint(char *str, t_prop *props)
{
	int	count;

	count = 0;
	if (props->prec >= 0)
		count += width_handler(props->prec - ft_strlen(str), 1);
	count += mod_putstr(str, ft_strlen(str));
	return (count);
}

int	putpart_uint(char *str, t_prop *props)
{
	int	count;

	count = 0;
	if (props->minus)
		count += put_prec_uint(str, props);
	if (props->prec >= 0 && (size_t)props->prec < ft_strlen(str))
		props->prec = ft_strlen(str);
	if (props->prec >= 0)
	{
		props->width -= props->prec;
		count += width_handler(props->width, 0);
	}
	else
		count += width_handler(props->width - ft_strlen(str), props->zero);
	if (!props->minus)
		count += put_prec_uint(str, props);
	return (count);
}

int	uint_handler(unsigned int val, t_prop *props)
{
	char	*str;
	int		count;

	count = 0;
	val += UINT_MAX + 1;
	if (!props->prec && !val)
	{
		count += width_handler(props->width, 0);
		return (count);
	}
	str = u_itoa(val);
	count += putpart_uint(str, props);
	free(str);
	return (count);
}
