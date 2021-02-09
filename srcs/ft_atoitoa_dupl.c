/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoitoa_dupl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzhou <hzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:34:12 by hzhou             #+#    #+#             */
/*   Updated: 2021/01/31 01:55:01 by hzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi_printf(char *str, int *i)
{
	int	atoi;

	atoi = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		atoi = 10 * atoi + str[*i] - '0';
		(*i)++;
	}
	(*i)--;
	return (atoi);
}

char	*ft_itoa_printf(intmax_t n)
{
	char	*str;
	int		num_len;

	num_len = ft_intlen(n);
	if (!(str = ft_calloc(num_len + 1, sizeof(char))))
		return (NULL);
	str[num_len] = '\0';
	while (num_len)
	{
		if (n < 0)
		{
			str[--num_len] = -(n % 10) + '0';
			n = n / 10;
			n = -n;
		}
		else
		{
			str[--num_len] = n % 10 + '0';
			n = n / 10;
		}
	}
	return (str);
}

char	*ft_strdup_l(char *s, t_printf *tab)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	if (tab->precision && tab->precision_width < len)
		len = tab->precision_width;
	if (!(str = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_init_precision(t_printf *tab)
{
	tab->precision = 1;
	tab->precision_width = 0;
}

void	ft_reset_flags(t_printf *tab)
{
	tab->width = 0;
	tab->precision = 0;
	tab->precision_width = 0;
	tab->converter = 0;
	tab->minus = 0;
	tab->zero = 0;
	tab->len = 0;
	tab->sp_len = 0;
	tab->is_int = 0;
	tab->n = 0;
	tab->u = 0;
}
