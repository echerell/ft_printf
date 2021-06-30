/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:30:06 by echerell          #+#    #+#             */
/*   Updated: 2021/06/30 15:20:56 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	init_props(t_prop *props)
{
	props->minus = 0;
	props->zero = 0;
	props->width = 0;
	props->prec = -1;
	props->type = 0;
}

int	prop_handler(const char *str, va_list args, int i, t_prop *props)
{
	while (!ft_isalpha(str[i]) && str[i] && str[i] != '%')
	{
		if (str[i] == '-')
		{
			props->minus = 1;
			props->zero = 0;
		}
		else if (str[i] == '0')
			props->zero = 1;
		else if (str[i] == '*')
			parse_star(va_arg(args, int), props);
		else if (str[i] == '.')
			i += parse_prec(str, i, args, props) + 1;
		else if (ft_isdigit(str[i]))
			i += parse_width(str, i, props);
		i++;
	}
	props->type = str[i];
	return (i);
}

void	write_props(t_prop *props)
{
	printf("\n############################################\n");
	printf("minus = %d\n", props->minus);
	printf("zero = %d\n", props->zero);
	printf("width = %d\n", props->width);
	printf("precision = %d\n", props->prec);
	printf("type = %c\n", props->type);
}

int	arg_handler(const char *str, va_list args, int i, t_prop *props)
{
	int	count;

	count = 0;
	if (str[i] == 'c')
		count = char_handler(va_arg(args, int), props);
	else if (str[i] == 's')
		count = str_handler(va_arg(args, char *), props);
	else if (str[i] == 'p')
		count = ptr_handler(va_arg(args, unsigned long), props);
	else if (str[i] == 'd' || str[i] == 'i')
		count = dec_int_handler(va_arg(args, int), props);
	else if (str[i] == 'u')
		count = uint_handler(va_arg(args, unsigned int), props);
	else if (str[i] == 'x')
		count = hex_handler(va_arg(args, unsigned int), 0, props);
	else if (str[i] == 'X')
		count = hex_handler(va_arg(args, unsigned int), 1, props);
	else if (str[i] == '%')
		count += mod_putstr("%", 1);
	else
	{
		ft_putchar_fd(str[i], 1);
		return (1);
	}
	return (count);
}

int	parser(const char *str, va_list args, t_prop *props)
{
	int	count_char;
	int	i;

	count_char = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i = prop_handler(str, args, ++i, props);
			//write_props(props);
			count_char += arg_handler(str, args, i, props);
			init_props(props);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count_char++;
			i++;
		}
	}
	return (count_char);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;
	t_prop	props;

	init_props(&props);
	va_start(args, format);
	count = parser(format, args, &props);
	va_end(args);
	return (count);
}
