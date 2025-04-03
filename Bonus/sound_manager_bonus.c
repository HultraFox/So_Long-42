/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound_manager_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master_bonus.h"

void	play_sound(int sound)
{
	if (sound == 0 && check_sound(sound))
		system("paplay -p ./Bonus/audio/select.wav &");
	else if (sound == 1 && check_sound(sound))
		system("paplay -p ./Bonus/audio/confirm.wav &");
	else if (sound == 2 && check_sound(sound))
		system("paplay -p ./Bonus/audio/back.wav &");
	else if (sound == 3 && check_sound(sound))
		system("paplay -p ./Bonus/audio/exit_door.wav &");
	else if (sound == 4 && check_sound(sound))
		system("paplay -p ./Bonus/audio/slime_noise.wav &");
	else if (sound == 5 && check_sound(sound))
		system("paplay -p ./Bonus/audio/collectible.wav &");
	else if (sound == 88 && check_sound(sound))
		system("paplay -p ./Bonus/audio/debug.wav &");
	else if (sound == 99 && check_sound(sound))
		system("paplay -p ./Bonus/audio/error.wav &");
}

int	check_sound(int sound)
{
	int	i;

	i = -1;
	if (sound == 0)
		i = open("./Bonus/audio/select.wav", O_RDONLY);
	else if (sound == 1)
		i = open("./Bonus/audio/confirm.wav", O_RDONLY);
	else if (sound == 2)
		i = open("./Bonus/audio/back.wav", O_RDONLY);
	else if (sound == 3)
		i = open("./Bonus/audio/exit_door.wav", O_RDONLY);
	else if (sound == 4)
		i = open("./Bonus/audio/slime_noise.wav", O_RDONLY);
	else if (sound == 5)
		i = open("./Bonus/audio/collectible.wav", O_RDONLY);
	else if (sound == 88)
		i = open("./Bonus/audio/debug.wav", O_RDONLY);
	else if (sound == 99)
		i = open("./Bonus/audio/error.wav", O_RDONLY);
	return (close_sound(i));
}

int	close_sound(int file)
{
	if (file != -1)
	{
		close (file);
		return (1);
	}
	else
		return (0);
}
