/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:47:21 by rkergast          #+#    #+#             */
/*   Updated: 2019/08/14 15:17:26 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		ft_initmlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	ft_setscreen(data);
	ft_initwin(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->winwidth,\
			data->winheight, "fdf");
	mlx_key_hook(data->win_ptr, ft_getkey, data);
	mlx_expose_hook(data->win_ptr, ft_display, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
