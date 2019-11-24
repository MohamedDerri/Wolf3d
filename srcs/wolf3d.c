/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 03:40:39 by mderri            #+#    #+#             */
/*   Updated: 2019/11/22 22:02:12 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

// void	raycaster(t_wolf *w)
// {
// 	int x = 0;
// 	int y = 0;
// 	w->hit = 0;
// 	double newx;
// 	double h_factor;
// 	int		z_wall;
// 	int		max_h;
// 	int		min_h;

// 	while (x < w->m.w) // boucler sur des pixels colonnes
// 	{
// 		newx = 2  * y / (long double)MAP_WIDTH - 1; // creation d'un repere (-1,1) / (-1,1)
// 		w->ray.x = w->dir.x + w->plane.x * newx;
// 		w->ray.y = w->dir.y + w->plane.y * newx;
// 		w->map.x = (int)w->p.x;
// 		w->map.y = (int)w->p.y;
// 		w->delta.x = ft_abs(1 / w->ray.x); // la distance entre deux colonnes x consecutifs;
// 		w->delta.y = ft_abs(1 / w->ray.y); // la distance entre deux colonnes y consecutifs;
// 		if (w->ray.x < 0)
// 		{
// 			w->step.x = -1;
// 			w->side_d.x = (w->p.x - w->map.x) * w->delta.x;
// 		}
// 		else
// 		{
// 			w->step.x = 1;
// 			w->side_d.x = (w->map.x + 1 - w->p.x) * w->delta.x;
// 		}
// 		if (w->ray.x < 0)
// 		{
// 			w->step.y = -1;
// 			w->side_d.y = (w->p.y - w->map.y) * w->delta.y;
// 		}
// 		else
// 		{
// 			w->step.y = 1;
// 			w->side_d.y = (w->map.y + 1 - w->p.y) * w->delta.y;
// 		}
// 		// performing the dda algorithm
// 		while (w->hit == 0)
// 		{
// 			if (w->side_d.x < w->side_d.y)
// 			{
// 				w->side_d.x += w->delta.x;
// 				w->map.x += w->step.x;
// 				w->which_s = 0;
// 			}
// 			else
// 			{
// 				w->side_d.y += w->delta.y;
// 				w->map.y += w->step.y;
// 				w->which_s = 1;	
// 			}
// 			if (map[w->map.x][w->map.y] > 0)
// 				w->hit = 1;
// 		}
// 		if (w->which_s == 0)
// 			h_factor = (w->map.x - w->p.x + (1 - w->step.x) / 2) / w->ray.x;
// 		else
// 			h_factor = (w->map.y - w->p.y + (1 - w->step.y) / 2) / w->ray.y;
// 		z_wall = (int)(w->m.h / h_factor);
// 		min_h = -z_wall / 2 + w->m.h / 2;
// 		max_h = z_wall / 2 + w->m.h / 2;
// 		if (min_h < 0)
// 			min_h = 0;
// 		if (max_h >= w->m.h)
// 			max_h = w->m.h - 1;
// 		if (map[w->map.x][w->map.y] == 1)
// 			w->color = YELLOW;
// 		else if (map[w->map.x][w->map.y] == 2)
// 			w->color = GREEN;
// 		else if (map[w->map.x][w->map.y] == 3)
// 			w->color = ZABI;
// 		else if (map[w->map.x][w->map.y] == 4)
// 			w->color = ZABII;
// 		else if (map[w->map.x][w->map.y] == 5)
// 			w->color = ZABIII;
// 		else if (map[w->map.x][w->map.y] == 6)
// 			w->color = ZABIIII;
// 		if (w->which_s == 1)
// 			w->color = w->color / 2;
// 		y = min_h;
// 		while (y <= max_h)
// 		{
// 			w->m.d.pic_str[(int)(y * w->m.h + x)] = w->color;
// 			y++;
// 		}
// 		x++;
// 	}
// }

int		main(int argc, char **argv)
{
	t_wolf	w;
	// int				map[MAP_HEIGHT][MAP_WIDTH] =
	// {
	// 	{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,1,1,1,1,1,1,1},
	// 	{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
	// 	{4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	// 	{4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	// 	{4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
	// 	{4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,1,1,0,1,1,1,1,1},
	// 	{4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,1,0,0,0,1,1,1,1},
	// 	{4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,1,0,0,0,0,0,0,2},
	// 	{4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	// 	{4,0,2,0,0,0,0,5,0,0,0,0,0,0,0,5,1,0,0,0,0,0,0,2},
	// 	{4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,1,0,0,0,1,1,1,1},
	// 	{4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,1,1,1,1,1,1,1,1},
	// 	{6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
	// 	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
	// 	{6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
	// 	{4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
	// 	{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
	// 	{4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
	// 	{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
	// 	{4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
	// 	{4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
	// 	{4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
	// 	{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
	// 	{4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
	// };
	w.dir.x = -1;
	w.dir.y = 0;
	w.plane.x = 0;
	w.plane.y = 0.66;
	w.p.x = 12;
	w.p.y = 12;
	w.movespeed = 0.3;
	w.rotspeed = 3;
	if (argc != 2)
	{
		ft_putstr("Usage : ./wolf3d labyrinthe\n");
		exit(0);
	}
	readmap(argv[1], &w);
	w.m.h = 500;
	w.m.w= 500;
	w.name = ft_strdup("WOLF3D - mderri && slaanani");
	w.m.ptr = mlx_init();
	w.m.win = mlx_new_window(w.m.ptr,w.m.w , w.m.h, w.name);
	w.m.d.img_ptr = mlx_new_image(w.m.ptr,w.m.w , w.m.h);
	w.m.d.pic_str = (int *)mlx_get_data_addr(w.m.d.img_ptr, &w.m.d.bpp,
&w.m.d.s_l, &w.m.d.endian);
	raycaster(&w);
	mlx_put_image_to_window(w.m.ptr, w.m.win, w.m.d.img_ptr, 0, 0);
	mlx_hook(w.m.win, 2, 1, event_handle, &w.m);
	mlx_hook(w.m.win, 11, 1, ft_close, &w.m);
	mlx_loop(w.m.ptr);
	return (0);
}
