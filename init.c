/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 19:43:32 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/23 16:38:08 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fill_fractal_info(t_fractal *fractal, char *name, t_complex (*func)
			(t_fractal *), size_t id)
{
	fractal->name = ft_strdup(name);
	fractal->func = func;
	fractal->id = id;
	fractal->min.im = 0;
	fractal->min.re = 0;
	fractal->max.im = 0;
	fractal->max.re	= 0;
	fractal->max_iters = 20;
	fractal->win_h = HEIGHT;
	fractal->win_w = WIDTH;
	fractal->y_start = 0;
	fractal->x_start = 0;
	fractal->zoom = 1;
	fractal->y_end = fractal->win_h;
	fractal->x_end = fractal->win_w;
	ft_bzero((void *)fractal->rgb, 3);
	fractal->colors = init_colors();
}

t_colors	*init_colors(void)
{
	t_colors *clr;

	clr = (t_colors *)ft_memalloc(sizeof(t_colors));
	clr->delta_color = 32;
	clr->delta_red = 0xff;
	clr->delta_green = 0;
	clr->delta_blue = 0;
	clr->clr_mod = 25;
	return (clr);
}

t_screen	*init_screen(void)
{
	t_screen *scr;

	if (!(scr = ft_memalloc(sizeof(t_screen))))
		return  (NULL);
	fill_fractal_info(&scr->fractal[mandelbrot],
			"Mandelbrot", fractal_mandelbrot, mandelbrot);
	start_conditions(&scr->fractal[mandelbrot],
			-1.4, -2.0, 1.0);
	fill_fractal_info(&scr->fractal[julia],
			"Julia", fractal_julia, julia);
	start_conditions(&scr->fractal[julia],
			-2.0, -2.0, 2.0);
	fill_fractal_info(&scr->fractal[burning_ship],
			"Burning ship", fractal_burning_ship, burning_ship);
	start_conditions(&scr->fractal[burning_ship],
			-2.0, -2.0, 2.0);
	fill_fractal_info(&scr->fractal[tricorn],
			"Tricorn Mandelbrot", fractal_tricorn_mandelbrot, tricorn);
	start_conditions(&scr->fractal[tricorn],
			-2.0, -2.0, 2.0);
	fill_fractal_info(&scr->fractal[batman],
					  "Batman", fractal_batman, batman);
	start_conditions(&scr->fractal[batman],
					 -2.0, -2.0, 2.0);
	fill_fractal_info(&scr->fractal[mandelbrot_3_x],
					  "Mandelbrot x3", fractal_mandelbrot_3x, mandelbrot_3_x);
	start_conditions(&scr->fractal[mandelbrot_3_x],
					 -2.0, -2.0, 2.0);
	fill_fractal_info(&scr->fractal[celtic_mandelbrot],
					  "Celtic Mandelbrot", fractal_celtick_mandelbrot, celtic_mandelbrot);
	start_conditions(&scr->fractal[celtic_mandelbrot],
					 -2.0, -2.0, 2.0);
	fill_fractal_info(&scr->fractal[julia_x_4],
					  "Julia x4", fractal_custom, julia_x_4);
	start_conditions(&scr->fractal[julia_x_4],
					 -2.0, -2.0, 2.0);
	return (scr);
}

t_mlx *init_mlx(void)
{
	t_mlx *mlx;

	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	mlx->mlx_ptr = mlx_init();
	mlx->scr = init_screen();
	return (mlx);
}

void	init_drawing(t_mlx *mlx, char **fractals)
{
	if ((mlx->scr->fractal_to_draw = search_fractal_by_name(mlx->scr->fractal, *fractals))
		|| (mlx->scr->fractal_to_draw = search_fractal_by_id(mlx->scr->fractal, *fractals)))
	{
		mlx->mlx_window = mlx_new_window(mlx->mlx_ptr, WIDTH + 450, HEIGHT, "Fract-ol ablizniu");
		mlx->image_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
		mlx->data_buff = mlx_get_data_addr(mlx->image_ptr,
										   &mlx->bpp, &mlx->size_line, &mlx->endian);
		mlx->bpp /= 8;
		mlx->scr->fractal_to_draw->mlx = mlx;
	}
}