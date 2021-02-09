/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzhou <hzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:22:22 by hzhou             #+#    #+#             */
/*   Updated: 2021/02/08 14:17:50 by hzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(uintmax_t n, char *base)
{
	char	*str;
	int		num_len;
	int		base_len;

	base_len = ft_strlen(base);
	num_len = ft_intlen_base(n, base);
	if (!(str = ft_calloc(num_len + 1, sizeof(char))))
		return (NULL);
	str[num_len] = '\0';
	while (num_len)
	{
		str[--num_len] = base[n % base_len];
		n = n / base_len;
	}
	return (str);
}
