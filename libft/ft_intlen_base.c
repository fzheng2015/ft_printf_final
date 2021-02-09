/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzhou <hzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:21:59 by hzhou             #+#    #+#             */
/*   Updated: 2021/02/08 15:00:46 by hzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen_base(uintmax_t n, char *base)
{
	size_t	len;
	size_t	base_len;

	len = 1;
	base_len = ft_strlen(base);
	while (n >= base_len)
	{
		n = n / base_len;
		len++;
	}
	return (len);
}
