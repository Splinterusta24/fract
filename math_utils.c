/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakbas <nakbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:56:23 by nakbas            #+#    #+#             */
/*   Updated: 2025/04/10 06:55:59 by nakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		map(double unscaled_num, double new_min, double new_max,
		double old_min, double old_max)
{
	//return ((unscaled_num - old_min) * (new_max - new_min) / (old_max - old_min) + new_min);
	return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;

}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.real = z1.real + z2.real;
	result.imaginary = z1.imaginary + z2.imaginary;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.real = (z.real * z.real) - (z.imaginary * z.imaginary);
	result.imaginary = 2 * z.real * z.imaginary;
	return (result);
}
