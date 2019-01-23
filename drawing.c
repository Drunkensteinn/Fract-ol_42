/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 19:43:54 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/23 21:41:29 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline void		clear(t_mlx *mlx)
{
	ft_bzero(mlx->data_buff, mlx->h * mlx->w * 4);
	mlx_clear_window(mlx->mlx_ptr, mlx->mlx_window);
}

inline void		put_image(t_mlx *mlx, int x, int y, int color)
{
	if ((x >= 0 && x < (int)mlx->scr->fractal_to_draw->win_w) &&
	(y >= 0 && y < (int)mlx->scr->fractal_to_draw->win_h))
		*(int *)(mlx->data_buff +
		(y * (int)mlx->scr->fractal_to_draw->win_h + x) * mlx->bpp) = color;
}

void			create_threads(t_mlx *mlx)
{
	t_fractal	temp[THREADS_NUMBER];
	size_t		i;

	i = 0;
	modify_conditions(mlx);
	while (i < THREADS_NUMBER)
	{
		temp[i] = *mlx->scr->fractal_to_draw;
		temp[i].x_start = 0;
		temp[i].x_end = mlx->scr->fractal_to_draw->win_w;
		temp[i].y_start = mlx->scr->fractal_to_draw->win_h /
				THREADS_NUMBER * i;
		temp[i].y_end = mlx->scr->fractal_to_draw->win_h /
				THREADS_NUMBER * (i + 1);
		pthread_create(&mlx->scr->threads[i], NULL,
				(void *)fractal, (void *)&temp[i]);
		i++;
	}
	i = 0;
	while (i < THREADS_NUMBER)
	{
		pthread_join(mlx->scr->threads[i], NULL);
		i++;
	}
}

inline int		refresh(t_mlx *mlx)
{
	clear(mlx);
	create_threads(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window,
			mlx->image_ptr, 0, 0);
	print_info(mlx);
	return (0);
}

void			main_drawing_func(t_mlx *mlx)
{
	mlx_expose_hook(mlx->mlx_window, refresh, mlx);
	mlx_hook(mlx->mlx_window, 4, 1L << 2, mouse_zoom, mlx);
	mlx_hook(mlx->mlx_window, 6, 1L << 6, mouse_events, mlx);
	mlx_hook(mlx->mlx_window, 2, 5, key_events, mlx);
	mlx_do_sync(mlx->mlx_ptr);
	mlx_loop(mlx->mlx_ptr);
}
