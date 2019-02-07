/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:29:20 by marvin            #+#    #+#             */
/*   Updated: 2019/02/07 17:30:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h" 

int main(void)
{
    t_fract *fractol;

    fractol = create_fractol();
    draw_fract(fractol);
    mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr, fractol->img_ptr, 0, 0);
	mlx_hook(fractol->win_ptr, 3, 0, &key_release, NULL);
    mlx_loop(fractol->mlx_ptr);
}
