/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:04:05 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/22 21:49:54 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_factor(int button, t_mlx *mlx)
{
	if (button == MWHEEL_UP)
		mlx->scr->fractal_to_draw->zoom = 0.80;
	else if (button == MWHEEL_DOWN)
		mlx->scr->fractal_to_draw->zoom = 1.20;
}

int 	mouse_zoom(int button, int x, int y, t_mlx *mlx)
{
	t_fractal	*fractal;
	double		inter;

	zoom_factor(button, mlx);
	fractal = mlx->scr->fractal_to_draw;
	fractal->mouse.re = (double)x / (WIDTH / (fractal->max.re - fractal->min.re)) + fractal->min.re;
	fractal->mouse.im = ((double)y / (HEIGHT / (fractal->max.im - fractal->min.im)) * -1 + fractal->max.im);
	inter = 1.0 / fractal->zoom;
	fractal->min.re = interpolation(fractal->mouse.re, fractal->min.re, inter);
	fractal->min.im = interpolation(fractal->mouse.im, fractal->min.im, inter);
	fractal->max.re = interpolation(fractal->mouse.re, fractal->max.re, inter);
	fractal->max.im = interpolation(fractal->mouse.im, fractal->max.im, inter);
	refresh(mlx);
	return (0);
}

int 	mouse_events(int x, int y, t_mlx *mlx)
{
	t_fractal *fractal;

	fractal = mlx->scr->fractal_to_draw;
	if (fractal->mouse_block && ((ft_strequ("Julia", fractal->name) || fractal->id == julia) || (ft_strequ("Julia x4", fractal->name) || fractal->id == julia_x_4)))
	{
		fractal->julias_const.im = (y - (double)HEIGHT / 2) * (1.0 / (HEIGHT / 2.0));
		fractal->julias_const.re = (x - (double)WIDTH / 2) * (1.0 / (HEIGHT / 2.0));
		refresh(mlx);
	}
	return (0);
}