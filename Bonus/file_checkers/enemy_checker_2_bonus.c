/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_checker_2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:24:42 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:24:45 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	check_nmi_4(char *s)
{
	char	*tmp;

	tmp = ft_strjoin(s, SL_);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SL_0);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SL_1);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SL_2);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SL_3);
	check_img(tmp);
	free(tmp);
}
