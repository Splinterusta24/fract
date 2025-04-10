/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakbas <nakbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:02:51 by nakbas            #+#    #+#             */
/*   Updated: 2025/04/10 09:02:52 by nakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char **argv)
{
	t_fractol fractol;
	if ((argc == 2 && argv[1][0] == 'm')
		|| (argc == 4 && argv[1][0] == 'j'))
	{
		fractol.name = argv[1];
		if (argv[1][0] == 'j')
		{
			fractol.julia_x = atodbl(argv[2]);
			fractol.julia_y = atodbl(argv[3]);
		}
		fractal_init(&fractol);
		fractal_render(&fractol);
		mlx_loop(fractol.mlx);
	}
	else
	{
		write(2, ERROR_MESSAGE, sizeof(ERROR_MESSAGE));
		exit (EXIT_FAILURE);
	}
	return (0);
}
