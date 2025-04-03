/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_adrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:44:22 by fmontel           #+#    #+#             */
/*   Updated: 2024/10/18 11:23:53 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	recursive_print(size_t nb);
static int	recursive_lprint(size_t nb, int i);

void	ft_puthex_adrs(long nb)
{
	write(1, "0x", 2);
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	recursive_print(nb);
}

static void	recursive_print(size_t nb)
{
	size_t	i;
	char	c;

	if (nb > 0)
	{
		i = nb % 16;
		if (i <= 9)
			c = i + 48;
		else
			c = i + 87;
		nb /= 16;
		recursive_print(nb);
		write(1, &c, 1);
	}
}

int	ft_putlhex_adrs(size_t nb)
{
	size_t	i;

	if (nb == 0)
		return (write(1, "(nil)", 5));
	i = 0;
	write(1, "0x", 2);
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (recursive_lprint(nb, 2 + i));
}

static int	recursive_lprint(size_t nb, int i)
{
	size_t	o;
	char	c;

	if (nb > 0)
	{
		i++;
		o = nb % 16;
		if (o <= 9)
			c = o + 48;
		else
			c = o + 87;
		nb /= 16;
		i = recursive_lprint(nb, i);
		write(1, &c, 1);
	}
	return (i);
}
