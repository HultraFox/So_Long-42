/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:29:52 by fmontel           #+#    #+#             */
/*   Updated: 2024/10/09 14:29:54 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	s = malloc(len * sizeof(char) + 1);
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != 0)
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = 0;
	return (s);
}

char	*ft_strjoin_conf(int const *s1, int len)
{
	char	*s;
	int		i;
	int		j;
	int		size;

	size = len * 2 - 1;
	s = malloc(size * sizeof(char) + 1);
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (j < len)
	{
		s[i] = s1[j] + 48;
		i++;
		j++;
		if (i < size)
		{
			s[i] = '\n';
			i++;
		}
	}
	s[i] = 0;
	return (s);
}
