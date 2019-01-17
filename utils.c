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