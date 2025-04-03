/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:44:22 by fmontel           #+#    #+#             */
/*   Updated: 2024/10/18 11:24:06 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void			recursive_print(unsigned int nb, int uppc);
static unsigned int	recursive_lprint(unsigned int nb, int i, int uppc);

void	ft_puthex(unsigned int nb, int uppc)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	recursive_print(nb, uppc);
}

static void	recursive_print(unsigned int nb, int uppc)
{
	int		i;
	char	c;

	if (nb > 0)
	{
		i = nb % 16;
		if (i <= 9)
			c = i + 48;
		else
			c = i + 87 - (32 * uppc);
		nb /= 16;
		recursive_print(nb, uppc);
		write(1, &c, 1);
	}
}

unsigned int	ft_putlhex(unsigned int nb, int uppc)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (recursive_lprint(nb, 0, uppc));
}

static unsigned int	recursive_lprint(unsigned int nb, int i, int uppc)
{
	int		o;
	char	c;

	if (nb > 0)
	{
		i++;
		o = nb % 16;
		if (o <= 9)
			c = o + 48;
		else
			c = o + 87 - (32 * uppc);
		nb /= 16;
		i = recursive_lprint(nb, i, uppc);
		write(1, &c, 1);
	}
	return (i);
}
