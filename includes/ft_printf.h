/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:31:37 by echerell          #+#    #+#             */
/*   Updated: 2021/06/29 20:55:15 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_prop
{
	int	minus;
	int	zero;
	int	width;
	int	prec;
	int	type;
}t_prop;

int		ft_printf(const char *format, ...);
int		parser(const char *str, va_list args, t_prop *props);
void	init_props(t_prop *props);
int		prop_handler(const char *str, va_list args, int i, t_prop *props);
int		arg_handler(const char *str, va_list args, int i, t_prop *props);

void	parse_star(int val, t_prop *props);
int		parse_prec(const char *str, int i, va_list args, t_prop *props);
int		parse_width(const char *str, int i, t_prop *props);
int		check_type(char c);

int		width_handler(int offset, int zero);
int		mod_putstr(char *str, int prec);

int		char_handler(char c, t_prop *props);

int		str_handler(char *str, t_prop *props);

int		ptr_handler(unsigned long val, t_prop *props);
char	*atoi_base(unsigned long val, int base);

int		dec_int_handler(int val, t_prop *props);

int		uint_handler(unsigned int val, t_prop *props);
char	*u_itoa(unsigned int n);
int		putpart_uint(char *str, t_prop *props);
int		put_prec_uint(char *str, t_prop *props);

int		hex_handler(unsigned int val, int capital, t_prop *props);

int		per_handler(t_prop *props);

#endif
