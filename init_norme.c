/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_norme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:28:43 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/23 21:35:19 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_bonus_fractals(t_screen *scr)
{
	fill_fractal_info(&scr->fractal[tricorn],
			"Tricorn Mandelbrot", fractal_tricorn_mandelbrot, tricorn);
	start_conditions(&scr->fractal[tricorn], -2.0, -2.0, 2.0);
	fill_fractal_info(&scr->fractal[batman],
			"Batman", fractal_batman, batman);
	start_conditions(&scr->fractal[batman], -2.0, -2.0, 2.0);
	fill_fractal_info(&scr->fractal[mandelbrot_3_x],
			"Mandelbrot x3", fractal_mandelbrot_3x, mandelbrot_3_x);
	start_conditions(&scr->fractal[mandelbrot_3_x], -2.0, -2.0, 2.0);
	fill_fractal_info(&scr->fractal[celtic_mandelbrot],
			"Celtic Mandelbrot", fractal_celtick_mandelbrot, celtic_mandelbrot);
	start_conditions(&scr->fractal[celtic_mandelbrot], -2.0, -2.0, 2.0);
	fill_fractal_info(&scr->fractal[julia_x_4],
			"Julia x4", fractal_custom, julia_x_4);
	start_conditions(&scr->fractal[julia_x_4], -2.0, -2.0, 2.0);
}
