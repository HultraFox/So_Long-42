/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:44:22 by fmontel           #+#    #+#             */
/*   Updated: 2024/10/14 09:04:25 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	recursive_print(int nb, int fd);

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nb == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	recursive_print(nb, fd);
}

void	recursive_print(int nb, int fd)
{
	int		i;
	char	c;

	if (nb > 0)
	{
		i = nb % 10;
		nb /= 10;
		c = i + 48;
		recursive_print(nb, fd);
		write(fd, &c, 1);
	}
}
