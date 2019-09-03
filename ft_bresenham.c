/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:17:08 by rkergast          #+#    #+#             */
/*   Updated: 2019/09/02 15:11:33 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_quadran23(t_data *data)
{
	int err;

	err = data->pt.dx * 2;
	while (data->pt.x1 != data->pt.x2 + 1)
	{
		ft_putpix(data, data->pos.ix + data->pt.x1, data->pos.iy + data->pt.y1);
		data->pt.x1++;
		err -= data->pt.dy;
		if (err <= data->pt.dx)
		{
			err += data->pt.dx;
			data->pt.y1 += data->pt.sy;
		}
	}
}

void		ft_quadran14(t_data *data)
{
	int err;

	err = data->pt.dy * 2;
	while (data->pt.y1 != data->pt.y2 + 1)
	{
		ft_putpix(data, data->pos.ix + data->pt.x1, data->pos.iy + data->pt.y1);
		data->pt.y1 += data->pt.sy;
		err -= data->pt.dx;
		if (err <= data->pt.dy)
		{
			err += data->pt.dy;
			data->pt.x1++;
		}
	}
}

void		ft_bresenham(t_data *data)
{
	data->pt.dx = (int)(data->pt.x2 - data->pt.x1);
	data->pt.dy = (int)(data->pt.y2 - data->pt.y1);
	data->pt.sy = (data->pt.y1 < data->pt.y2) ? 1 : -1;
	data->pt.dx = (data->pt.x2 > data->pt.x1) ?
		data->pt.x2 - data->pt.x1 : (data->pt.x2 - data->pt.x1) * -1;
	data->pt.dy = (data->pt.y2 > data->pt.y1) ?
		data->pt.y2 - data->pt.y1 : (data->pt.y2 - data->pt.y1) * -1;
	if (data->pt.x1 == data->pt.x2)
		ft_horiline(data);
	else if (data->pt.y1 == data->pt.y2)
		ft_vertline(data);
	else if (data->pt.dx == data->pt.dy)
		ft_diag(data);
	else if (data->pt.dx < data->pt.dy)
		ft_quadran14(data);
	else if (data->pt.dx > data->pt.dy)
		ft_quadran23(data);
}
