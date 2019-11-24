/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:07:25 by mderri            #+#    #+#             */
/*   Updated: 2019/11/24 15:07:27 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void       raycaster(t_wolf *w)
{
	int x = 0;
	int y = 0;
	w->hit = 0;
	double newx;
	double h_factor;
	int		z_wall;
	int		max_h;
	int		min_h;

	while (x < w->m.w) // boucler sur des pixels colonnes
	{
		newx = 2  * y / (long double)MAP_WIDTH - 1; // creation d'un repere (-1,1) / (-1,1)
		w->ray.x = w->dir.x + w->plane.x * newx;
		w->ray.y = w->dir.y + w->plane.y * newx;
		w->mp.x = (int)w->p.x;
		w->mp.y = (int)w->p.y;
		w->delta.x = ft_abs(1 / w->ray.x); // la distance entre deux colonnes x consecutifs;
		w->delta.y = ft_abs(1 / w->ray.y); // la distance entre deux colonnes y consecutifs;
		if (w->ray.x < 0)
		{
			w->step.x = -1;
			w->side_d.x = (w->p.x - w->mp.x) * w->delta.x;
		}
		else
		{
			w->step.x = 1;
			w->side_d.x = (w->mp.x + 1 - w->p.x) * w->delta.x;
		}
		if (w->ray.y < 0)
		{
			w->step.y = -1;
			w->side_d.y = (w->p.y - w->mp.y) * w->delta.y;
		}
		else
		{
			w->step.y = 1;
			w->side_d.y = (w->mp.y + 1 - w->p.y) * w->delta.y;
		}
		// performing the dda algorithm
		while (w->hit == 0)
		{
			if (w->side_d.x < w->side_d.y)
			{
				w->side_d.x += w->delta.x;
				w->mp.x += w->step.x;
				w->which_s = 0;
			}
			else
			{
				w->side_d.y += w->delta.y;
				w->mp.y += w->step.y;
				w->which_s = 1;	
			}
			if (w->mp.map[w->mp.x][w->mp.y] > 0)
				w->hit = 1;
		}
		if (w->which_s == 0)
			h_factor = (w->mp.x - w->p.x + (1 - w->step.x) / 2) / w->ray.x + 5;
		else
			h_factor = (w->mp.y - w->p.y + (1 - w->step.y) / 2) / w->ray.y + 5;
		printf("h_factor = %f\n", h_factor);
		z_wall = (int)(w->m.h / h_factor);
		printf("z_wall = %d\n", z_wall);
		min_h = (-z_wall / 2) + w->m.h / 2;
		max_h = (z_wall / 2) + w->m.h / 2;
		if (min_h < 0)
			min_h = 0;
		if (max_h >= w->m.h)
			max_h = w->m.h;
		if (w->mp.map[w->mp.x][w->mp.y] == 1)
			w->color = YELLOW;
		else if (w->mp.map[w->mp.x][w->mp.y] == 2)
			w->color = GREEN;
		else if (w->mp.map[w->mp.x][w->mp.y] == 3)
			w->color = ZABI;
		else if (w->mp.map[w->mp.x][w->mp.y] == 4)
			w->color = ZABII;
		else if (w->mp.map[w->mp.x][w->mp.y] == 5)
			w->color = ZABIII;
		else if (w->mp.map[w->mp.x][w->mp.y] == 6)
			w->color = ZABIIII;
		// if (w->which_s == 1)
		// 	w->color = w->color / 2;
        printf("min_h = %d && max_h = %d\n", min_h, max_h);
		y = min_h;
		while (y <= max_h)
		{
            // printf("|%d|", (y * w->m.w + x));
			w->m.d.pic_str[(int)(y * w->m.w + x)] = w->color;
			y++;
		}
		x++;
	}
}
