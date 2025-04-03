/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:23:26 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:23:29 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master_bonus.h"

void	load_config(t_config *config)
{
	int		i;
	int		o;
	char	*tmp;

	i = 0;
	o = open("options.conf", O_RDONLY);
	if (o == -1)
		config->file_exist = 0;
	else
	{
		while (i < 5)
		{
			tmp = get_next_line(o);
			if (!tmp || !tmp[0])
				preloading_error(11, NULL, 1101);
			if (tmp[0] != 0)
				config->conf[i] = tmp[0] - 48;
			free(tmp);
			i++;
		}
		config->file_exist = 1;
		close(o);
	}
	protect_config(config);
	set_config(config);
}

void	set_config(t_config *config)
{
	if (config->file_exist == 0)
	{
		config->conf[0] = 0;
		config->conf[1] = 0;
		config->conf[2] = 0;
		config->conf[3] = 4;
		config->conf[4] = 1;
		config->file_exist = 1;
	}
	moddify_config(config);
}

void	moddify_config(t_config *config)
{
	int		o;
	char	*tmp;

	if (config->file_exist == 0)
		return ;
	o = open("options.conf", O_CREAT | O_RDWR);
	if (o == -1)
		config->file_exist = 0;
	if (config->file_exist != 0)
	{
		tmp = ft_strjoin_conf(config->conf, 5);
		write(o, tmp, ft_strlen(tmp) * sizeof(char));
		free(tmp);
	}
	close(o);
}

void	protect_config(t_config *config)
{
	if (config->file_exist == 0)
		return ;
	protect_config_2(config);
	if (config->conf[0] < 0 || config->conf[0] > 5)
		preloading_error(11, NULL, 1102);
	if (config->conf[1] < 0 || config->conf[1] > 3)
		preloading_error(11, NULL, 1103);
	if (config->conf[2] < 0 || config->conf[2] > 5)
		preloading_error(11, NULL, 1104);
	if (config->conf[3] < 0 || config->conf[3] > 4)
		preloading_error(11, NULL, 1105);
	if (config->conf[4] < 0 || config->conf[4] > 2)
		preloading_error(11, NULL, 1106);
}

void	protect_config_2(t_config *config)
{
	int		o;
	int		i;
	char	*tmp;

	o = open("options.conf", O_RDWR | O_CREAT, 0777);
	i = 0;
	if (o == -1)
		config->file_exist = 0;
	tmp = get_next_line(o);
	while (tmp)
	{
		i++;
		free(tmp);
		tmp = get_next_line(o);
	}
	close(o);
	if (i != 5)
		preloading_error(11, NULL, 1107);
}
