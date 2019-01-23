/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:05:28 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/22 20:51:25 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline void calculate_func_iter(t_mlx *mlx, t_fractal *fractal, t_complex (*func)(t_fractal *), int32_t *color)
{
	size_t	i;

	i = 0;
	while (i < fractal->max_iters)
	{
		fractal->z_in_pow.re = FT_POW(fractal->z.re);
		fractal->z_in_pow.im = FT_POW(fractal->z.im);
		if (fractal->z_in_pow.re + fractal->z_in_pow.im > 4)
		{
			fractal->in_set = false;
			colors(fractal, i, color);
			break;
		};
		fractal->z.im = func(fractal).im;
		fractal->z.re = func(fractal).re;
		put_image(mlx, (int)fractal->x_start, (int)fractal->y_start, *color);
		i++;
	}
	if (fractal->in_set == true)
		put_image(mlx, (int)fractal->x_start, (int)fractal->y_start, COLOR_BLACK);
}

inline void *fractal(t_fractal *fractal)
{
	t_mlx *mlx;
	int32_t color;

	mlx = fractal->mlx;
	while (fractal->y_start < fractal->y_end)
	{
		fractal->x_start = 0;
		fractal->c.im = fractal->max.im - fractal->y_start * fractal->factor.im;
		while (fractal->x_start < fractal->x_end)
		{
			fractal->c.re = fractal->min.re + fractal->x_start * fractal->factor.re;
			fractal->in_set = true;
			fractal->z.re = fractal->c.re;
			fractal->z.im = fractal->c.im;
			calculate_func_iter(mlx, fractal, fractal->func, &color);
			fractal->x_start++;
		}
		fractal->y_start++;
	}
	return (NULL);
}