/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzhou <hzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 21:27:43 by hzhou             #+#    #+#             */
/*   Updated: 2020/07/22 15:39:00 by hzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_columnlen(char const *s, char c, int i)
{
	int	columnlen;

	columnlen = 0;
	while (s[i] && s[i] != c)
	{
		columnlen++;
		i++;
	}
	return (columnlen);
}

static int	ft_rowlen(char const *s, char c)
{
	int	nb_s;
	int	i;

	nb_s = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			nb_s++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (nb_s);
}

static char	**ft_free(char **tab, int nb_row)
{
	while (--nb_row > 0)
	{
		free(tab[nb_row]);
		tab[nb_row] = NULL;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}

static char	**ft_enter(char **tab, char const *s, char c, int nb_row)
{
	int	i;
	int	j;
	int	k;
	int	nb_column;

	i = 0;
	j = -1;
	while (++j < nb_row)
	{
		while (s[i] == c)
			i++;
		nb_column = ft_columnlen(s, c, i);
		if (!(tab[j] = (char*)malloc(sizeof(char) * (nb_column + 1))))
			return (ft_free(tab, nb_row));
		k = -1;
		while (s[i] && s[i] != c)
		{
			tab[j][++k] = s[i];
			i++;
		}
		tab[j][++k] = '\0';
	}
	return (tab);
}

char		**ft_split(char const *s, char c)
{
	int		nb_row;
	char	**tab;

	if (s == 0)
		return (NULL);
	nb_row = ft_rowlen(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (nb_row + 1))))
		return (NULL);
	tab = ft_enter(tab, s, c, nb_row);
	tab[nb_row] = 0;
	return (tab);
}
