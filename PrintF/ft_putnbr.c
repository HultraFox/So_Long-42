/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:44:22 by fmontel           #+#    #+#             */
/*   Updated: 2024/10/18 11:25:00 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	recursive_print(int nb);
static int	recursive_lprint(int nb, int i);

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	recursive_print(nb);
}

static void	recursive_print(int nb)
{
	char	c;

	if (nb > 0)
	{
		c = nb % 10 + 48;
		nb /= 10;
		recursive_print(nb);
		write(1, &c, 1);
	}
}

int	ft_putlnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
		i = 1;
	}
	return (recursive_lprint(nb, i));
}

static int	recursive_lprint(int nb, int i)
{
	char	c;

	if (nb > 0)
	{
		i++;
		c = nb % 10 + 48;
		nb /= 10;
		i = recursive_lprint(nb, i);
		write(1, &c, 1);
	}
	return (i);
}
