/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakbas <nakbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:35:43 by nakbas            #+#    #+#             */
/*   Updated: 2025/04/10 07:02:47 by nakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

#define ERROR_MESSAGE "Please enter \n\t\" ./fractol mandelbrot \" \n\t\" ./fractol julia (value_1) (value_2) \" "

#define BLACK		0x000000
#define WHITE		0xFFFFFF
#define RED			0xFF0000
#define GREEN		0x00FF00
#define BLUE		0x0000FF

#define MAGENTA_BURST		0xFF00FF
#define LIME_SHOCK			0xCCFF00
#define NEON_ORANGE			0xFF6600
#define PSYCHEDELIC_PURPLE 	0x660066
#define AQUA_DREAM			0x33CCCC
#define HOT_PINK        	0xFF66B2
#define ELECTRIC_BLUE   	0x0066FF
#define LAVA_RED        	0xFF3300

typedef struct s_complex
{
	double  real;
	double  imaginary;
}				t_complex;

typedef struct  s_img
{
	void	*img; // mlx_new_image()
	char	*addr_pixel; // mlx_get_data_addr()
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_fractol
{
	char	*name;
	void	*mlx; // mlx_init()
	void	*window; // mlx_new_window()
	t_img    img; // mlx_new_image()
	int		iteration_max;
	double	shift_x;
	double	shift_y;
	double 	zoom;
	double  julia_x;
	double  julia_y;
}				t_fractol;

int     	ft_strncmp(char *s1, char *s2);
void    	fractal_init(t_fractol *fractol);
double		map(double unscaled_num, double new_min, double new_max,
				double old_min, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
void		fractal_render(t_fractol *fractol);
int			key_handler(int keysym, t_fractol *fractol);
static void	events_init(t_fractol *fractol);
int			close_handler(t_fractol *fractol);
int			mouse_handler(int button, int x, int y, t_fractol *fractol);
double		atodbl(char *s);
int			julia_track(int x, int y, t_fractol *fractal);

#endif
