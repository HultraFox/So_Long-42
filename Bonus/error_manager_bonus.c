/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:23:46 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:23:48 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master_bonus.h"

void	error_manager(int err_type, t_mlx *param, int err_code, char *s)
{
	play_sound(99);
	loading_error(err_type, err_code, s);
	error_list_1();
	error_exit(param, err_code);
}

void	preloading_error(int err_type, char *s, int err_code)
{
	if (err_type == -1)
		ft_printf("%s%s%s\n	%s%s%s\n", _CB, ERR_Z, _W_,
			_C_, INF_Z, _W_);
	else if (err_type == 1)
		ft_printf("%s%s%s\n	%s%s%s%s%s\n", _CB, ERR_1, _W_,
			_Y_, INF_1, _YB, s, _W_);
	else if (err_type == 2)
		ft_printf("%s%s%s\n	%s%s%s%i%s\n", _RB, ERR_2, _W_,
			_Y_, INF_2, _YB, err_code, _W_);
	else if (err_type == 3)
		ft_printf("%s%s%s\n	%s%s%s%i%s\n", _YB, ERR_3, _W_,
			_Y_, INF_3, _YB, err_code, _W_);
	else if (err_type == 11)
		ft_printf("%s%s%s\n	%s%s%s%i%s\n", _RB, ERR_11, _W_,
			_Y_, INF_11, _YB, err_code, _W_);
	error_list_1();
	exit(1);
}

void	loading_error(int err_type, int err_code, char *s)
{
	if (err_type == -1)
		ft_printf("%s%s%s\n	%s%s%s\n", _CB, ERR_Z, _W_,
			_C_, INF_Z, _W_);
	else if (err_type == 9)
		ft_printf("%s%s%s\n	%s%s%s%i%s\n", _RB, ERR_0, _W_,
			_Y_, INF_0, _YB, err_code, _W_);
	else if (err_type == 1)
		ft_printf("%s%s%s\n	%s%s%s%i%s\n", _YB, ERR_1, _W_,
			_Y_, INF_1, _YB, err_code, _W_);
	else if (err_type == 2)
		ft_printf("%s%s%s\n	%s%s%s%i%s\n", _RB, ERR_2, _W_,
			_Y_, INF_2, _YB, err_code, _W_);
	else if (err_type == 3)
		ft_printf("%s%s%s\n	%s%s%s%i%s\n", _YB, ERR_3, _W_,
			_Y_, INF_3, _YB, err_code, _W_);
	else if (err_type == 4)
		ft_printf("%s%s%s\n	%s%s%s%s%s%s%s%i%s\n", _CB, ERR_4, _W_,
			_Y_, INF_4_1, _YB, s, _Y_, INF_4_2, _YB, err_code, _W_);
	else if (err_type == 5 && err_code != 5004)
		ft_printf("%s%s%s\n	%s%s%s%s%s%s%s%i%s\n", _CB, ERR_4, _W_,
			_Y_, INF_5_1, _YB, s, _Y_, INF_5_2, _YB, err_code, _W_);
	else
		loading_error_2(err_type, err_code, s);
}

void	loading_error_2(int err_type, int err_code, char *s)
{
	if (err_type == 5 && err_code == 5004)
		ft_printf("%s%s%s\n	%s%s%s%s%s%s%s%i%s\n", _CB, ERR_4, _W_,
			_Y_, INF_5_1, _YB, s, _Y_, INF_5_4, _YB, err_code, _W_);
	else if (err_type == 6 && err_code != 6006)
		ft_printf("%s%s%s\n	%s%s%s%s%s%s%s%i%s\n", _CB, ERR_4, _W_,
			_Y_, INF_5_1, _YB, s, _Y_, INF_6_1, INF_4_2, err_code, _W_);
	else if (err_type == 6 && err_code == 6006)
		ft_printf("%s%s%s\n	%s%s%s%s%s%s%s%i%s\n", _CB, ERR_4, _W_,
			_Y_, INF_5_1, _YB, s, _Y_, INF_6_6, INF_4_2, err_code, _W_);
	else if (err_type == 7)
		ft_printf("%s%s%s\n	%s%s%s%s%s%s%i%s\n", _CB, ERR_4, _W_,
			_Y_, INF_7_1, _YB, s, _Y_, INF_4_2, err_code, _W_);
	else if (err_type == 8)
		ft_printf("%s%s%s\n	%s%s%s%s%s%s%i%s\n", _CB, ERR_4, _W_,
			_Y_, INF_8_1, _YB, s, _Y_, INF_4_2, err_code, _W_);
	else
		ft_printf("%s%s%s\n	%s%s%s%i%s\n", _RB, ERR_X, _W_,
			_Y_, INF_X, _YB, err_code, _W_);
}

void	error_list_1(void)
{
	ft_printf("\n%sError codes:%s\n", _WB, _W_);
	ft_printf("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
		_CC, ERR_C_1, _W_, ERR_C_11, ERR_C_12, ERR_C_15, ERR_C_16, _RR,
		ERR_C_2, _W_, ERR_C_21, ERR_C_24, ERR_C_25, ERR_C_26, _YY, ERR_C_3,
		ERR_C_4, _W_, ERR_C_5, ERR_C_6, _W_, ERR_C_61, ERR_C_62, ERR_C_63,
		ERR_C_64, ERR_C_65, ERR_C_66, _CC, _CC);
	ft_printf("%s%s%s%s%s%s%s\n",
		ERR_C_7, ERR_C_8, _RR, ERR_C_9, _YY, ERR_C_110, _W_);
}
