/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 21:56:32 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/24 12:16:32 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_bool	validation_id(int32_t argc, char **argv)
{
	size_t	i;
	int32_t	num;

	i = 0;
	while (i < MAX_FRACTALS_QUANT && i < (size_t)argc && *argv)
	{
		num = ft_atoi(argv[i]);
		if (num >= 0 && num < MAX_FRACTALS_QUANT)
			return (true);
		i++;
	}
	return (false);
}

t_bool	validation_name(t_fractal *fractal, int32_t argc, char **argv)
{
	size_t	i;

	i = 0;
	while (i < MAX_FRACTALS_QUANT && i < (size_t)argc && *argv)
	{
		if (ft_strequ(fractal[i].name, argv[i]))
			return (true);
		i++;
	}
	return (false);
}

t_bool	parse_flag_format(char *arg)
{
	size_t i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && arg[i] != '-')
			return (false);
		i++;
	}
	return (true);
}

void	parse_flag(t_mlx *mlx, char **argv, int32_t *index)
{
	int32_t		var;

	if (ft_strequ(argv[0], "-w"))
	{
		if (argv[1] && argv[2] &&
		parse_flag_format(argv[1]) && parse_flag_format(argv[2]))
		{
			if ((var = ft_atoi(argv[1])) < 0)
				print_error();
			mlx->h = (uint32_t)var;
			if ((var = ft_atoi(argv[2])) < 0)
				print_error();
			mlx->w = (uint32_t)var;
		}
		else
			print_error();
		*index = 4;
	}
	else
	{
		mlx->h = HEIGHT;
		mlx->w = WIDTH;
	}
}

int		main(int32_t argc, char **argv)
{
	t_mlx	*mlx;
	int32_t	index;

	index = argc - 1;
	if (argc >= 2)
	{
		mlx = init_mlx();
		parse_flag(mlx, &argv[1], &index);
		if (mlx && (validation_name(mlx->scr->fractal, argc - 1, &argv[index])
		|| validation_id(argc - 1, &argv[index])))
		{
			init_drawing(mlx, &argv[index]);
			main_drawing_func(mlx);
		}
	}
	print_usage();
	return (0);
}
