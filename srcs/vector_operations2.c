/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 03:24:20 by mderri            #+#    #+#             */
/*   Updated: 2019/11/22 03:24:22 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			create_camera(t_wolf *w, char **s, int i)
{
	t_vecteur	up;

	up = normalise(create_v(0.000001, 1 + w->m.h - w->m.h, 0.000001));
	w->cam.forward = normalise(sub(w->cam.lookat, w->cam.position));
	w->cam.left = normalise(vcross(up, w->cam.forward));
	w->cam.up = normalise(vcross(w->cam.forward, w->cam.left));
	w->cam.frame_height = (long double)w->m.h / (long double)w->m.w;
	w->cam.frame_width = w->cam.frame_height * (long double)w->m.w /
(long double)w->m.h;
}

long double		module(t_vecteur v1)
{
	return (sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z));
}

t_vecteur		normalise(t_vecteur v1)
{
	t_vecteur u;

	u.x = v1.x / module(v1);
	u.y = v1.y / module(v1);
	u.z = v1.z / module(v1);
	return (u);
}

t_vecteur	create_v(long double x, long double y, long double z)
{
	t_vecteur		v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

long double		map(long double x, double size, int w)
{
	return (x * size / w - (size / 2));
}

void			make_ray(t_wolf *w)
{
	t_vecteur	left;
	t_vecteur	up;
	t_vecteur	forward;
	t_vecteur	sumupleft;

	left = kv(w->cam.left, map(w->v1.x, w->cam.frame_width, w->m.w));
	up = kv(w->cam.up, map(w->v1.y, w->cam.frame_height, w->m.h));
	forward = kv(w->cam.forward, w->cam.focal_length);
	sumupleft = sum(up, left);
	w->ray.direct = sum(sumupleft, forward);
	w->ray.org = create_v(w->cam.position.x, w->cam.position.y,
	w->cam.position.z);
}
