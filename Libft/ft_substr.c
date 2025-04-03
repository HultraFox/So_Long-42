/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:59:50 by fmontel           #+#    #+#             */
/*   Updated: 2024/10/09 12:59:56 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	setstr(char *s, char const *src, unsigned int start, size_t len);

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*s;

	if (start >= ft_strlen(src))
	{
		s = malloc(1);
		if (!s)
			return (NULL);
		s[0] = 0;
		return (s);
	}
	if (len >= ft_strlen(src) || len + start >= ft_strlen(src))
		len = ft_strlen(src) - start;
	s = malloc(len * sizeof(char) + 1);
	if (!s)
		return (NULL);
	setstr(s, src, start, len);
	return (s);
}

static void	setstr(char *s, char const *src, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && src[i + start] != 0)
	{
		s[i] = src[i + start];
		i++;
	}
	while (i + start < len)
	{
		s[i] = 0;
		i++;
	}
	s[i] = 0;
}
