/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   per_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 12:42:27 by echerell          #+#    #+#             */
/*   Updated: 2021/07/07 13:20:26 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	per_handler(t_prop *props)
{
	int	count;

	count = 0;
	if (props->minus)
		ft_putchar_fd('%', 1);
	if (props->zero)
		count += width_handler(props->width - 1, 1);
	else
		count += width_handler(props->width - 1, 0);
	if (!props->minus)
		ft_putchar_fd('%', 1);
	return (++count);
}
