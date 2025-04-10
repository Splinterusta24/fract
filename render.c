/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakbas <nakbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:49:30 by nakbas            #+#    #+#             */
/*   Updated: 2025/04/10 07:21:47 by nakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int 		offset;

	offset = (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr_pixel + offset) = color;
}

static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractol *fractal)
{	
	if (fractal->name[0] == 'j')
	{
		c->real = fractal->julia_x;
		c->imaginary = fractal->julia_y;
	}
	else
	{
		c->real = z->real;
		c->imaginary = z->imaginary;
	}
}

void	handle_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	// z.real = 0.0;
	// z.imaginary = 0.0;

	z.real = (map(x, -2, +2, 0, 799) * fractol->zoom) + fractol->shift_x;
	z.imaginary = (map(y, +2, -2, 0, 599) * fractol->zoom) + fractol->shift_y;

	mandel_vs_julia(&z, &c, fractol);

	while (i < fractol->iteration_max)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real) + (z.imaginary * z.imaginary) > 4)
		{
			color = map(i, BLACK, WHITE, 0, fractol->iteration_max);
			my_pixel_put(x, y, &fractol->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractol->img, WHITE);
}

void	fractal_render(t_fractol *fractol)
{
	int		x;
	int		y;
	
	y = -1;
	while (++y < 599)
	{
		x = -1;
		while (++x < 799)
		{
			handle_pixel(x, y, fractol);
		}
	}
	mlx_put_image_to_window(fractol->mlx, fractol->window,
							fractol->img.img, 0, 0);
}
