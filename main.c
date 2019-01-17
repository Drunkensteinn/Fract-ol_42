/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 21:56:32 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/14 17:49:05 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_bool	validation_id(int32_t argc, char **argv)
{
	size_t	i;
	int32_t	num;

	i = 0;
	while (i < MAX_FRACTALS_QUANT && i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num <= 0 && num > MAX_FRACTALS_QUANT)
			return (false);
		i++;
	}
	return (true);
}

t_bool	validation_name(t_fractal *fractal, int32_t argc, char **argv)
{
	size_t	i;

	i = 0;
	while (i < MAX_FRACTALS_QUANT && i < argc)
	{
		if (!ft_strequ(fractal[i].name, argv[i]))
			return (false);
		i++;
	}
	return (true);
}

int		main(int32_t argc, char **argv)
{
	t_mlx *mlx;

	if (argc >= 2)
	{
		mlx = init_mlx();
		if (mlx && (validation_name(mlx->scr->fractal, argc - 1, &argv[1])
		|| validation_id(argc - 1, &argv[1])))
		{
			init_drawing(mlx, argc - 1, &argv[1]);
		}
	}
	else
		print_usage();
	return (0);
}