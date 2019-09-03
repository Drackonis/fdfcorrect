/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabtopix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 12:44:33 by rkergast          #+#    #+#             */
/*   Updated: 2019/09/02 14:35:44 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		ft_tabtoisoy(int x, int y, t_data *data)
{
	int py;

	if (data->proj == 0)
		py = (int)(((x * data->space) - (y * data->space)) * data->pos.ry);
	else
		py = (y * data->space) * data->pos.ry;
	return (py);
}

int		ft_tabtoisox(int x, int y, t_data *data)
{
	int px;

	if (data->proj == 0)
		px = (int)(((y * data->space) + (x * data->space)) * data->pos.rx);
	else
		px = (x * data->space) * data->pos.rx;
	return (px);
}
