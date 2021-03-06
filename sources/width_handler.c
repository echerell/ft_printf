/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 20:38:37 by echerell          #+#    #+#             */
/*   Updated: 2021/06/28 19:47:55 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	width_handler(int offset, int zero)
{
	int	count;

	count = 0;
	while (offset > 0)
	{
		if (zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		offset--;
		count++;
	}
	return (count);
}
