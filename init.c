/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 19:43:32 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/16 22:32:09 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fill_fractal_info(t_fractal *fractal, char *name, void (*func)(t_mlx *, t_fractal *), size_t id)
{
	fractal->name = ft_strdup(name);
	fractal->func = func;
	fractal->id = id;
	fractal->max_iters = 0;
	fractal->min.im = 0;
	fractal->min.re = 0;
	fractal->max.im = 0;
	fractal->max.re	= 0;
	fractal->mouse_x = 0.0;
	fractal->mouse_y = 0.0;
}

t_colors	*init_colors(void)
{
	t_colors *clr;

	clr = (t_colors *)ft_memalloc(sizeof(t_colors));
	clr->red = 0;
	clr->green = 0;
	clr->blue = 0;
	return (clr);
}

t_screen	*init_screen(void)
{
	t_screen *scr;

	if (!(scr = ft_memalloc(sizeof(t_screen))))
		return  (NULL);
	scr->colors = init_colors();
	scr->delta_red = 255;
	scr->delta_green = 0;
	scr->delta_blue = 0;
	fill_fractal_info(&scr->fractal[mandelbrot], "Mandelbrot", fractal_mandelbrot, 1);
	mandelbrot_start_conditions(&scr->fractal[mandelbrot]);
	return (scr);
}

t_mlx *init_mlx(void)
{
	t_mlx *mlx;

	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	mlx->mlx_ptr = mlx_init();
	mlx->scr = init_screen();
	mlx->scr->colors->red = 255;
	return (mlx);
}
