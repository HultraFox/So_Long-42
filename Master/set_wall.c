/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	set_wall(t_mlx *mlx, int y, int x, int v)
{
	if (v == 21 || v == 53 || v == 85 || v == 117)
		mlx->values[y][x] = 16;
	else if (v == 23 || v == 55 || v == 151 || v == 183)
		mlx->values[y][x] = 17;
	else if (v == 29 || v == 93 || v == 157 || v == 221)
		mlx->values[y][x] = 18;
	else if (v == 31)
		mlx->values[y][x] = 19;
	else if (v == 41 || v == 57 || v == 169 || v == 185)
		mlx->values[y][x] = 20;
	else if (v == 43 || v == 59 || v == 107 || v == 123)
		mlx->values[y][x] = 21;
	else if (v == 45 || v == 173 || v == 109 || v == 237)
		mlx->values[y][x] = 22;
	else if (v == 47)
		mlx->values[y][x] = 23;
	else if (v == 61 || v == 125 || v == 189 || v == 253)
		mlx->values[y][x] = 24;
	else if (v == 63)
		mlx->values[y][x] = 25;
	else if (v == 70 || v == 86 || v == 198 || v == 214)
		mlx->values[y][x] = 26;
	else
		set_wall_2(mlx, y, x, v);
}

void	set_wall_2(t_mlx *mlx, int y, int x, int v)
{
	if (v == 71 || v == 199 || v == 103 || v == 231)
		mlx->values[y][x] = 27;
	else if (v == 78 || v == 94 || v == 110 || v == 126)
		mlx->values[y][x] = 28;
	else if (v == 79)
		mlx->values[y][x] = 29;
	else if (v == 87 || v == 119 || v == 215 || v == 247)
		mlx->values[y][x] = 30;
	else if (v == 95)
		mlx->values[y][x] = 31;
	else if (v == 111)
		mlx->values[y][x] = 32;
	else if (v == 127)
		mlx->values[y][x] = 33;
	else if (v == 138 || v == 170 || v == 202 || v == 234)
		mlx->values[y][x] = 34;
	else if (v == 139 || v == 203 || v == 155 || v == 219)
		mlx->values[y][x] = 35;
	else if (v == 142 || v == 174 || v == 158 || v == 190)
		mlx->values[y][x] = 36;
	else if (v == 143)
		mlx->values[y][x] = 37;
	else
		set_wall_3(mlx, y, x, v);
}

void	set_wall_3(t_mlx *mlx, int y, int x, int v)
{
	if (v == 159)
		mlx->values[y][x] = 38;
	else if (v == 171 || v == 187 || v == 235 || v == 251)
		mlx->values[y][x] = 39;
	else if (v == 175)
		mlx->values[y][x] = 40;
	else if (v == 191)
		mlx->values[y][x] = 41;
	else if (v == 206 || v == 222 || v == 238 || v == 254)
		mlx->values[y][x] = 42;
	else if (v == 207)
		mlx->values[y][x] = 43;
	else if (v == 223)
		mlx->values[y][x] = 44;
	else if (v == 239)
		mlx->values[y][x] = 45;
	else if (v == 255)
		mlx->values[y][x] = 46;
	else
		set_wall_4(mlx, y, x, v);
}

void	set_wall_4(t_mlx *mlx, int y, int x, int v)
{
	if (v == 28 || v == 44 || v == 76 || v == 140 || v == 60 || v == 92
		|| v == 156 || v == 124 || v == 188 || v == 220 || v == 108
		|| v == 172 || v == 236 || v == 204 || v == 252)
		mlx->values[y][x] = 12;
	else if (v == 17 || v == 33 || v == 49)
		mlx->values[y][x] = 1;
	else if (v == 130 || v == 66 || v == 194)
		mlx->values[y][x] = 2;
	else if (v == 19 || v == 35 || v == 67 || v == 131 || v == 51
		|| v == 83 || v == 147 || v == 99 || v == 163 || v == 195
		|| v == 115 || v == 179 || v == 243 || v == 211 || v == 227)
		mlx->values[y][x] = 3;
	else if (v == 84 || v == 20 || v == 68)
		mlx->values[y][x] = 4;
	else if (v == 37 || v == 69 || v == 101)
		mlx->values[y][x] = 5;
	else if (v == 22 || v == 134 || v == 150)
		mlx->values[y][x] = 6;
	else if (v == 168 || v == 40 || v == 136)
		mlx->values[y][x] = 8;
	else if (v == 25 || v == 137 || v == 153)
		mlx->values[y][x] = 9;
	else
		set_wall_5(mlx, y, x, v);
}

void	set_wall_5(t_mlx *mlx, int y, int x, int v)
{
	if (v == 42 || v == 74 || v == 106)
		mlx->values[y][x] = 10;
	else if (v == 135 || v == 39 || v == 167)
		mlx->values[y][x] = 7;
	else if (v == 75 || v == 27 || v == 91)
		mlx->values[y][x] = 11;
	else if (v == 30 || v == 46 || v == 62)
		mlx->values[y][x] = 14;
	else if (v == 77 || v == 141 || v == 205)
		mlx->values[y][x] = 13;
	else if (v >= 16)
		mlx->values[y][x] = 0;
}
