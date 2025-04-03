/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:20:15 by fmontel           #+#    #+#             */
/*   Updated: 2024/10/14 09:30:46 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

static int	count_words(char const *src, char sep);
static char	**cut_words(char **dest, char const *s, char c);
static int	check_c(char *src, char sep);

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		nbw;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	nbw = count_words(s, c);
	if (!&check_c)
		nbw = 1;
	dest = malloc((nbw + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	dest = cut_words(dest, s, c);
	return (dest);
}

static int	count_words(char const *src, char sep)
{
	int		is_c;
	int		nbw;

	is_c = 0;
	nbw = 0;
	while (*src)
	{
		if (*src != sep && is_c == 0)
		{
			is_c = 1;
			nbw++;
		}
		else if (*src == sep)
			is_c = 0;
		src++;
	}
	return (nbw);
}

static char	**cut_words(char **dest, char const *s, char c)
{
	size_t	o;
	size_t	end;
	int		start;

	o = 0;
	end = 0;
	start = -1;
	while (end <= ft_strlen(s))
	{
		if (s[end] != c && start < 0)
			start = end;
		else if ((s[end] == c || end == ft_strlen(s)) && start >= 0)
		{
			dest[o] = ft_substr(s, start, end - start);
			if (!dest[o])
				return (super_free((void **)dest));
			start = -1;
			o++;
		}
		end++;
	}
	dest[o] = 0;
	return (dest);
}

static int	check_c(char *src, char sep)
{
	while (*src)
	{
		if (*src == sep)
			return (1);
		src++;
	}
	return (0);
}
