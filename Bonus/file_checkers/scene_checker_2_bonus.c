/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_checker_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:24:42 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:24:45 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	win_check(void)
{
	check_img("imgs/ui/lvl_win/bg_c.png");
	check_img("imgs/ui/lvl_win/bg_i.png");
	check_img("imgs/ui/lvl_win/bg_l.png");
	check_img("imgs/ui/lvl_win/bg_p.png");
	check_img("imgs/ui/lvl_win/bg_r.png");
	check_img("imgs/ui/lvl_win/bg_y.png");
	check_img("imgs/ui/lvl_win/txt.png");
	check_img("imgs/ui/lvl_win/menu.png");
	check_img("imgs/ui/lvl_win/next.png");
	check_img("imgs/ui/lvl_win/next_hl.png");
	check_img("imgs/ui/lvl_win/next_pr.png");
	check_img("imgs/ui/lvl_win/retry_c.png");
	check_img("imgs/ui/lvl_win/retry_c_hl.png");
	check_img("imgs/ui/lvl_win/retry_c_pr.png");
	check_img("imgs/ui/lvl_win/retry_i.png");
	check_img("imgs/ui/lvl_win/retry_i_hl.png");
	check_img("imgs/ui/lvl_win/retry_i_pr.png");
	check_img("imgs/ui/lvl_win/retry_l.png");
	check_img("imgs/ui/lvl_win/retry_l_hl.png");
	check_img("imgs/ui/lvl_win/retry_l_pr.png");
	check_img("imgs/ui/lvl_win/retry_p.png");
	check_img("imgs/ui/lvl_win/retry_p_hl.png");
	check_img("imgs/ui/lvl_win/retry_p_pr.png");
	win_check_2();
}

void	win_check_2(void)
{
	check_img("imgs/ui/lvl_win/retry_r.png");
	check_img("imgs/ui/lvl_win/retry_r_hl.png");
	check_img("imgs/ui/lvl_win/retry_r_pr.png");
	check_img("imgs/ui/lvl_win/retry_y.png");
	check_img("imgs/ui/lvl_win/retry_y_hl.png");
	check_img("imgs/ui/lvl_win/retry_y_pr.png");
}

void	lose_check(void)
{
	check_img("imgs/ui/lvl_fail/bg_c.png");
	check_img("imgs/ui/lvl_fail/bg_i.png");
	check_img("imgs/ui/lvl_fail/bg_l.png");
	check_img("imgs/ui/lvl_fail/bg_p.png");
	check_img("imgs/ui/lvl_fail/bg_r.png");
	check_img("imgs/ui/lvl_fail/bg_y.png");
	check_img("imgs/ui/lvl_fail/txt.png");
	check_img("imgs/ui/lvl_fail/menu.png");
	check_img("imgs/ui/lvl_fail/back.png");
	check_img("imgs/ui/lvl_fail/back_hl.png");
	check_img("imgs/ui/lvl_fail/back_pr.png");
	check_img("imgs/ui/lvl_fail/retry_c.png");
	check_img("imgs/ui/lvl_fail/retry_c_hl.png");
	check_img("imgs/ui/lvl_fail/retry_c_pr.png");
	check_img("imgs/ui/lvl_fail/retry_i.png");
	check_img("imgs/ui/lvl_fail/retry_i_hl.png");
	check_img("imgs/ui/lvl_fail/retry_i_pr.png");
	check_img("imgs/ui/lvl_fail/retry_l.png");
	check_img("imgs/ui/lvl_fail/retry_l_hl.png");
	check_img("imgs/ui/lvl_fail/retry_l_pr.png");
	check_img("imgs/ui/lvl_fail/retry_p.png");
	check_img("imgs/ui/lvl_fail/retry_p_hl.png");
	check_img("imgs/ui/lvl_fail/retry_p_pr.png");
	lose_check_2();
}

void	lose_check_2(void)
{
	check_img("imgs/ui/lvl_fail/retry_r.png");
	check_img("imgs/ui/lvl_fail/retry_r_hl.png");
	check_img("imgs/ui/lvl_fail/retry_r_pr.png");
	check_img("imgs/ui/lvl_fail/retry_y.png");
	check_img("imgs/ui/lvl_fail/retry_y_hl.png");
	check_img("imgs/ui/lvl_fail/retry_y_pr.png");
	check_img("imgs/ui/lvl_fail/no_retry.png");
}
