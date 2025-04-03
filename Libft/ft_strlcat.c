/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 07:33:20 by fmontel           #+#    #+#             */
/*   Updated: 2024/09/17 08:52:16 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	len;
	size_t	i;

	d_len = ft_strlen((const char *)dst);
	len = ft_strlen((const char *)dst);
	s_len = ft_strlen(src);
	i = 0;
	if (size <= len)
		return (s_len + size);
	while (src[i] && i < size - len - 1)
	{
		dst[d_len] = src[i];
		d_len++;
		i++;
	}
	dst[d_len] = '\0';
	return (len + s_len);
}
