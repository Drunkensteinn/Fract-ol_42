/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_fractals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 21:47:16 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/22 17:25:43 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline t_complex fractal_mandelbrot(t_fractal *fractal)
{
	t_complex constanta;

	constanta.im = 2 * fractal->z.re * fractal->z.im + fractal->c.im;
	constanta.re = fractal->z_in_pow.re - fractal->z_in_pow.im + fractal->c.re;
	return (constanta);
}

inline t_complex fractal_julia(t_fractal *fractal)
{
	t_complex constanta;

	constanta.im = 2 * fractal->z.re * fractal->z.im + fractal->julias_const.im;
	constanta.re = fractal->z_in_pow.re - fractal->z_in_pow.im + fractal->julias_const.re;
	return (constanta);
}

inline t_complex fractal_burning_ship(t_fractal *fractal)
{
	t_complex constanta;

	constanta.im = -2 * FT_ABS(fractal->z.re * fractal->z.im) + fractal->c.im;
	constanta.re = fractal->z_in_pow.re - fractal->z_in_pow.im + fractal->c.re;
	return (constanta);
}