/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 19:43:54 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/16 13:31:43 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	draw(t_mlx *mlx, t_fractal *fractal)
{
	fractal->func(mlx,fractal);
}

inline void	put_image(t_mlx *mlx, int x, int y, int color)
{
	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
		*(int *)(mlx->data_buff + (y * HEIGHT + x) * mlx->bpp) = color;
}

void	init_drawing(t_mlx *mlx, int32_t quant, char **fractals)
{
	t_fractal	*temp;
	size_t		i;

	i = 0;
	while (i < quant)
	{
		if ((temp = search_fractal_by_name(mlx->scr->fractal, fractals[i]))
			|| (temp = search_fractal_by_id(mlx->scr->fractal, fractals[i])))
		{
			mlx->mlx_window[i] = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, temp->name);
			mlx->image_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
			mlx->data_buff = mlx_get_data_addr(mlx->image_ptr,
											   &mlx->bpp, &mlx->size_line, &mlx->endian);
			mlx->bpp /= 8;
			draw(mlx, temp);
		}
		i++;
	}
}

