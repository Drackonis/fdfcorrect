/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setcolor2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:10:37 by rkergast          #+#    #+#             */
/*   Updated: 2019/08/22 17:13:32 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_setyellow(t_data *data)
{
	data->color.r = 255;
	data->color.g = 255;
	data->color.b = 0;
}

void	ft_setcyan(t_data *data)
{
	data->color.r = 0;
	data->color.g = 255;
	data->color.b = 255;
}

void	ft_setpurple(t_data *data)
{
	data->color.r = 255;
	data->color.g = 0;
	data->color.b = 255;
}

void	ft_setblack(t_data *data)
{
	data->color.r = 0;
	data->color.g = 0;
	data->color.b = 0;
}

void	ft_setgrey(t_data *data)
{
	data->color.r = 100;
	data->color.g = 100;
	data->color.b = 100;
}
