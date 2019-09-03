/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawimg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 14:22:26 by rkergast          #+#    #+#             */
/*   Updated: 2019/09/02 15:41:14 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_putpix(t_data *data, int x, int y)
{
	if (x > 0 && y > 0 && x < data->winwidth && y < data->winheight)
	{
		data->img.data[(x * (data->img.bpp / 8)) +
			(y * data->img.size_line) + 2] = data->color.r;
		data->img.data[(x * (data->img.bpp / 8)) +
			(y * data->img.size_line) + 1] = data->color.g;
		data->img.data[(x * (data->img.bpp / 8)) +
			(y * data->img.size_line)] = data->color.b;
	}
}

void		ft_drawcolumn(t_data *data)
{
	int		i;
	int		j;

	j = 0;
	while (j < data->nbcol)
	{
		i = 0;
		while (i < data->nblin - 1)
		{
			data->pt.x1 = ft_tabtoisox(i, j, data) + data->winwidth / 2;
			data->pt.y1 = ft_tabtoisoy(i, j, data) + data->winheight / 2;
			data->pt.x2 = ft_tabtoisox(i + 1, j, data) + data->winwidth / 2;
			data->pt.y2 = ft_tabtoisoy(i + 1, j, data) + data->winheight / 2;
			data->pt.y1 -= data->tab[i][j] * data->heightcoef;
			data->pt.y2 -= data->tab[i + 1][j] * data->heightcoef;
			ft_selectcolor(data, 1, i, j);
			ft_swap(data);
			ft_bresenham(data);
			i++;
		}
		j++;
	}
}

void		ft_drawline(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->nblin)
	{
		j = 0;
		while (j < data->nbcol - 1)
		{
			data->pt.x1 = ft_tabtoisox(i, j, data) + data->winwidth / 2;
			data->pt.y1 = ft_tabtoisoy(i, j, data) + data->winheight / 2;
			data->pt.x2 = ft_tabtoisox(i, j + 1, data) + data->winwidth / 2;
			data->pt.y2 = ft_tabtoisoy(i, j + 1, data) + data->winheight / 2;
			data->pt.y1 -= data->tab[i][j] * data->heightcoef;
			data->pt.y2 -= data->tab[i][j + 1] * data->heightcoef;
			ft_selectcolor(data, 0, i, j);
			ft_swap(data);
			ft_bresenham(data);
			j++;
		}
		i++;
	}
}

void		ft_drawimg(t_data *data)
{
	ft_drawline(data);
	ft_drawcolumn(data);
}
