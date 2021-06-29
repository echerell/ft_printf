/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   per_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:49:00 by echerell          #+#    #+#             */
/*   Updated: 2021/06/29 21:07:36 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	per_handler(t_prop *props)
{
	int	count;

	count = 0;
	if (props->minus)
		count += mod_putstr("%", 1);
	count += width_handler(props->width - 1, props->zero);
	if (!props->minus)
		count += mod_putstr("%", 1);
	return (count);
}
