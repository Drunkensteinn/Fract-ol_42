/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 19:42:58 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/24 12:15:36 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			print_usage(void)
{
	ft_putstr("Usage: ./Fract-ol <fractal>.....\n");
	ft_putstr("\t\t '-w'[H][W] options gives to you"
	"a possibility to change window "
	"params;\n");
	ft_putstr("Available fractals : \n\t1) Mandelbrot - '0'\n\t2) Julia - '1'"
	"\n\t3) Burning ship - '2'\n\t4) Tricorn Mandelbrot - '3'\n\t"
	"5) Batman - '4'\n\t6) Mandelbrot x3 - '5'\n\t"
	"7) Celtic Mandelbrot - '6'\n\t8) Julia x4 - '7'\n");
}

void			print_error(void)
{
	ft_putstr("Invalid window parameters\n");
	exit(0);
}

inline void		print_info(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, 5 + mlx->w, 5, 0xffffff,
			"1) Movement : ARROWS");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, 5 + mlx->w, 25, 0xffffff,
			"2) Zoom/Action : MOUSE_WHEEL/LEFT_MB");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, 5 + mlx->w, 45, 0xffffff,
			"3) Mouse lock : SPACE");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, 5 + mlx->w, 65, 0xffffff,
			"4) Change iter +/- : 1/2");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, 5 + mlx->w, 85, 0xffffff,
			"5) Reset fractal : R");
	mlx_string_put(mlx->mlx_ptr,
			mlx->mlx_window, 5 + mlx->w, 105, 0xffffff,
			"6) Color specters : ");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window,
			5 + mlx->w, 125, 0xff0000, "    RED    ");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window,
			5 + mlx->w + 100, 125, 0xffffff, "ON/OFF : NUM_1/NUM_4 ");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window,
			5 + mlx->w, 145, 0x00ff00, "    GREEN  ");
	info(mlx);
}

inline void		info(t_mlx *mlx)
{
	char		*temp;

	temp = ft_itoa(mlx->scr->fractal_to_draw->max_iters);
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window,
			5 + mlx->w + 100, 145, 0xffffff, "ON/OFF : NUM_2/NUM_5 ");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window,
			5 + mlx->w, 165, 0x0000ff, "    BLUE   ");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window,
			5 + mlx->w + 100, 165, 0xffffff, "ON/OFF : NUM_3/NUM_3 ");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, 5 + mlx->w, 185, 0xffffff,
			"7) Drawing density : Q/W");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, 5 + mlx->w, 205, 0xffffff,
			"8) Color depth : A/S");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, 5 + mlx->w, 225, 0xffffff,
			"9) Change fractal : Z/X");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, 5 + mlx->w, 245, 0xffffff,
			"Current func iter : ");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window,
			5 + mlx->w + 200, 245, 0xffffff,
			temp);
	ft_strdel(&temp);
}
