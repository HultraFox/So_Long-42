/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:04:58 by fmontel           #+#    #+#             */
/*   Updated: 2024/10/09 09:05:00 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	finder;

	i = 0;
	finder = ft_strlen(little);
	if (finder == 0)
		return ((char *) big);
	if (len == 0)
		return (NULL);
	while (big[i] != 0 && i != len)
	{
		j = 0;
		if (big[i] == little[0])
		{
			while (big[i + j] == little[j] && big[i + j] != 0
				&& i + j != len)
				j++;
			if (little[j] == 0)
				return ((char *) big + i);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
