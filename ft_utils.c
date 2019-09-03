/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:01:36 by rkergast          #+#    #+#             */
/*   Updated: 2019/09/02 15:12:03 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_diag(t_data *data)
{
	while (data->pt.x1 != data->pt.x2 + 1)
	{
		ft_putpix(data, data->pos.ix + data->pt.x1, data->pos.iy + data->pt.y1);
		data->pt.y1 += data->pt.sy;
		data->pt.x1++;
	}
}

void	ft_horiline(t_data *data)
{
	if (data->pt.y1 > data->pt.y2)
		ft_swap(data);
	while (data->pt.y1 <= data->pt.y2)
	{
		ft_putpix(data, data->pos.ix + data->pt.x1, data->pos.iy + data->pt.y1);
		data->pt.y1++;
	}
}

void	ft_vertline(t_data *data)
{
	if (data->pt.x1 > data->pt.x2)
		ft_swap(data);
	while (data->pt.x1 <= data->pt.x2)
	{
		ft_putpix(data, data->pos.ix + data->pt.x1, data->pos.iy + data->pt.y1);
		data->pt.x1++;
	}
}

void	ft_swap(t_data *data)
{
	int tmp;

	if (data->pt.x1 > data->pt.x2)
	{
		tmp = data->pt.x1;
		data->pt.x1 = data->pt.x2;
		data->pt.x2 = tmp;
		tmp = data->pt.y1;
		data->pt.y1 = data->pt.y2;
		data->pt.y2 = tmp;
	}
}
