/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 20:04:18 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/23 21:31:43 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "fractol_keys.h"
# include "mlx.h"
# include <math.h>
# include "pthread.h"

# define MAX_FRACTALS_QUANT 8
# define HEIGHT				800
# define WIDTH				800
# define COLOR_BLACK		0x000000
# define INDEX_RED			0
# define INDEX_GREEN		1
# define INDEX_BLUE			2

# define THREADS_NUMBER		12

typedef enum				e_name
{
	mandelbrot,
	julia,
	burning_ship,
	tricorn,
	batman,
	mandelbrot_3_x,
	celtic_mandelbrot,
	julia_x_4
}							t_name;

typedef	struct				s_complex
{
	double					im;
	double					re;
}							t_complex;

typedef struct				s_fractal
{
	t_bool					in_set;
	t_bool					mouse_block;
	int32_t					max_iters;
	size_t					id;
	double					zoom;
	double					x_start;
	double					y_start;
	double					x_end;
	double					y_end;
	double					win_h;
	double					win_w;
	struct s_colors			*colors;
	struct s_mlx			*mlx;
	char					*name;
	t_complex				min;
	t_complex				max;
	t_complex				factor;
	t_complex				c;
	t_complex				z;
	t_complex				mouse;
	t_complex				julias_const;
	t_complex				z_in_pow;
	t_complex				(*func)(struct s_fractal *);
	int32_t					rgb[3];
}							t_fractal;

typedef	struct				s_colors
{
	uint8_t					delta_color;
	uint8_t					clr_mod;
	int32_t					delta_red;
	int32_t					delta_green;
	int32_t					delta_blue;
}							t_colors;

typedef	struct				s_screen
{
	t_fractal				*fractal_to_draw;
	pthread_t				threads[THREADS_NUMBER];
	t_fractal				fractal[MAX_FRACTALS_QUANT];
}							t_screen;

typedef struct				s_mlx
{
	int32_t					bpp;
	int32_t					size_line;
	int32_t					endian;
	uint32_t				h;
	uint32_t				w;
	char					*data_buff;
	void					*mlx_ptr;
	void					*mlx_window;
	void					*image_ptr;
	t_screen				*scr;
}							t_mlx;

/*
** Init
*/
t_colors					*init_colors(void);

t_mlx						*init_mlx(void);

void						init_drawing(t_mlx *mlx, char **fractals);

void						start_conditions(t_fractal *fractal, double min_im,
							double min_re, double max_re);
void						fill_fractal_info(t_fractal *fractal, char *name,
							t_complex (*func)(t_fractal *), size_t id);
void						init_bonus_fractals(t_screen *scr);
/*
** Validation
*/
void						parse_flag(t_mlx *mlx, char **argv, int32_t *index);

t_bool						parse_flag_format(char *arg);

t_bool						validation_id(int32_t argc, char **argv);

t_bool						validation_name(t_fractal *fractal,
							int32_t argc, char **argv);

t_fractal					*search_fractal_by_name(t_fractal *fractal,
							char *name);

t_fractal					*search_fractal_by_id(t_fractal *fractal,
							char *name);
/*
** Utils math
*/
double						interpolation(double start,
											double end, double interpolation);

void						calculate_func_iter(t_mlx *mlx, t_fractal *fractal,
							t_complex (*func)(t_fractal *), int32_t *color);
/*
** Fractals formula
*/
t_complex					fractal_custom(t_fractal *fractal);

t_complex					fractal_celtick_mandelbrot(t_fractal *fractal);

t_complex					fractal_mandelbrot_3x(t_fractal *fractal);

t_complex					fractal_batman(t_fractal *fractal);

t_complex					fractal_tricorn_mandelbrot(t_fractal *fractal);

t_complex					fractal_burning_ship(t_fractal *fractal);

t_complex					fractal_julia(t_fractal *fractal);

t_complex					fractal_mandelbrot(t_fractal *fractal);
/*
** Print
*/
void						print_info(t_mlx *mlx);

void						print_usage(void);

void						print_error(void);

void						info(t_mlx *mlx);
/*
** Drawing utils
*/
void						main_drawing_func(t_mlx *mlx);

void						*fractal(t_fractal *fractal);

void						modify_conditions(t_mlx *mlx);

void						put_image(t_mlx *mlx, int x, int y, int color);

int							refresh(t_mlx *mlx);

void						clear(t_mlx *mlx);
/*
** Colors
*/
void						colors(t_fractal *fractal, size_t iter,
							int32_t *color);

void						calculate_color(int32_t *color, int32_t delta,
											t_bool sign);
/*
** Mouse hooks and utils
*/
int							mouse_zoom(int button, int x, int y, t_mlx *mlx);

int							mouse_events(int x, int y, t_mlx *mlx);
/*
** Key hooks and utils
*/
int							key_events(int keycode, t_mlx *mlx);

void						key_events_color(t_mlx *mlx, int keycode);

void						change_fractal_further(t_mlx *mlx);

void						change_fractal_back(t_mlx *mlx);

void						change_iter(t_mlx *mlx, t_bool sign);

void						reset_fractal(t_mlx *mlx);

void						key_events_change_fractals(t_mlx *mlx, int keycode);
/*
** Free
*/
void						free_memmory(t_mlx *mlx);
/*
** Threads
*/
void						create_threads(t_mlx *mlx);

#endif
