/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:24:42 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:24:45 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master.h"

void	map_check(void)
{
	check_multi_tiles(FOLDER1_1, 47);
	check_multi_tiles(FOLDER2_1, 8);
	check_multi_tiles(FOLDER3_1, 8);
}

void	check_multi_tiles(char *s, int nb_iter)
{
	int		i;
	char	*nb;
	char	*tmp;
	char	*res;

	i = 0;
	while (i < nb_iter)
	{
		nb = ft_itoa(i);
		tmp = ft_strjoin(s, nb);
		res = ft_strjoin(tmp, EXT);
		check_img(res);
		free(nb);
		free(tmp);
		free(res);
		i++;
	}
}
