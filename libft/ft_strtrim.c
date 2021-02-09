/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzhou <hzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 21:27:45 by hzhou             #+#    #+#             */
/*   Updated: 2020/07/24 12:32:43 by hzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_debut(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_in_set(s1[i], set))
		i++;
	return (i);
}

static int	ft_fin(char const *s1, char const *set)
{
	int	end;

	end = ft_strlen(s1) - 1;
	while (end >= 0 && s1[end] && ft_in_set(s1[end], set))
		end--;
	return (end);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	int		start;
	int		end;
	char	*trim;

	if (s1 == 0 || set == 0)
		return (0);
	start = ft_debut(s1, set);
	end = ft_fin(s1, set);
	len = end - start + 1;
	if (len < 0)
		len = 0;
	if (!(trim = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = -1;
	while (++i < len)
		trim[i] = s1[start + i];
	trim[i] = '\0';
	return (trim);
}
