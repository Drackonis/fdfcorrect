/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:35:55 by rkergast          #+#    #+#             */
/*   Updated: 2019/09/02 15:41:24 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_setcolorc1(t_data *data, int i, int j)
{
	int c;
	int x;
	int y;

	c = data->tab[0][0];
	x = data->tab[i][j];
	y = data->tab[i + 1][j];
	ft_setyellow(data);
	if (x > c && y > c)
		data->color.b += ((x - c) + (y - c)) * 10;
	else if (x < c && y < c)
		data->color.g -= ((c - x) + (c - y)) * 10;
}

void	ft_setcolorc(t_data *data, int i, int j)
{
	ft_setgreen(data);
	if (data->tab[i][j] != data->tab[i + 1][j])
	{
		if (data->tab[i][j] >= data->tab[0][0] &&
				data->tab[i + 1][j] >= data->tab[0][0])
			ft_setbrown(data);
		else if (data->tab[i][j] <= data->tab[0][0] &&
				data->tab[i + 1][j] <= data->tab[0][0])
			ft_setcyan(data);
		else
			ft_setgreen(data);
	}
	else if (data->tab[i][j] > data->tab[0][0] ||
			data->tab[i + 1][j] > data->tab[0][0])
		ft_setwhite(data);
	else if (data->tab[i][j] < data->tab[0][0] ||
			data->tab[i + 1][j] < data->tab[0][0])
		ft_setblue(data);
}

void	ft_setcolorl1(t_data *data, int i, int j)
{
	int c;
	int x;
	int y;

	c = data->tab[0][0];
	x = data->tab[i][j];
	y = data->tab[i][j + 1];
	ft_setyellow(data);
	if (x > c && y > c)
		data->color.b += ((x - c) + (y - c)) * 10;
	else if (x < c && y < c)
		data->color.g -= ((c - x) + (c - y)) * 10;
}

void	ft_setcolorl(t_data *data, int i, int j)
{
	ft_setgreen(data);
	if (data->tab[i][j] != data->tab[i][j + 1])
	{
		if (data->tab[i][j] >= data->tab[0][0] &&
				data->tab[i][j + 1] >= data->tab[0][0])
			ft_setbrown(data);
		else if (data->tab[i][j] <= data->tab[0][0] &&
				data->tab[i][j + 1] <= data->tab[0][0])
			ft_setcyan(data);
		else
			ft_setgreen(data);
	}
	else if (data->tab[i][j] > data->tab[0][0] ||
			data->tab[i][j + 1] > data->tab[0][0])
		ft_setwhite(data);
	else if (data->tab[i][j] < data->tab[0][0] ||
			data->tab[i][j + 1] < data->tab[0][0])
		ft_setblue(data);
}

void	ft_selectcolor(t_data *data, int lc, int i, int j)
{
	if (lc == 0)
	{
		if (data->color.color == 0)
			ft_setcolorl(data, i, j);
		else if (data->color.color == 1)
			ft_setcolorl1(data, i, j);
	}
	else if (lc == 1)
	{
		if (data->color.color == 0)
			ft_setcolorc(data, i, j);
		else if (data->color.color == 1)
			ft_setcolorc1(data, i, j);
	}
}
