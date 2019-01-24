/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:50:20 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/24 12:15:36 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int					key_events(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
	{
		free_memmory(mlx);
		exit(0);
	}
	else if (keycode == ARROW_UP)
		mlx->scr->fractal_to_draw->min.im -= 0.05;
	else if (keycode == ARROW_DOWN)
		mlx->scr->fractal_to_draw->min.im += 0.05;
	else if (keycode == ARROW_LEFT)
	{
		mlx->scr->fractal_to_draw->min.re += 0.05;
		mlx->scr->fractal_to_draw->max.re += 0.05;
	}
	else if (keycode == ARROW_RIGHT)
	{
		mlx->scr->fractal_to_draw->min.re -= 0.05;
		mlx->scr->fractal_to_draw->max.re -= 0.05;
	}
	key_events_color(mlx, keycode);
	key_events_change_fractals(mlx, keycode);
	refresh(mlx);
	return (0);
}

inline void			key_events_color(t_mlx *mlx, int keycode)
{
	if (keycode == NUM_PAD_KEY_1)
		mlx->scr->fractal_to_draw->colors->delta_red = 255;
	else if (keycode == NUM_PAD_KEY_4)
		mlx->scr->fractal_to_draw->colors->delta_red = 0;
	else if (keycode == NUM_PAD_KEY_2)
		mlx->scr->fractal_to_draw->colors->delta_green = 255;
	else if (keycode == NUM_PAD_KEY_5)
		mlx->scr->fractal_to_draw->colors->delta_green = 0;
	else if (keycode == NUM_PAD_KEY_3)
		mlx->scr->fractal_to_draw->colors->delta_blue = 0;
	else if (keycode == NUM_PAD_KEY_6)
		mlx->scr->fractal_to_draw->colors->delta_blue = 255;
	else if (keycode == Q)
		mlx->scr->fractal_to_draw->colors->clr_mod += 1;
	else if (keycode == W)
		mlx->scr->fractal_to_draw->colors->clr_mod -= 1;
	else if (keycode == A)
		mlx->scr->fractal_to_draw->colors->delta_color += 4;
	else if (keycode == S)
		mlx->scr->fractal_to_draw->colors->delta_color -= 4;
	else if (keycode == SPACE)
		mlx->scr->fractal_to_draw->mouse_block =
				!mlx->scr->fractal_to_draw->mouse_block;
	else if (keycode == R)
		reset_fractal(mlx);
}

inline void			key_events_change_fractals(t_mlx *mlx, int keycode)
{
	if (keycode == X)
		change_fractal_further(mlx);
	else if (keycode == Z)
		change_fractal_back(mlx);
	else if (keycode == NUM_1)
		change_iter(mlx, true);
	else if (keycode == NUM_2)
		change_iter(mlx, false);
}
