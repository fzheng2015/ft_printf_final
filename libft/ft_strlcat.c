/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzhou <hzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 21:27:44 by hzhou             #+#    #+#             */
/*   Updated: 2020/07/23 18:32:44 by hzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	dest_strlen;
	size_t	src_strlen;

	dest_strlen = ft_strlen(dest);
	src_strlen = ft_strlen(src);
	if (size < dest_strlen)
		return (src_strlen + size);
	i = 0;
	while (src[i] && (dest_strlen + i + 1 < size) && size != 0)
	{
		dest[dest_strlen + i] = src[i];
		i++;
	}
	dest[dest_strlen + i] = '\0';
	return (dest_strlen + src_strlen);
}
