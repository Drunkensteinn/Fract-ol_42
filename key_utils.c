/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:13:10 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/23 21:20:38 by ablizniu         ###   ########.fr       */
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

void	change_fractal_further(t_mlx *mlx)
{
	size_t	id;

	id = mlx->scr->fractal_to_draw->id;
	if (id + 1 < MAX_FRACTALS_QUANT)
	{
		mlx->scr->fractal_to_draw = &mlx->scr->fractal[(id + 1)];
		mlx->scr->fractal_to_draw->mlx = mlx;
		mlx->scr->fractal_to_draw->win_h = mlx->h;
		mlx->scr->fractal_to_draw->win_w = mlx->w;
	}
	else if (id + 1 >= MAX_FRACTALS_QUANT)
	{
		mlx->scr->fractal_to_draw =
				&mlx->scr->fractal[(id + 1) % MAX_FRACTALS_QUANT];
		mlx->scr->fractal_to_draw->mlx = mlx;
		mlx->scr->fractal_to_draw->win_h = mlx->h;
		mlx->scr->fractal_to_draw->win_w = mlx->w;
	}
}

void	change_fractal_back(t_mlx *mlx)
{
	int8_t	id;

	id = (int8_t)mlx->scr->fractal_to_draw->id;
	if (id - 1 < 0 && FT_ABS(id - 1) < MAX_FRACTALS_QUANT)
	{
		mlx->scr->fractal_to_draw =
				&mlx->scr->fractal[(id - 1) + MAX_FRACTALS_QUANT];
		mlx->scr->fractal_to_draw->mlx = mlx;
		mlx->scr->fractal_to_draw->win_h = mlx->h;
		mlx->scr->fractal_to_draw->win_w = mlx->w;
	}
	else if (id > 0 && id < MAX_FRACTALS_QUANT)
	{
		mlx->scr->fractal_to_draw = &mlx->scr->fractal[id - 1];
		mlx->scr->fractal_to_draw->mlx = mlx;
		mlx->scr->fractal_to_draw->win_h = mlx->h;
		mlx->scr->fractal_to_draw->win_w = mlx->w;
	}
}

void	reset_fractal(t_mlx *mlx)
{
	start_conditions(mlx->scr->fractal_to_draw,
			-2.0, -2.0, 2.0);
	mlx->scr->fractal_to_draw->max_iters = 20;
}
