/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 21:47:16 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/16 22:48:19 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_start_conditions(t_fractal *fractal)
{
	fractal->min.im = -1.4;
	fractal->min.re = -2.0;
	fractal->max.re	= 1.0;
	fractal->max.im = fractal->min.im + (fractal->max.re - fractal->min.re) * HEIGHT/WIDTH;
	fractal->max_iters = 10;
	fractal->factor.im = (fractal->max.im - fractal->min.im) / (HEIGHT - 1);
	fractal->factor.re = (fractal->max.re - fractal->min.re) / (WIDTH - 1);
	fractal->mouse_x = 0.0;
	fractal->mouse_y = 0.0;
	fractal->in_set = true;
}

inline void	calculate_func_iter(t_mlx *mlx, t_fractal *fractal)
{
	size_t	i;

	i = 0;
	while (i < fractal->max_iters + 100)
	{
		fractal->z_in_pow.re = FT_POW(fractal->z.re);
		fractal->z_in_pow.im = FT_POW(fractal->z.im);
		if (fractal->z_in_pow.re + fractal->z_in_pow.im > 4)
		{
			fractal->in_set = false;
			colors(mlx, i);
			break;
		}
		fractal->z.im = 2 * fractal->z.re * fractal->z.im + fractal->c.im;
		fractal->z.re = fractal->z_in_pow.re - fractal->z_in_pow.im + fractal->c.re;
		put_image(mlx, (int) fractal->x, (int) fractal->y, mlx->scr->color);
		i++;
	}
	if (fractal->in_set == true)
		put_image(mlx, (int)fractal->x, (int)fractal->y, 0x000000);

}

void	fractal_mandelbrot(t_mlx *mlx, t_fractal *fractal)
{
	while (fractal->y < HEIGHT)
	{
		fractal->x = 0;
		fractal->c.im = fractal->max.im - fractal->y * fractal->factor.im;
		while (fractal->x < WIDTH)
		{
			fractal->c.re = fractal->min.re + fractal->x * fractal->factor.re;
			fractal->in_set = true;
			fractal->z.re = fractal->c.re;
			fractal->z.im = fractal->c.im;
			calculate_func_iter(mlx, fractal);
			fractal->x++;
		}
		fractal->y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window[mandelbrot],mlx->image_ptr, 0,0);
	mlx_do_sync(mlx->mlx_ptr);
	mlx_loop(mlx->mlx_ptr);
}


