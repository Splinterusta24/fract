/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakbas <nakbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:33:17 by nakbas            #+#    #+#             */
/*   Updated: 2025/04/10 09:02:56 by nakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	data_init(t_fractol *fractal)
{
	fractal->iteration_max = 42; 
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void	events_init(t_fractol *fractol)
{
	mlx_hook(fractol->window, KeyPress,  KeyPressMask, key_handler, fractol);
	mlx_hook(fractol->window, ButtonPress, ButtonPressMask, mouse_handler, fractol);
	mlx_hook(fractol->window, DestroyNotify, StructureNotifyMask, close_handler, fractol);
	//mlx_hook(fractol->window, MotionNotify, PointerMotionMask, julia_track, fractol);
}

void	fractal_init(t_fractol *fractol)
{
	fractol->mlx = mlx_init(); //mlx'i başlatır
	if (fractol->mlx == NULL)
	{
		write(2, "Error: mlx_init failed\n", 23);
		exit(EXIT_FAILURE);
	}
	fractol->window = mlx_new_window(fractol->mlx, 799, 599, "Fractol");
	if (fractol->window == NULL)
	{
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		write(2, "Error: mlx_new_window failed\n", 30); mlx_ptr:
		exit(EXIT_FAILURE);
	}
	fractol->img.img = mlx_new_image(fractol->mlx, 799, 599);
	if (fractol->img.img == NULL)
	{
		mlx_destroy_window(fractol->mlx, fractol->window);
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		write(2, "Error: mlx_new_image failed\n", 30);
		exit(EXIT_FAILURE);
	}
	fractol->img.addr_pixel = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_per_pixel, &fractol->img.line_length,
			&fractol->img.endian);
	events_init(fractol);
	data_init(fractol);
}
