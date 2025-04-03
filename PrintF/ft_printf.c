/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:44:12 by fmontel           #+#    #+#             */
/*   Updated: 2024/10/21 12:44:14 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static int	converter(const char *str, va_list varg, char *conv);
static int	conv_arg(va_list varg, int conv);
static int	print_or_null(char *s);
static int	print_undef(char c, size_t len[1]);

int	ft_printf(const char *str, ...)
{
	va_list	varg;

	if (!str)
		return (-1);
	va_start(varg, str);
	return (converter(str, varg, "cspdiuxX\%"));
}

static int	converter(const char *str, va_list varg, char *conv)
{
	int		i;
	size_t	len[1];

	i = 0;
	len[0] = 0;
	while ((size_t)i != ft_strlen(str))
	{
		if (str[i] != '%')
			write(1, &str[i], 1);
		else if (str[i] == '%' && str[i + 1] != 0
			&& (ft_charchk(str[i +1], conv) + 1) >= 0)
		{
			len[0] += conv_arg(varg, ft_charchk(str[i +1], conv)) - 2;
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == 0)
			return (-1);
		else if (str[i] == '%' && str[i + 1] != 0
			&& (ft_charchk(str[i +1], conv) + 1) < 0)
			i += print_undef(str[i + 1], len);
		if (i < 0)
			return (-1);
		i++;
	}
	return (i + len[0]);
}

static int	conv_arg(va_list varg, int conv)
{
	char	c;

	if (conv == 0)
	{
		c = (char) va_arg(varg, int);
		return (write(1, &c, 1));
	}
	else if (conv == 1)
		return (print_or_null(va_arg(varg, char *)));
	else if (conv == 2)
		return (ft_putlhex_adrs(va_arg(varg, size_t)));
	else if (conv <= 4)
		return (ft_putlnbr((int) va_arg(varg, int)));
	else if (conv == 5)
		return (ft_u_putlnbr((int) va_arg(varg, int)));
	else if (conv == 6)
		return (ft_putlhex((unsigned int) va_arg(varg, int), 0));
	else if (conv == 7)
		return (ft_putlhex((unsigned int) va_arg(varg, int), 1));
	else if (conv == 8)
		return (write(1, "%", 1));
	(void) c;
	return (0);
}

static int	print_or_null(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (ft_putlstr(s));
}

static int	print_undef(const char c, size_t len[1])
{
	if (ft_charchk(c, " 0#-+'ISC") >= 0)
		return (-2147483647);
	if (ft_charchk(c, "qthjlzLZ") >= 0)
	{
		len[0]--;
		return (write(1, "%", 1));
	}
	if (ft_charchk(c, "n") >= 0)
	{
		len[0] -= 2;
		return (1);
	}
	write(1, "%", 1);
	write(1, &c, 1);
	return (1);
}
