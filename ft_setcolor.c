/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:03:05 by rkergast          #+#    #+#             */
/*   Updated: 2019/08/22 17:06:19 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_setred(t_data *data)
{
	data->color.r = 255;
	data->color.g = 0;
	data->color.b = 0;
}

void	ft_setgreen(t_data *data)
{
	data->color.r = 0;
	data->color.g = 255;
	data->color.b = 0;
}

void	ft_setblue(t_data *data)
{
	data->color.r = 0;
	data->color.g = 0;
	data->color.b = 255;
}

void	ft_setwhite(t_data *data)
{
	data->color.r = 255;
	data->color.g = 255;
	data->color.b = 255;
}

void	ft_setbrown(t_data *data)
{
	data->color.r = 100;
	data->color.g = 60;
	data->color.b = 0;
}
