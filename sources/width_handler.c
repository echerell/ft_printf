/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 20:38:37 by echerell          #+#    #+#             */
/*   Updated: 2021/06/26 20:56:05 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	width_handler(int offset, int zero)
{
	int	count;

	if (offset < 0)
		return (0);
	count = 0;
	while (offset)
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
