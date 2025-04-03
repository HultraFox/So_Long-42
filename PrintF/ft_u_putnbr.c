/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:44:22 by fmontel           #+#    #+#             */
/*   Updated: 2024/10/18 11:25:45 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	recursive_print(unsigned int nb);
static int	recursive_lprint(unsigned int nb, int i);

void	ft_u_putnbr(unsigned int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	recursive_print(nb);
}

static void	recursive_print(unsigned int nb)
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

int	ft_u_putlnbr(unsigned int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (recursive_lprint(nb, 0));
}

static int	recursive_lprint(unsigned int nb, int i)
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
