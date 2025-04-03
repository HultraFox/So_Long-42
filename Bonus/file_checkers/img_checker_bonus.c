/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:24:42 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:24:45 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	img_checker(void)
{
	int	i;

	i = 0;
	while (i < S_SKIN)
	{
		slime_check(i);
		i++;
	}
	i = 0;
	while (i < M_SKIN)
	{
		map_check(i);
		obj_check(i);
		i++;
	}
	ennemy_check();
	main_menu_check();
	slime128_check();
	custom_check();
	lives_check();
	dialogue_check();
	win_check();
	lose_check();
	special_check();
}

void	check_img(char *s)
{
	int			o;

	if (s == NULL)
		preloading_error(3, NULL, 3001);
	o = open(s, O_RDONLY);
	if (o == -1)
	{
		preloading_error(1, s, 1001);
		free(s);
	}
	close (o);
}

void	special_check(void)
{
	check_img("imgs/ui/ftb/ftb_0.png");
	check_img("imgs/ui/ftb/ftb_1.png");
	check_img("imgs/ui/ftb/ftb_2.png");
	check_img("imgs/ui/ftb/ftb_3.png");
	check_img("imgs/ui/ftb/ftb_4.png");
	check_img("imgs/ui/ftb/ftb_5.png");
	check_img("imgs/ui/ftb/ftb_6.png");
	check_img("imgs/ui/ftb/ftb_7.png");
	check_img("imgs/ui/ftb/ftb_8.png");
	check_img("imgs/ui/ftb/ftb_9.png");
	check_img("imgs/ui/ftb/ftb_10.png");
	check_img("imgs/ui/ftb/ftb_11.png");
	check_img("imgs/ui/ftb/ftb_12.png");
	check_img("imgs/ui/ftb/ftb_12.png");
	check_img(FINISHED);
	check_img(CREDITS);
	check_img(LINE);
	check_img(SELEC);
}
