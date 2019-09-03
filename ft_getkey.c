/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getkey.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 12:47:40 by rkergast          #+#    #+#             */
/*   Updated: 2019/09/02 14:55:01 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		ft_getkey(int kc, t_data *data)
{
	if (kc == UP || kc == DOWN || kc == RIGHT || kc == LEFT)
		ft_keymove(kc, data);
	else if (kc == R || kc == G || kc == B || kc == C)
		ft_keycolor(kc, data);
	else if (kc == SPACE)
		ft_switchproj(data);
	else if (kc == ENTER)
		ft_initwin(data);
	else if (kc == ESC)
		exit(0);
	else if (kc == LESS || kc == MORE || kc == MUL || kc == DIV)
		ft_keyzoom(kc, data);
	else if (kc == RPX || kc == RPY || kc == RMX || kc == RMY)
		ft_keypad(kc, data);
	ft_display(data);
	return (0);
}

int		ft_display(t_data *data)
{
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, data->winwidth,\
			data->winheight);
	data->img.data = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,\
			&data->img.size_line, &data->img.endian);
	ft_drawimg(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,\
			data->img.img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	return (0);
}
