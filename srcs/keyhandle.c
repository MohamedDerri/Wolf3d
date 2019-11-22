/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 03:28:11 by mderri            #+#    #+#             */
/*   Updated: 2019/11/22 03:28:14 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_close(t_wolf *w)
{
	mlx_destroy_image(w->m.ptr, w->m.d.img_ptr);
	mlx_destroy_window(w->m.ptr, w->m.win);
	free_all(w);
	exit(0);
}

int		event_handle(int keycode, t_wolf *w)
{
	if (keycode == ESC)
		ft_close(w);
	return (0);
}
