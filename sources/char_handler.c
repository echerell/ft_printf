/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 20:30:38 by echerell          #+#    #+#             */
/*   Updated: 2021/06/26 20:54:11 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	char_handler(char c, t_prop *props)
{
	int	count;

	count = 0;
	if (props->minus)
		ft_putchar_fd(c, 1);
	count += width_handler(props->width - 1, 0);
	if (!props->minus)
		ft_putchar_fd(c, 1);
	return (++count);
}
