/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:44:59 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/20 19:08:49 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline void		calculate_color(int32_t *color, int32_t delta, t_bool sign)
{
	delta %= 0xff;
	if (sign)
	{
		*color += delta;
		if (*color > 0xff)
			*color = 0xff;
	}
	else
	{
		*color -= delta;
		if (*color < 0)
			*color = 0;
	}
}

inline void colors(t_fractal *fractal, size_t iter, int32_t *color)
{
	size_t i;

	i = 0;
	iter %= (fractal->colors->clr_mod) + 1;
	fractal->rgb[INDEX_RED] = fractal->colors->delta_red;
	fractal->rgb[INDEX_GREEN] = fractal->colors->delta_green;
	fractal->rgb[INDEX_BLUE] = fractal->colors->delta_blue;
	if (fractal->colors->delta_color == UINT8_MAX)
		fractal->colors->delta_color = 1;
	while (i < iter)
	{
		if (fractal->rgb[INDEX_RED] && !fractal->rgb[INDEX_BLUE] && fractal->rgb[INDEX_RED] > fractal->rgb[INDEX_GREEN])
			calculate_color(&fractal->rgb[INDEX_GREEN], fractal->colors->delta_color, true);
		else if (fractal->rgb[INDEX_GREEN] && fractal->rgb[INDEX_RED] && !fractal->rgb[INDEX_BLUE])
			calculate_color(&fractal->rgb[INDEX_RED], fractal->colors->delta_color, false);
		else if (fractal->rgb[INDEX_GREEN] && !fractal->rgb[INDEX_RED] && fractal->rgb[INDEX_GREEN] > fractal->rgb[INDEX_BLUE])
			calculate_color(&fractal->rgb[INDEX_BLUE], fractal->colors->delta_color, true);
		else if (fractal->rgb[INDEX_BLUE] && fractal->rgb[INDEX_GREEN] && !fractal->rgb[INDEX_RED])
			calculate_color(&fractal->rgb[INDEX_GREEN], fractal->colors->delta_color, false);
		else if (fractal->rgb[INDEX_BLUE] && !fractal->rgb[INDEX_GREEN] && fractal->rgb[INDEX_RED] < fractal->rgb[INDEX_BLUE])
			calculate_color(&fractal->rgb[INDEX_RED], fractal->colors->delta_color, true);
		else if (fractal->rgb[INDEX_BLUE] && !fractal->rgb[INDEX_GREEN] && fractal->rgb[INDEX_RED] >= fractal->rgb[INDEX_BLUE])
			calculate_color(&fractal->rgb[INDEX_BLUE], fractal->colors->delta_color, false);
		i++;
	}
	*color = (uint32_t)(fractal->rgb[INDEX_RED] << 16 | fractal->rgb[INDEX_GREEN] << 8 | fractal->rgb[INDEX_BLUE]);
}
