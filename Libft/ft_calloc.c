/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:39:19 by fmontel           #+#    #+#             */
/*   Updated: 2024/10/09 10:39:22 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*s;

	if (nmemb <= 0 || size <= 0)
	{
		s = malloc(0);
		if (!s)
			return (NULL);
		return (s);
	}
	s = malloc(nmemb * size);
	if (!s)
		return (NULL);
	ft_bzero(s, nmemb * size);
	return (s);
}

int	**ft_calloc_double(size_t nmemb, size_t sd, size_t su, size_t len)
{
	int		**s;
	size_t	i;

	i = 0;
	if (nmemb <= 0 || sd <= 0)
	{
		s = malloc(0);
		if (!s)
			return (NULL);
		return (s);
	}
	s = malloc(nmemb * sd);
	if (!s)
		return (NULL);
	while (i < nmemb)
	{
		s[i] = malloc(len * su);
		if (!s[i])
			return (NULL);
		ft_bzero(s[i], len * su);
		i++;
	}
	return (s);
}
