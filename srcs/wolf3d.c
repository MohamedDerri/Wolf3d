/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 03:40:39 by mderri            #+#    #+#             */
/*   Updated: 2019/11/22 03:40:41 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int argc, char **argv)
{
	t_wolf      w;

	if (argc != 2)
	{
		ft_putstr("Usage : ./wolf3d labyrinthe\n");
		exit(0);
	}
	w.name = ft_strdup("WOLF3D - mderri && slaanani");
	w.obj_list = parsing(argv[1], &w);
	w.head = w.obj_list;
	w.m.ptr = mlx_init();
	w.m.win = mlx_new_window(w.m.ptr, w.m.w, w.m.h, w.name);
	w.m.d.img_ptr = mlx_new_image(w.m.ptr, w.m.w, w.m.h);
	w.m.d.pic_str = (int *)mlx_get_data_addr(w.m.d.img_ptr, &w.m.d.bpp,
&w.m.d.s_l, &w.m.d.endian);
	raycaster(&w);
	mlx_put_image_to_window(w.m.ptr, w.m.win, w.m.d.img_ptr, 0, 0);
	mlx_hook(w.m.win, 2, 1, event_handle, &w.m);
	mlx_hook(w.m.win, 17, 1, ft_close, &w.m);
	mlx_loop(w.m.ptr);
	return (0);
}
