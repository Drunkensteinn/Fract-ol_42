/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:50:20 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/23 16:54:15 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	change_iter(t_mlx *mlx, t_bool sign)
{
	if (mlx->scr->fractal_to_draw->max_iters)
	{
		if (sign)
			mlx->scr->fractal_to_draw->max_iters++;
		else
			mlx->scr->fractal_to_draw->max_iters--;
	}
	else
		mlx->scr->fractal_to_draw->max_iters = 1;
}

void 	change_fractal_further(t_mlx *mlx)
{
	size_t	id;

	id = mlx->scr->fractal_to_draw->id;
	if (id + 1 < MAX_FRACTALS_QUANT)
	{
		mlx->scr->fractal_to_draw = &mlx->scr->fractal[(id + 1)];
		mlx->scr->fractal_to_draw->mlx = mlx;
	}
	else if (id + 1 >= MAX_FRACTALS_QUANT)
	{
		mlx->scr->fractal_to_draw = &mlx->scr->fractal[(id + 1) % MAX_FRACTALS_QUANT];
		mlx->scr->fractal_to_draw->mlx = mlx;
	}
}

void 	change_fractal_back(t_mlx *mlx)
{
	int8_t	id;

	id = (int8_t)mlx->scr->fractal_to_draw->id;
	if (id - 1 < 0 && FT_ABS(id - 1) < MAX_FRACTALS_QUANT)
	{
		mlx->scr->fractal_to_draw = &mlx->scr->fractal[(id - 1) + MAX_FRACTALS_QUANT];
		mlx->scr->fractal_to_draw->mlx = mlx;
	}
	else if (id > 0 && id < MAX_FRACTALS_QUANT)
	{
		mlx->scr->fractal_to_draw = &mlx->scr->fractal[id - 1];
		mlx->scr->fractal_to_draw->mlx = mlx;
	}
}


void	reset_fractal(t_mlx *mlx)
{
	start_conditions(mlx->scr->fractal_to_draw,
					 -2.0, -2.0, 2.0);
	mlx->scr->fractal_to_draw->max_iters = 20;
}

int 	key_events(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
		exit(0);
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
	else if (keycode == NUM_1)
		change_iter(mlx, true);
	else if (keycode == NUM_2)
		change_iter(mlx, false);
	else if (keycode == NUM_PAD_KEY_1)
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
		mlx->scr->fractal_to_draw->mouse_block = !mlx->scr->fractal_to_draw->mouse_block;
	else if (keycode == R)
		reset_fractal(mlx);
	else if (keycode == X)
		change_fractal_further(mlx);
	else if (keycode == Z)
		change_fractal_back(mlx);
	refresh(mlx);
	return (0);
}