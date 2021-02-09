/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzhou <hzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:34:55 by hzhou             #+#    #+#             */
/*   Updated: 2021/02/08 14:36:46 by hzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_int(va_list ap, t_printf *tab)
{
	char	*str;
	char	*sp;

	tab->is_int = 1;
	tab->n = (intmax_t)va_arg(ap, int);
	str = ft_itoa_printf(tab->n);
	tab->len = ft_intlen(tab->n);
	str = ft_str_with_precision(str, tab);
	tab->len = ft_strlen(str);
	(tab->n < 0) ? tab->len++ : 0;
	if (tab->n == 0 && tab->precision && tab->precision_width == 0
		&& !tab->width)
	{
		free(str);
		return ;
	}
	if (tab->n == 0 && tab->precision && tab->precision_width == 0)
	{
		free(str);
		str = ft_strdup(" ");
	}
	sp = ft_sp(tab);
	ft_join_all(str, sp, tab);
}

void	ft_convert_uint(va_list ap, t_printf *tab)
{
	char	*str;
	char	*sp;

	tab->is_int = 1;
	tab->u = (uintmax_t)va_arg(ap, unsigned int);
	str = ft_uitoa(tab->u);
	tab->len = ft_strlen(str);
	str = ft_str_with_precision(str, tab);
	tab->len = ft_strlen(str);
	if (tab->u == 0 && tab->precision && tab->precision_width == 0
		&& !tab->width)
	{
		free(str);
		return ;
	}
	if (tab->u == 0 && tab->precision && tab->precision_width == 0)
	{
		free(str);
		str = ft_strdup(" ");
	}
	sp = ft_sp(tab);
	ft_join_all(str, sp, tab);
}

void	ft_convert_x(va_list ap, t_printf *tab)
{
	char	*str;
	char	*sp;

	str = NULL;
	tab->is_int = 1;
	tab->u = (uintmax_t)va_arg(ap, unsigned int);
	tab->converter == 'x' ? str = ft_itoa_base(tab->u, "0123456789abcdef") : 0;
	tab->converter == 'X' ? str = ft_itoa_base(tab->u, "0123456789ABCDEF") : 0;
	tab->len = ft_strlen(str);
	str = ft_str_with_precision(str, tab);
	tab->len = ft_strlen(str);
	if (tab->u == 0 && tab->precision && tab->precision_width == 0
		&& !tab->width)
	{
		free(str);
		return ;
	}
	if (tab->u == 0 && tab->precision && tab->precision_width == 0)
	{
		free(str);
		str = ft_strdup(" ");
	}
	sp = ft_sp(tab);
	ft_join_all(str, sp, tab);
}
