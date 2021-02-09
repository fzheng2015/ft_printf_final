/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzhou <hzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 13:51:53 by hzhou             #+#    #+#             */
/*   Updated: 2021/01/31 02:02:47 by hzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>

# include "../libft/libft.h"
# define BUFFER_SIZE 20

typedef struct	s_printf
{
	char			buf[BUFFER_SIZE + 1];
	int				buf_count;
	int				ret;
	int				width;
	int				precision;
	int				precision_width;
	int				converter;
	int				minus;
	int				zero;
	int				len;
	int				sp_len;
	int				is_int;
	intmax_t		n;
	uintmax_t		u;
	int				i;
}				t_printf;

int				ft_printf(const char *str, ...);
void			ft_init_struct(t_printf *tab);
void			ft_print_no_specifier(t_printf *tab, char *str);
void			ft_add_to_buffer(t_printf *tab, char *str, int len);
void			ft_print_buffer(t_printf *tab);

size_t			ft_is_conversion(char c);
size_t			ft_is_flag(char c);
void			ft_parse(char *str, va_list ap, t_printf *tab);
int				ft_parse_flag(char *str, va_list ap, t_printf *tab);
void			ft_check_flag(char *str, va_list ap, t_printf *tab);

char			*ft_sp(t_printf *tab);
void			ft_join_all(char *str, char *sp, t_printf *tab);
char			*ft_str_with_precision(char *str, t_printf *tab);
void			ft_add_minus(t_printf *tab);

void			ft_reset_flags(t_printf *tab);
int				ft_atoi_printf(char *str, int *i);
void			ft_init_precision(t_printf *tab);
char			*ft_itoa_printf(intmax_t n);
char			*ft_strdup_l(char *s, t_printf *tab);

void			ft_convert_c(va_list ap, t_printf *tab);
void			ft_convert_p(va_list ap, t_printf *tab);
void			ft_convert_str(va_list ap, t_printf *tab);

void			ft_convert_int(va_list ap, t_printf *tab);
void			ft_convert_uint(va_list ap, t_printf *tab);
void			ft_convert_x(va_list ap, t_printf *tab);

#endif
