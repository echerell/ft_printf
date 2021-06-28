/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_putstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:36:54 by echerell          #+#    #+#             */
/*   Updated: 2021/06/28 19:41:21 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	mod_putstr(char *str, int prec)
{
	int	count;

	count = 0;
	while (str[count] && count < prec)
	{
		ft_putchar_fd(str[count], 1);
		count++;
	}
	return (count);
}
