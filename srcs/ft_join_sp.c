/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_sp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzhou <hzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:21:28 by hzhou             #+#    #+#             */
/*   Updated: 2021/02/08 14:59:10 by hzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_add_minus(t_printf *tab)
{
	if (tab->n < 0)
	{
		tab->len--;
		ft_add_to_buffer(tab, "-", 1);
	}
}

void	ft_join_all(char *str, char *sp, t_printf *tab)
{
	(tab->is_int && tab->zero) ? ft_add_minus(tab) : 0;
	if (sp && !tab->minus)
		ft_add_to_buffer(tab, sp, tab->sp_len);
	(tab->is_int && !tab->zero) ? ft_add_minus(tab) : 0;
	if (tab->converter == 'p')
	{
		ft_add_to_buffer(tab, "0x", 2);
		tab->len -= 2;
	}
	ft_add_to_buffer(tab, str, tab->len);
	if (sp && tab->minus)
		ft_add_to_buffer(tab, sp, tab->sp_len);
	free(str);
	free(sp);
}

char	*ft_sp(t_printf *tab)
{
	char	*str;
	int		i;

	i = 0;
	if (tab->width < tab->len)
		return (NULL);
	if (!(str = ft_calloc((tab->width + 1), sizeof(char))))
		return (NULL);
	while (i < tab->width - tab->len)
	{
		if (tab->zero)
			str[i] = '0';
		else
			str[i] = ' ';
		i++;
	}
	tab->sp_len = i;
	str[i] = '\0';
	return (str);
}

char	*ft_str_with_precision(char *str, t_printf *tab)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!tab->precision)
		return (str);
	if (tab->precision_width < tab->len)
		return (str);
	if (!(tmp = ft_calloc(tab->precision_width + 1, sizeof(char))))
		return (NULL);
	while (i < tab->precision_width - tab->len)
	{
		tmp[i] = '0';
		i++;
	}
	while (str[j])
	{
		tmp[i + j] = str[j];
		j++;
	}
	tmp[i + j] = '\0';
	free(str);
	return (tmp);
}
