/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_itoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:32:46 by echerell          #+#    #+#             */
/*   Updated: 2021/06/29 21:07:52 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int	ft_count_nbr(long tmp, size_t i)
{
	while (tmp >= 1)
	{
		i++;
		tmp /= 10;
	}
	return (i);
}

static	void	ft_make_str(char *str, long tmp, size_t i)
{
	while (i)
	{
		str[i--] = tmp % 10 + '0';
		tmp /= 10;
	}
	str[i] = tmp % 10 +'0';
}

char	*u_itoa(unsigned int n)
{
	char	*str;
	size_t	i;

	i = 0;
	i = ft_count_nbr((long)n, i);
	if (n == 0)
		i++;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	ft_make_str(str, (long)n, i);
	return (str);
}
