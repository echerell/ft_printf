/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 11:59:20 by echerell          #+#    #+#             */
/*   Updated: 2021/06/29 12:13:20 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	make_digit(char *str, int base, unsigned long val, int i)
{
	while (val)
	{
		if ((val % base) < 10)
			str[i - 1] = (val % base) + 48;
		else
			str[i - 1] = (val % base) + 87;
		val /= base;
		i--;
	}
}

char	*atoi_base(unsigned long val, int base)
{
	char			*str;
	int				i;
	unsigned long	save;

	save = val;
	i = 0;
	if (!val)
		return (ft_strdup("0"));
	while (val)
	{
		val /= base;
		i++;
	}
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	make_digit(str, base, save, i);
	str[i] = '\0';
	return (str);
}
