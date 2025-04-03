/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_checker_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:24:42 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:24:45 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	ennemy_check(void)
{
	check_nmi_1(NMI_1);
	check_nmi_1(NMI_2);
	check_nmi_1(NMI_3);
	check_nmi_1(NMI_4);
	check_nmi_1(NMI_5);
	check_nmi_1(NMI_6);
	check_nmi_1(NMI_7);
	check_nmi_1(NMI_8);
	check_nmi_1(NMI_9);
	check_nmi_2(NMI_1);
	check_nmi_2(NMI_2);
	check_nmi_2(NMI_3);
	check_nmi_2(NMI_4);
	check_nmi_2(NMI_5);
	check_nmi_2(NMI_6);
	check_nmi_2(NMI_7);
	check_nmi_2(NMI_8);
	check_nmi_2(NMI_9);
	check_nmi_3(NMI_1);
	check_nmi_3(NMI_2);
	check_nmi_3(NMI_3);
	check_nmi_3(NMI_4);
	ennemy_check_2();
}

void	ennemy_check_2(void)
{
	check_nmi_3(NMI_5);
	check_nmi_3(NMI_6);
	check_nmi_3(NMI_7);
	check_nmi_3(NMI_8);
	check_nmi_3(NMI_9);
	check_nmi_4(NMI_1);
	check_nmi_4(NMI_2);
	check_nmi_4(NMI_3);
	check_nmi_4(NMI_4);
	check_nmi_4(NMI_5);
	check_nmi_4(NMI_6);
	check_nmi_4(NMI_7);
	check_nmi_4(NMI_8);
	check_nmi_4(NMI_9);
}

void	check_nmi_1(char *s)
{
	char	*tmp;

	tmp = ft_strjoin(s, SF_);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SF_0);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SF_1);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SF_2);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SF_3);
	check_img(tmp);
	free(tmp);
}

void	check_nmi_2(char *s)
{
	char	*tmp;

	tmp = ft_strjoin(s, SB_);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SB_0);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SB_1);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SB_2);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SB_3);
	check_img(tmp);
	free(tmp);
}

void	check_nmi_3(char *s)
{
	char	*tmp;

	tmp = ft_strjoin(s, SR_);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SR_0);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SR_1);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SR_2);
	check_img(tmp);
	free(tmp);
	tmp = ft_strjoin(s, SR_3);
	check_img(tmp);
	free(tmp);
}
