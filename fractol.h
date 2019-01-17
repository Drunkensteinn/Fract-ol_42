/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 20:04:18 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/17 14:24:49 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include	"libft/libft.h"
#include	"mlx.h"

#define		MAX_FRACTALS_QUANT 8
#define		HEIGHT	1200
#define		WIDTH	1200

#define		CLR_MOD 16

typedef struct	s_mlx	t_mlx;

typedef enum	e_name
{
	mandelbrot,
	julia,
	burningship
}				s_name;

typedef	struct		s_complex
{
	double			im;
	double			re;
}					t_complex;

typedef struct 		s_fractal
{
	char			*name;
	size_t			id;
	t_complex		min;
	t_complex		max;
	t_complex		factor;

	t_complex		c;
	t_complex		z;

	double			x;
	double			y;

	t_complex		z_in_pow;

	t_bool			in_set;

	size_t 			max_iters;
	double			mouse_x;
	double			mouse_y;

	void			(*func)(t_mlx *mlx, struct s_fractal *);
}					t_fractal;

typedef	struct		s_colors
{
	int32_t	red;
	int32_t	green;
	int32_t	blue;
}					t_colors;

typedef	struct		s_screen
{
	t_fractal fractal[MAX_FRACTALS_QUANT];

	uint32_t			color;
	uint32_t			delta;

	t_colors			*colors;

	int32_t				delta_red;
	int32_t				delta_green;
	int32_t				delta_blue;

	int32_t				start_condition;

}					t_screen;

struct				s_mlx
{
	char			*data_buff;
	void			*mlx_ptr;
	void			*mlx_window[MAX_FRACTALS_QUANT];
	void			*image_ptr;
	int32_t			bpp;
	int32_t			size_line;
	int32_t			endian;
	t_screen		*scr;
};

void				print_usage(void);

t_mlx				*init_mlx(void);

void				fractal_mandelbrot(t_mlx *mlx, t_fractal *fractal);

void				init_drawing(t_mlx *mlx, int32_t quant, char **fractals);

t_fractal			*search_fractal_by_name(t_fractal *fractal, char *name);

t_fractal			*search_fractal_by_id(t_fractal *fractal, char *name);

void				mandelbrot_start_conditions(t_fractal *fractal);

void				calculate_func_iter(t_mlx *mlx, t_fractal *fractal);

void				put_image(t_mlx *mlx, int x, int y, int color);

void				colors(t_mlx *mlx, size_t iter);

#endif
