/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:15:38 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/23 21:42:35 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_memmory(t_mlx *mlx)
{
	size_t	i;

	i = 0;
	while (i < MAX_FRACTALS_QUANT)
	{
		ft_strdel(&mlx->scr->fractal[i].name);
		ft_memdel((void **)&mlx->scr->fractal[i].colors);
		i++;
	}
	ft_memdel((void **)&mlx->scr);
	ft_memdel((void **)&mlx);
}
