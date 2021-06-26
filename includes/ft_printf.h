/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:31:37 by echerell          #+#    #+#             */
/*   Updated: 2021/06/26 20:52:12 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
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
int		arg_handler(const char *str, va_list args, int i, t_prop *props);
void	init_props(t_prop *props);
int		prop_handler(const char *str, va_list args, int i, t_prop *props);
int		parse_prec(const char *str, int i, va_list args, t_prop *props);
int		parse_width(const char *str, int i, t_prop *props);
int		check_type(char c);
int		dec_int_handler(va_list args, t_prop *props);
int		char_handler(char c, t_prop *props);
int		width_handler(int offset, int zero);

#endif
