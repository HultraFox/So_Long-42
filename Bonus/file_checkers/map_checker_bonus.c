/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:24:42 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:24:45 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	map_check(int m_skin)
{
	if (m_skin == 0)
	{
		check_multi_tiles(FOLDER1_1, 47);
		check_multi_tiles(FOLDER2_1, 8);
		check_multi_tiles(FOLDER3_1, 8);
		check_img(DOOR_0);
	}
	else if (m_skin == 1)
	{
		check_multi_tiles(FOLDER1_2, 47);
		check_multi_tiles(FOLDER2_2, 8);
		check_multi_tiles(FOLDER3_2, 8);
		check_img(DOOR_1);
	}
	else
		map_check_2(m_skin);
}

void	map_check_2(int m_skin)
{
	if (m_skin == 2)
	{
		check_multi_tiles(FOLDER1_3, 47);
		check_multi_tiles(FOLDER2_3, 8);
		check_multi_tiles(FOLDER3_3, 8);
		check_img(DOOR_2);
	}
	else if (m_skin == 3)
	{
		check_multi_tiles(FOLDER1_4, 47);
		check_multi_tiles(FOLDER2_4, 8);
		check_multi_tiles(FOLDER3_4, 8);
		check_img(DOOR_3);
	}
	else
		preloading_error(2, NULL, 1003);
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
