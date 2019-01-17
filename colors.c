/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:44:59 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/17 14:56:59 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					get_rvalue(int clr)
{
	return (clr >> 16 & 0xFF);
}

int					get_gvalue(int clr)
{
	return (clr >> 8 & 0xFF);
}

int					get_bvalue(int clr)
{
	return (clr & 0xFF);
}

static	int			color(int first, int second, double prc)
{
	return (int)((first + (second - first) * prc));
}

int					gradient(int first, int second, double procent)
{
	int red;
	int green;
	int blue;

	if (first == second)
		return (first);
	red = color(get_rvalue(first),
				 get_rvalue(second), procent);
	green = color(get_gvalue(first),
				 get_gvalue(second), procent);
	blue = color(get_bvalue(first),
				 get_bvalue(second), procent);
	return (red << 16 | green << 8 | blue);
}

void		calculate_red(t_colors *colors, int32_t delta)
{
	if (colors->red >= 255 && colors->green < 255 && colors->blue <= 0)
	{
		colors->green += delta;
		if (colors->green > 255)
			colors->green =  255;
	}
	else if (colors->red <= 255 && colors->green >= 255 && colors->blue <= 0)
	{
		colors->red -= delta;
		if (colors->red < 0)
			colors->red = 0;
	}
}

void		calculate_green(t_colors *colors, int32_t delta)
{
	if (colors->green >= 255 && colors->red == 0 && colors->blue < 255)
	{
		colors->blue += delta;
		if (colors->blue > 255)
			colors->blue = 255;
	}
	else if (colors->red == 0 && colors->green <= 255 && colors->blue >= 255)
	{
		colors->green -= delta;
		if (colors->green < 0)
			colors->green = 0;
	}
}

void		calculate_blue(t_colors *colors, int32_t delta)
{
	if (colors->blue >= 255 && colors->green == 0 && colors->red < 255)
	{
		colors->red += delta;
		if (colors->red > 255)
			colors->red = 255;
	}
	else if (colors->red == 255 && colors->green == 0 && colors->blue <= 255)
	{
		colors->blue -= delta;
		if (colors->blue < 0)
			colors->blue = 0;
		colors->green -= delta;
	}
}

inline void		colors(t_mlx *mlx, size_t iter)
{
	size_t	i;

	i = 0;
	iter %= CLR_MOD;
	mlx->scr->colors->red = 0 + mlx->scr->delta_red;
	mlx->scr->colors->green = 0 + mlx->scr->delta_green;
	mlx->scr->colors->blue = 0 + mlx->scr->delta_blue;
	mlx->scr->delta = 16;
	//0xd133ff
//	if (iter == 1)
//		mlx->scr->color = gradient(0xff3333, 0x000000, 0.5) + mlx->scr->delta;
//	else if (iter == 2)
//		mlx->scr->color = 0xff3333 + mlx->scr->delta; // red
//	else if (iter == 3)
//		mlx->scr->color = gradient(0xff9633, 0xff3333, 0.5) + mlx->scr->delta;
//	else if (iter == 4)
//		mlx->scr->color = 0xff9633 + mlx->scr->delta; // orange
//	else if (iter == 5)
//		mlx->scr->color = gradient(0xf6ff33, 0xff9633, 0.5) + mlx->scr->delta;
//	else if (iter == 6)
//		mlx->scr->color = 0xf6ff33 + mlx->scr->delta; // yellow
//	else if (iter == 7)
//		mlx->scr->color = gradient(0x66f933, 0xf6ff33, 0.5) + mlx->scr->delta;
//	else if (iter == 8)
//		mlx->scr->color	= 0x66f933 +  mlx->scr->delta; // green
//	else if (iter == 9)
//		mlx->scr->color	= gradient(0x33f9fa, 0x66f933, 0.5) + mlx->scr->delta;
//	else if (iter == 10)
//		mlx->scr->color	= 0x33f9fa + mlx->scr->delta; // white - blue;
//	else if (iter == 11)
//		mlx->scr->color	= gradient(0x3360f9, 0x33f9fa, 0.5) + mlx->scr->delta;
//	else if (iter == 12)
//		mlx->scr->color	= 0x3360f9 + mlx->scr->delta; // blue;
//	else if (iter == 13)
//		mlx->scr->color	= gradient(0xd01bb7, 0x3360f9, 0.5) + mlx->scr->delta;
//	else if (iter == 14)
//		mlx->scr->color	= 0xd01bb7 + mlx->scr->delta; // violet
//	else if (iter == 15)
//		mlx->scr->color	= gradient(0xd01b41, 0xd01bb7, 0.5) + mlx->scr->delta;

	while (i < iter)
	{
		calculate_red(mlx->scr->colors, mlx->scr->delta);
		calculate_green(mlx->scr->colors,mlx->scr->delta);
		calculate_blue(mlx->scr->colors,mlx->scr->delta);
		i++;
	}
	mlx->scr->color = (uint32_t)(mlx->scr->colors->red << 16 | mlx->scr->colors->green << 8 | mlx->scr->colors->blue);

}
