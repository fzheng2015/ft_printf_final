/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzhou <hzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:23:13 by hzhou             #+#    #+#             */
/*   Updated: 2021/01/28 17:23:15 by hzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(uintmax_t n)
{
	char	*str;
	int		num_len;

	num_len = ft_uintlen(n);
	if (!(str = ft_calloc(num_len + 1, sizeof(char))))
		return (NULL);
	str[num_len] = '\0';
	while (num_len)
	{
		str[--num_len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
