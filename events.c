/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakbas <nakbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 03:29:44 by nakbas            #+#    #+#             */
/*   Updated: 2025/04/10 09:03:03 by nakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img.img);
	mlx_destroy_window(fractol->mlx, fractol->window);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractol *fractol)
{
	printf("Key pressed: %d\n", keysym);
	if (keysym == XK_Escape)
		close_handler(fractol);
	if (keysym == XK_Left)
		fractol->shift_x -= (0.2 * fractol->zoom);
	else if (keysym == XK_Right)
		fractol->shift_x += (0.2 * fractol->zoom);
	else if (keysym == XK_Up)
		fractol->shift_y += (0.2 * fractol->zoom);
	else if (keysym == XK_Down)
		fractol->shift_y -= (0.2 * fractol->zoom);
	else if (keysym == XK_q)
		fractol->iteration_max += 2;
	else if (keysym == XK_w)
		fractol->iteration_max -= 2;
	fractal_render(fractol);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractol *fractol)
{
	if (button == Button5)
	{
		fractol->zoom *= 0.95;
	}
	else if (button == Button4)
	{
		fractol->zoom *= 1.05;
	}
	fractal_render(fractol);
	return (0);
}

// int	julia_track(int x, int y, t_fractol *fractal)
// {
// 	if (fractal->name[0] == 'j')
// 	{
// 		fractal->julia_x = (map(x, -2, +2, 0, 799) * fractal->zoom) + fractal->shift_x;
// 		fractal->julia_y = (map(y, +2, -2, 0, 599) * fractal->zoom) + fractal->shift_y;
// 		fractal_render(fractal);
// 	}
// 	return 0;
// }