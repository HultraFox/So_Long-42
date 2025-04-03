/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:02:22 by fmontel           #+#    #+#             */
/*   Updated: 2024/10/14 06:54:29 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	tochar(char *s, int nb, int neg, int len);
static int	getlen(int n);

char	*ft_itoa(int n)
{
	int		neg;
	int		len;
	int		i;
	char	*s;

	if (n == -2147483648)
		return ("-2147483648");
	if (n == 2147483647)
		return ("2147483647");
	neg = 1;
	len = getlen(n) + 1;
	if (n == 0)
		len++;
	if (n < 0)
	{
		neg = -1;
		len++;
	}
	n *= neg;
	i = n;
	s = malloc(len * sizeof(char));
	if (!s)
		return (NULL);
	tochar(s, n, neg, len);
	return (s);
}

static void	tochar(char *s, int nb, int neg, int len)
{
	int		i;

	i = 0;
	if (neg == -1)
		s[0] = '-';
	if (nb == 0)
		s[0] = '0';
	while (nb > 0)
	{
		s[len - i - 2] = (nb % 10) + 48;
		nb /= 10;
		i++;
	}
	s[len - 1] = 0;
}

static int	getlen(int n)
{
	int		len;

	len = 0;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
