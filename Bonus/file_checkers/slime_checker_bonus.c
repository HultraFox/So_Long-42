/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slime_checker_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:24:42 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:24:45 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	slime_check(int skin)
{
	char	*s;

	if (skin == 0)
		s = "imgs/chars/slime_l/";
	else if (skin == 1)
		s = "imgs/chars/slime_c/";
	else if (skin == 2)
		s = "imgs/chars/slime_i/";
	else if (skin == 3)
		s = "imgs/chars/slime_p/";
	else if (skin == 4)
		s = "imgs/chars/slime_r/";
	else if (skin == 5)
		s = "imgs/chars/slime_y/";
	else
		s = NULL;
	if (!s)
		preloading_error(1, NULL, 1002);
	check_slime_1(s);
	check_slime_2(s);
}

void	check_slime_1(char *s)
{
	char	*tmp;

	tmp = ft_strjoin(s, SF_0);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SF_1);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SF_3);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SB_0);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SB_1);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SB_3);
	check_img(tmp);
	free(tmp);
}

void	check_slime_2(char *s)
{
	char	*tmp;

	tmp = ft_strjoin(s, SR_0);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SR_1);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SR_3);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SL_0);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SL_1);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SL_3);
	check_img(tmp);
	free(tmp);
}

void	slime128_check(void)
{
	check_img("imgs/chars_x128/l_0.png");
	check_img("imgs/chars_x128/l_1.png");
	check_img("imgs/chars_x128/l_3.png");
	check_img("imgs/chars_x128/c_0.png");
	check_img("imgs/chars_x128/c_1.png");
	check_img("imgs/chars_x128/c_3.png");
	check_img("imgs/chars_x128/i_0.png");
	check_img("imgs/chars_x128/i_1.png");
	check_img("imgs/chars_x128/i_3.png");
	check_img("imgs/chars_x128/p_0.png");
	check_img("imgs/chars_x128/p_1.png");
	check_img("imgs/chars_x128/p_3.png");
	check_img("imgs/chars_x128/r_0.png");
	check_img("imgs/chars_x128/r_1.png");
	check_img("imgs/chars_x128/r_3.png");
	check_img("imgs/chars_x128/y_0.png");
	check_img("imgs/chars_x128/y_1.png");
	check_img("imgs/chars_x128/y_3.png");
}
