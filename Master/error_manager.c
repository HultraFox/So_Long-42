/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:23:46 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:23:48 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	error_manager(t_mlx *param, int err_code)
{
	ft_printf("Error\n	code: %i\n\n", err_code);
	ft_printf("Codes:\n	*1	:can't read file or no .ber extention;\n");
	ft_printf("	*2,3	:Can't open map;\n");
	ft_printf("	*4,11	:Malloc error;\n");
	ft_printf("	*5	:Can't reach exit;\n");
	ft_printf("	*6	:Can't reach all collectibles;\n");
	ft_printf("	*7	:Empty line in map;\n");
	ft_printf("	*8	:Map is not rectangular;\n");
	ft_printf("	*9	:Map is too large;\n");
	ft_printf("	*10	:Missing Player, Exit or Collectible;\n");
	ft_printf("	*12	:Unknown character in map;\n");
	ft_printf("	*13	:Too many Player in map;\n");
	ft_printf("	*14	:Too many Exit in map;\n");
	ft_printf("	*15	:Empty map file;\n\n");
	error_exit(param);
}

void	preloading_error(void)
{
	ft_printf("Error\n");
	exit(1);
}
