/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:24:42 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:24:45 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master.h"

void	img_checker(void)
{
	check_img("imgs/chars/slime_l/f0.png");
	check_img("imgs/chars/slime_l/b0.png");
	check_img("imgs/chars/slime_l/l0.png");
	check_img("imgs/chars/slime_l/r0.png");
	map_check();
	obj_check();
}

void	check_img(char *s)
{
	int			o;

	if (s == NULL)
		preloading_error();
	o = open(s, O_RDONLY);
	if (o == -1)
	{
		preloading_error();
		free(s);
	}
	close(o);
}
