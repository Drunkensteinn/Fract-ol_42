/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:09:24 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/14 17:31:59 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal	*search_fractal_by_name(t_fractal *fractal, char *name)
{
	size_t i;

	i = 0;
	while (i < MAX_FRACTALS_QUANT)
	{
		if (ft_strequ(name, fractal[i].name))
			return (&fractal[i]);
		i++;
	}
	return (NULL);
}

t_fractal	*search_fractal_by_id(t_fractal *fractal, char *id)
{
	size_t i;

	i = 0;
	while (i < MAX_FRACTALS_QUANT)
	{
		if (ft_atoi(id) == fractal[i].id)
			return (&fractal[i]);
		i++;
	}
	return (NULL);
}

inline void start_conditions(t_fractal *fractal, double min_im, double min_re, double max_re)
{
	double w;
	double h;

	w = fractal->win_w;
	h = fractal->win_h;
	fractal->min.im = min_im;
	fractal->min.re = min_re;
	fractal->max.re	= max_re;
	fractal->max.im = (fractal->min.im + (fractal->max.re - fractal->min.re) * h/w);
	fractal->factor.im = (fractal->max.im - fractal->min.im) / (h - 1.0);
	fractal->factor.re = (fractal->max.re - fractal->min.re) / (w - 1.0);
	fractal->in_set = true;
}

double interpolation(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation)); // stolen from inet - refactor;
}