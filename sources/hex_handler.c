/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:25:00 by echerell          #+#    #+#             */
/*   Updated: 2021/06/29 21:06:14 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	hex_handler(unsigned int val, int capitals, t_prop *props)
{
	char	*str;
	int		count;
	int		i;

	count = 0;
	i = 0;
	val += UINT_MAX + 1;
	if (!props->prec && !val)
	{
		count += width_handler(props->width, 0);
		return (count);
	}
	str = atoi_base((unsigned long) val, 16);
	if (capitals)
	{
		while (str[i])
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	}
	count += putpart_uint(str, props);
	free(str);
	return (count);
}
