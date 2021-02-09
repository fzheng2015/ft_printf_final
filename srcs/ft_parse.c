/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzhou <hzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:33:42 by hzhou             #+#    #+#             */
/*   Updated: 2021/02/08 15:07:14 by hzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flag(char *str, va_list ap, t_printf *tab)
{
	if (str[tab->i] == '*')
	{
		if (tab->precision)
			tab->precision_width = va_arg(ap, int);
		else
			tab->width = va_arg(ap, int);
	}
	if (str[tab->i] == '0' && !tab->minus && !tab->precision)
		tab->zero = 1;
	if (str[tab->i] > '0' && str[tab->i] <= '9' && !tab->precision)
		tab->width = ft_atoi_printf(str, &tab->i);
	if (str[tab->i] > '0' && str[tab->i] <= '9' && tab->precision)
		tab->precision_width = ft_atoi_printf(str, &tab->i);
	if (str[tab->i] == '-')
	{
		tab->zero = 0;
		tab->minus = 1;
	}
	str[tab->i] == '.' ? ft_init_precision(tab) : 0;
}

int		ft_parse_flag(char *str, va_list ap, t_printf *tab)
{
	while (!ft_is_conversion(str[tab->i]))
	{
		ft_check_flag(str, ap, tab);
		if (str[tab->i + 1] == '\0')
			return (0);
		if (!ft_is_flag(str[tab->i + 1]))
		{
			tab->i++;
			return (0);
		}
		tab->i++;
	}
	return (1);
}

void	ft_parse(char *str, va_list ap, t_printf *tab)
{
	tab->i++;
	ft_reset_flags(tab);
	if (!ft_parse_flag(str, ap, tab))
		return ;
	if (tab->width < 0)
	{
		tab->minus = 1;
		tab->zero = 0;
		tab->width = -tab->width;
	}
	(tab->precision_width < 0) ? tab->precision = 0 : 0;
	if (tab->precision && tab->precision_width >= 0)
		(str[tab->i] != '%') ? tab->zero = 0 : 0;
	tab->converter = str[tab->i];
	str[tab->i] == 'c' || str[tab->i] == '%' ? ft_convert_c(ap, tab) : 0;
	str[tab->i] == 's' ? ft_convert_str(ap, tab) : 0;
	str[tab->i] == 'd' || str[tab->i] == 'i' ? ft_convert_int(ap, tab) : 0;
	str[tab->i] == 'u' ? ft_convert_uint(ap, tab) : 0;
	str[tab->i] == 'p' ? ft_convert_p(ap, tab) : 0;
	str[tab->i] == 'x' || str[tab->i] == 'X' ? ft_convert_x(ap, tab) : 0;
}

size_t	ft_is_conversion(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
			|| c == 'u' || c == 'x' || c == 'n' || c == 'X' || c == '%');
}

size_t	ft_is_flag(char c)
{
	return (ft_is_conversion(c) || (c >= '0' && c <= '9') || c == '-'
			|| c == '.' || c == '*');
}
