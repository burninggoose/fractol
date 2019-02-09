/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:29:20 by marvin            #+#    #+#             */
/*   Updated: 2019/02/09 19:34:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>

int	draw_on_update(t_fract *fractal)
{
	t_pixel *start;
	t_pixel *end;

	start = NULL;
	end = NULL;
	if (fractal->updated)
	{
		start = create_pixel(0, 0, 0);
		end = create_pixel(W, H, 0);
		calculate_zone(fractal, start, end);
		mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr,
								fractal->img_ptr, 0, 0);
		fractal->updated = 0;
	}
	if (start)
		free(start);
	if (end)
		free(end);
	return (0);
}

int	print_usage(void)
{
	ft_putendl("usage:\n\t./fractol [mandelbroot, julia, burningship]");
	return (0);
}

int	main(int argc, char **argv)
{
	t_fract *fractol;

	if (argc == 1 || (ft_strcmp(argv[1], "mandelbroot")
						&& ft_strcmp(argv[1], "julia")
						&& ft_strcmp(argv[1], "burningship")))
		return (print_usage());
	fractol = create_fractol(argv[1]);
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
							fractol->img_ptr, 0, 0);
	mlx_loop_hook(fractol->mlx_ptr, &draw_on_update, fractol);
	mlx_hook(fractol->win_ptr, 2, 0, &key_press, fractol);
	mlx_hook(fractol->win_ptr, 4, 0, &mouse_release, fractol);
	mlx_hook(fractol->win_ptr, 3, 0, &key_release, NULL);
	mlx_loop(fractol->mlx_ptr);
}
