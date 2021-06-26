/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:30:06 by echerell          #+#    #+#             */
/*   Updated: 2021/06/26 15:08:23 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	init_props(t_prop *props)
{
	props->minus = 0;
	props->zero = 0;
	props->width = 0;
	props->prec = 0;
	props->type = 0;
}

int	parse_prec(const char *str, int i, va_list args, t_prop *props)
{
	if (str[i+1] == '*')
	{
		props->prec = va_arg(args, int);
		return (1);
	}
	else if (ft_isdigit(str[i+1]) || str[i+1] == '-')
		return (parse_width(str, ++i, props));
	else
	{
		props->prec = 0;
		return (0);
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
	if (str[start-1] == '.')
		props->prec = ft_atoi(sub);
	else
		props->width = ft_atoi(sub);
	free(sub);
	return (--len);
}

int	check_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int	prop_handler(const char *str, va_list args, int i, t_prop *props)
{
	while(!ft_isalpha(str[i]) && str[i])
	{
		if (str[i] == '-')
			props->minus++;
		else if (str[i] == '0')
			props->zero++;
		else if (str[i] == '*')
			props->width = va_arg(args, int);
		else if (str[i] == '.')
			i += parse_prec(str, i, args, props) + 1;
		else if (ft_isdigit(str[i]))
			i += parse_width(str, i, props);
		i++;
	}
	if (check_type(str[i]))
		props->type = str[i];
	else
		props->type = 0;
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

/*int	arg_handler(const char *str, va_list args, int i, t_prop *props)
{
	int count;

	count = 0;
	if (str[i] == 'd')
		count = mod_putnbr(va_arg(args, int), props);
	return (count);
}*/

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
			write_props(props);
			//count_char += arg_handler(str, args, i, props);
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
