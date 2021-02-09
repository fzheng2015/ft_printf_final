/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzhou <hzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 21:27:42 by hzhou             #+#    #+#             */
/*   Updated: 2020/07/23 19:49:21 by hzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(int i, const char *str)
{
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\r'
			|| str[i] == '\n' || str[i] == '\f' || str[i] == '\t')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	long int	result;
	int			i;
	int			sign;

	sign = 1;
	i = 0;
	result = 0;
	i = ft_check(i, str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = 10 * result + (str[i] - '0');
		if (result * sign > 2147483647)
			return (-1);
		if (result * sign < -2147483648)
			return (0);
		i++;
	}
	return (result * sign);
}
