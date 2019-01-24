/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_fractals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 20:56:40 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/24 12:15:36 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

inline t_complex	fractal_tricorn_mandelbrot(t_fractal *fractal)
{
	t_complex	constanta;

	constanta.im = -2 * fractal->z.re * fractal->z.im + fractal->c.im;
	constanta.re = fractal->z_in_pow.re - fractal->z_in_pow.im + fractal->c.re;
	return (constanta);
}

inline t_complex	fractal_batman(t_fractal *fractal)
{
	t_complex	constanta;

	constanta.re = (fractal->z.im * fractal->z.im -
			fractal->z.re * fractal->z.re) + fractal->c.re;
	constanta.im = (5 * fractal->z.im) * fractal->z.re + fractal->c.im;
	return (constanta);
}

inline t_complex	fractal_mandelbrot_3x(t_fractal *fractal)
{
	t_complex	constanta;

	constanta.im = 4 * fractal->z.re * fractal->z.im *
			(fractal->z_in_pow.re - fractal->z_in_pow.im) + fractal->c.im;
	constanta.re = (fractal->z_in_pow.re * fractal->z_in_pow.re +
			fractal->z_in_pow.im * fractal->z_in_pow.im) - 6 *
					fractal->z_in_pow.re * fractal->z_in_pow.im +
					fractal->c.re;
	return (constanta);
}

inline t_complex	fractal_celtick_mandelbrot(t_fractal *fractal)
{
	t_complex	constanta;

	constanta.im = 2.0 * fractal->z.re * fractal->z.im + fractal->c.im;
	constanta.re = FT_ABS(fractal->z_in_pow.re -
			fractal->z_in_pow.im) + fractal->c.re;
	return (constanta);
}

inline t_complex	fractal_custom(t_fractal *fractal)
{
	t_complex	constanta;

	constanta.im = 4 * fractal->z.re * fractal->z.im *
			(fractal->z_in_pow.re - fractal->z_in_pow.im) +
			fractal->julias_const.im;
	constanta.re = (fractal->z_in_pow.re * fractal->z_in_pow.re +
			fractal->z_in_pow.im * fractal->z_in_pow.im) - 6 *
					fractal->z_in_pow.re * fractal->z_in_pow.im +
					fractal->julias_const.re;
	return (constanta);
}
