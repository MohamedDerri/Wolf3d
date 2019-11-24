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
# include <stdio.h>

# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define PI 3.1415926535
# define ADV ((PI * 60) / 180)
# define WIDTH 400
# define HEIGHT 400
# define MAP_HEIGHT 24
# define MAP_WIDTH 24
# define YELLOW 0xebb00e
# define GREEN 0x8edb09
# define ZABI 0x02e39c
# define ZABII 0x03fcf8
# define ZABIII 0x5e5ef2
# define ZABIIII 0xe741f2

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
}				t_vecteur;

typedef struct	s_ivecteur
{
	int	x;
	int	y;
}				t_ivecteur;

typedef struct	s_map
{
	int	**map;
	int		x;
	int 	y;
}				t_map;

typedef struct	s_wolf
{
	t_mlx			m;
	t_vecteur		ray;
	t_vecteur		dir;
	t_vecteur		delta;
	t_vecteur		plane;
	t_ivecteur		grid;
	t_ivecteur		side_d;
	t_ivecteur		step;
	t_vecteur		p;
	int				hit;
	int				which_s;
	int				color;
	double			movespeed;
	double 			rotspeed;
	char			*name;
	t_map			mp;
	int				nligne;
	int				ncol;
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
void			raycaster(t_wolf *w);
// ----------------------------------------------------------------------
void			init_nb_ligne_col(int fd, t_wolf *w);
void			readmap(char *arg, t_wolf *w);
#endif
