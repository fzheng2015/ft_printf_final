/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzhou <hzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 21:27:43 by hzhou             #+#    #+#             */
/*   Updated: 2020/06/16 18:13:10 by hzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cp_dest;
	unsigned char	*cp_src;
	size_t			i;

	cp_dest = (unsigned char*)dest;
	cp_src = (unsigned char*)src;
	if (dest == src)
		return (dest);
	if (cp_dest > cp_src)
	{
		while (n-- > 0)
		{
			cp_dest[n] = cp_src[n];
		}
		return (dest);
	}
	i = 0;
	while (i < n)
	{
		cp_dest[i] = cp_src[i];
		i++;
	}
	return (dest);
}
