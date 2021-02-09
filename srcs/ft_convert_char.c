/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzhou <hzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:34:42 by hzhou             #+#    #+#             */
/*   Updated: 2021/02/08 15:02:03 by hzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_str(va_list ap, t_printf *tab)
{
	char	*str;
	char	*sp;

	if (!(str = va_arg(ap, char *)))
	{
		str = ft_strdup_l("(null)", tab);
	}
	else
		str = ft_strdup_l(str, tab);
	tab->len = ft_strlen(str);
	sp = ft_sp(tab);
	ft_join_all(str, sp, tab);
}

void	ft_convert_c(va_list ap, t_printf *tab)
{
	char	*str;
	char	*sp;

	str = NULL;
	tab->len = 1;
	tab->converter == 'c' ? str = ft_c_to_str(va_arg(ap, int)) : 0;
	tab->converter == '%' ? str = ft_strdup("%") : 0;
	sp = ft_sp(tab);
	ft_join_all(str, sp, tab);
}

void	ft_convert_p(va_list ap, t_printf *tab)
{
	char	*str;
	char	*sp;

	tab->u = va_arg(ap, unsigned long);
	str = ft_itoa_base(tab->u, "0123456789abcdef");
	tab->len = ft_strlen(str) + 2;
	if (tab->u == 0 && tab->precision && tab->precision_width == 0)
	{
		free(str);
		str = ft_strdup("");
		tab->len -= 1;
	}
	sp = ft_sp(tab);
	ft_join_all(str, sp, tab);
}
