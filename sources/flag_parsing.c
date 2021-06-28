/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 18:24:38 by echerell          #+#    #+#             */
/*   Updated: 2021/06/28 19:16:08 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	parse_star(int val, t_prop *props)
{
	if (val < 0)
	{
		props->minus = 1;
		props->zero = 0;
		props->width = (-1) * val;
	}
	else
		props->width = val;
}

int	parse_prec(const char *str, int i, va_list args, t_prop *props)
{
	if (str[i + 1] == '*')
	{
		props->prec = va_arg(args, int);
		if (props->prec < 0)
			props->prec *= -1;
		return (0);
	}
	else if (ft_isdigit(str[i + 1]))
		return (parse_width(str, ++i, props));
	else
	{
		props->prec = 0;
		return (-1);
	}
}

int	parse_width(const char *str, int i, t_prop *props)
{
	unsigned int	start;
	size_t			len;
	char			*sub;

	start = i;
	len = 0;
	while (ft_isdigit(str[i]))
	{
		len++;
		i++;
	}
	sub = ft_substr(str, start, len);
	if (str[start - 1] == '.')
		props->prec = ft_atoi(sub);
	else
		props->width = ft_atoi(sub);
	free(sub);
	return (--len);
}

int	check_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}
