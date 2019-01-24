/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 19:43:32 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/24 12:15:36 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			fill_fractal_info(t_fractal *fractal,
				char *name, t_complex (*func)
				(t_fractal *), size_t id)
{
	fractal->name = ft_strdup(name);
	fractal->func = func;
	fractal->id = id;
	fractal->min.im = 0;
	fractal->min.re = 0;
	fractal->max.im = 0;
	fractal->max.re = 0;
	fractal->max_iters = 20;
	fractal->y_start = 0;
	fractal->x_start = 0;
	fractal->zoom = 1;
	fractal->y_end = fractal->win_h;
	fractal->x_end = fractal->win_w;
	ft_bzero((void *)fractal->rgb, 3);
	fractal->colors = init_colors();
}

t_colors		*init_colors(void)
{
	t_colors *clr;

	if (!(clr = (t_colors *)ft_memalloc(sizeof(t_colors))))
		return (NULL);
	clr->delta_color = 32;
	clr->delta_red = 0xff;
	clr->delta_green = 0;
	clr->delta_blue = 0;
	clr->clr_mod = 25;
	return (clr);
}

t_screen		*init_screen(void)
{
	t_screen	*scr;

	if (!(scr = (t_screen *)ft_memalloc(sizeof(t_screen))))
		return (NULL);
	fill_fractal_info(&scr->fractal[mandelbrot],
			"Mandelbrot", fractal_mandelbrot, mandelbrot);
	start_conditions(&scr->fractal[mandelbrot], -1.4, -2.0, 1.0);
	fill_fractal_info(&scr->fractal[julia],
			"Julia", fractal_julia, julia);
	start_conditions(&scr->fractal[julia], -2.0, -2.0, 2.0);
	fill_fractal_info(&scr->fractal[burning_ship],
			"Burning ship", fractal_burning_ship, burning_ship);
	start_conditions(&scr->fractal[burning_ship], -2.0, -2.0, 2.0);
	init_bonus_fractals(scr);
	return (scr);
}

t_mlx			*init_mlx(void)
{
	t_mlx		*mlx;

	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	mlx->mlx_ptr = mlx_init();
	mlx->scr = init_screen();
	return (mlx);
}

void			init_drawing(t_mlx *mlx, char **fractals)
{
	if ((mlx->scr->fractal_to_draw =
			search_fractal_by_name(mlx->scr->fractal, *fractals))
		|| (mlx->scr->fractal_to_draw =
				search_fractal_by_id(mlx->scr->fractal, *fractals)))
	{
		mlx->mlx_window = mlx_new_window(mlx->mlx_ptr,
				mlx->w + 450, mlx->h, "Fract-ol ablizniu");
		mlx->image_ptr = mlx_new_image(mlx->mlx_ptr, mlx->w, mlx->h);
		mlx->data_buff = mlx_get_data_addr(mlx->image_ptr,
						&mlx->bpp, &mlx->size_line, &mlx->endian);
		mlx->bpp /= 8;
		mlx->scr->fractal_to_draw->mlx = mlx;
		mlx->scr->fractal_to_draw->win_h = mlx->h;
		mlx->scr->fractal_to_draw->win_w = mlx->w;
	}
}
