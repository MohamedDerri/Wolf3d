/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 23:59:36 by mderri            #+#    #+#             */
/*   Updated: 2019/11/22 18:14:09 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <mlx.h>
# include "libft.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>

# define ESC 53
# define UP 126
# define DOWN 125
# define PI 3.1415926535
# define ADV ((PI * 60) / 180)
# define MAX 1e30
# define MIN 1e-4
# define MAP_HEIGHT 24
# define MAP_WIDTH 24

typedef struct	s_data
{
	void	*img_ptr;
	int		bpp;
	int		s_l;
	int		endian;
	int		*pic_str;
}				t_data;

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
	int		h;
	int		w;
	t_data	d;
}				t_mlx;

typedef struct	s_color
{
	long double	r;
	long double	g;
	long double	b;
}				t_color;

typedef struct	s_vecteur
{
	long double	x;
	long double	y;
	long double	z;
}				t_vecteur;

typedef struct	s_camera
{
	t_vecteur	lookat;
	t_vecteur	position;
	t_vecteur	up;
	t_vecteur	forward;
	t_vecteur	left;
	long double	focal_length;
	long double	frame_width;
	long double	frame_height;
}				t_camera;

typedef struct	s_wolf
{
	t_mlx			m;
	t_vecteur		ray;
	t_vecteur		v1;
	t_camera		cam;
	t_vecteur		u;
	char			*name;
}				t_wolf;

t_vecteur		sum(t_vecteur v1, t_vecteur v2);
t_vecteur		sub(t_vecteur v1, t_vecteur v2);
t_vecteur		kv(t_vecteur v1, long double k);
long double		dot(t_vecteur v1, t_vecteur v2);
t_vecteur		vcross(t_vecteur v1, t_vecteur v2);
long double		module(t_vecteur v1);
t_vecteur		normalise(t_vecteur v1);
int				ft_close(t_wolf *w);
int				event_handle(int keycode, t_wolf *w);
void			put_error(char *str);
int				rgb(int r, int g, int b);
t_vecteur		create_v(long double x, long double y, long double z);
void			free_splited(char **tab);
double			deg_to_rad(double angle);
t_vecteur		rotatez(t_vecteur vec, double angle);
t_vecteur		rotatex(t_vecteur vec, double angle);
t_vecteur		rotatey(t_vecteur vec, double angle);
t_vecteur		translation(t_vecteur old_pos, t_vecteur tr);
#endif
