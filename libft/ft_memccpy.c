/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzhou <hzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 21:27:43 by hzhou             #+#    #+#             */
/*   Updated: 2020/07/22 16:26:17 by hzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dest_cp;
	unsigned char	*src_cp;
	size_t			i;

	i = 0;
	dest_cp = (unsigned char*)dest;
	src_cp = (unsigned char*)src;
	while (i < n)
	{
		dest_cp[i] = src_cp[i];
		if (src_cp[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (0);
}
