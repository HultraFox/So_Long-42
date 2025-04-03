/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:24:42 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:24:45 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	obj_check(int m_skin)
{
	if (m_skin == 0)
	{
		check_multi_tiles(OBJ_1, 2);
		check_multi_tiles(EXIT_1, 8);
	}
	else if (m_skin == 1)
	{
		check_multi_tiles(OBJ_2, 2);
		check_multi_tiles(EXIT_2, 8);
	}
	else if (m_skin == 2)
	{
		check_multi_tiles(OBJ_3, 2);
		check_multi_tiles(EXIT_3, 8);
	}
	else if (m_skin == 3)
	{
		check_multi_tiles(OBJ_4, 2);
		check_multi_tiles(EXIT_4, 8);
	}
	else
		preloading_error(1, NULL, 1004);
}
