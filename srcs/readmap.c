/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:12:21 by mderri            #+#    #+#             */
/*   Updated: 2019/11/24 15:12:22 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		ft_count_wordsc(char const *s, char c)
{
	int			v;
	int			i;
	int			cnt_word;

	i = 0;
	v = 0;
	cnt_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && v == 0)
		{
			v = 1;
			cnt_word++;
		}
		else if (s[i] == c && v == 1)
			v = 0;
		i++;
	}
	return (cnt_word);
}

// int				init_and_loop(int fd, char *line, t_wolf *w)
// {
// 	i = 0;
// 	j = 0;
// 	v = 0;
// 	while (get_next_line(fd, &line))
// 	{
// 		if ((i = ft_count_words(line, ' ')) == 0 ||
// 		(i - j != 0 && v == 1))
// 			return (1);
// 		v = 1;
// 		j = i;
// 	}
// 	free(line);
// 	close(fd);
// 	return (0);
// }

// int				verify(char *name, t_wolf *w)
// {
// 	char		*line;
// 	int			fd;

// 	fd = open(name, O_RDONLY);
// 	line = NULL;
// 	if (get_next_line(fd, &line) < 0)
// 	{
// 		free(line);
// 		close(fd);
// 		return (1);
// 	}
// 	if (ft_strlen(line) == 0)
// 		return (1);
// 	return (init_and_loop(fd, line, map));
// }

void			init_nb_ligne_col(int fd, t_wolf *w)
{
	char		*line;
	int			i;

	i = 0;
	while (get_next_line(fd, &line))
	{
		if (i == 0)
			w->ncol = ft_count_wordsc(line, ' ');
		i++;
	}
	w->nligne = i;
	free(line);
}

void			readmap(char *arg, t_wolf *w)
{
	char		**tmp;
	char		*line;
	int			fd;
    int         incy;
    int         incx;

	fd = open(arg, O_RDONLY);
	w->mp.map = malloc(sizeof(int) * w->nligne);
	incy = 0;
	while (get_next_line(fd, &line))
	{
		w->mp.map[incy] = malloc(sizeof(int) * w->ncol);
		tmp = ft_strsplit(line, ' ');
		incx = 0;
		while (incx < w->ncol)
		{
			w->mp.map[incy][incx] = ft_atoi(tmp[incx]);
			incx++;
		}
		free_splited(tmp);
		incy++;
	}
	free(line);
	close(fd);
}
