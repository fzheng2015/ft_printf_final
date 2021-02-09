/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzhou <hzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 21:27:43 by hzhou             #+#    #+#             */
/*   Updated: 2020/07/22 22:52:20 by hzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest1;
	unsigned char	*src1;

	dest1 = (unsigned char*)dest;
	src1 = (unsigned char*)src;
	if (dest1 == 0 && src1 == 0)
		return (0);
	while (n-- > 0)
	{
		*dest1++ = *src1++;
	}
	return (dest);
}
