/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzhou <hzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 21:27:43 by hzhou             #+#    #+#             */
/*   Updated: 2020/07/22 11:22:28 by hzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_recu(long int nb, int fd)
{
	int		n;
	char	str;

	n = nb % 10;
	if (nb > 9)
		ft_putnbr_recu(nb / 10, fd);
	str = n + '0';
	write(fd, &str, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	int			sign;

	sign = 1;
	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		sign = -1;
	}
	nb *= sign;
	ft_putnbr_recu(nb, fd);
}
