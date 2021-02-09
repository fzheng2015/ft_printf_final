/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzhou <hzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 21:27:42 by hzhou             #+#    #+#             */
/*   Updated: 2020/06/30 18:15:28 by hzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen_itoa(long int tmp, int sign)
{
	int	len;

	if (tmp == 0)
		return (1);
	len = 0;
	while (tmp != 0)
	{
		tmp /= 10;
		len++;
	}
	if (sign < 0)
		len++;
	return (len);
}

static char	*ft_inttostr(char *str, long int tmp, int len, int sign)
{
	str[len] = '\0';
	if (tmp == 0)
		str[0] = '0';
	while (tmp != 0)
	{
		str[--len] = tmp % 10 + '0';
		tmp /= 10;
	}
	if (sign < 0)
		str[0] = '-';
	return (str);
}

char		*ft_itoa(int n)
{
	char		*str;
	long int	tmp;
	int			len;
	int			sign;

	sign = 1;
	if (n < 0)
		sign = -sign;
	tmp = n;
	tmp *= sign;
	len = ft_intlen_itoa(tmp, sign);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str = ft_inttostr(str, tmp, len, sign);
	return (str);
}
