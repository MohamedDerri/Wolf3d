/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 03:28:11 by mderri            #+#    #+#             */
/*   Updated: 2019/11/22 17:39:56 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_close(t_wolf *w)
{
	mlx_destroy_image(w->m.ptr, w->m.d.img_ptr);
	mlx_destroy_window(w->m.ptr, w->m.win);
	exit(0);
}

int		event_handle(int keycode, t_wolf *w)
{
	if (keycode == ESC)
		ft_close(w);
	if (keycode == UP)
	{
		if (w->mp.map[(int)(w->p.x + w->dir.x * w->movespeed)][(int)w->p.y] == 0)
			w->p.x += w->dir.x * w->movespeed;
		if (w->mp.map[(int)w->p.x][(int)(w->p.y + w->dir.y * w->movespeed)] == 0)
			w->p.y += w->dir.y * w->movespeed;
	}
	if (keycode == DOWN)
	{
		if (w->mp.map[(int)(w->p.x - w->dir.x * w->movespeed)][(int)w->p.y] == 0)
		{
			w->p.x -= w->dir.x * w->movespeed;
			ft_putnbr(w->p.x);
		}
		if (w->mp.map[(int)w->p.x][(int)(w->p.y - w->dir.y * w->movespeed)] == 0)
		{
			w->p.y -= w->dir.y * w->movespeed;
			ft_putnbr(w->p.y);
		}
	}
	if (keycode == RIGHT)
	{
		double old_dirx = w->dir.x;
		w->dir.x = w->dir.x * cos(-w->rotspeed) - w->dir.y * sin(-w->rotspeed);
      	w->dir.y = old_dirx * sin(-w->rotspeed) + w->dir.y * cos(-w->rotspeed);
		double old_planex = w->plane.x;
		w->plane.x = w->plane.x * cos(-w->rotspeed) - w->plane.y * sin(-w->rotspeed);
      	w->plane.y = old_planex * sin(-w->rotspeed) + w->plane.y * cos(-w->rotspeed);
	}
	raycaster(w);
	return (0);
}
