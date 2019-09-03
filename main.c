/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:58:25 by rkergast          #+#    #+#             */
/*   Updated: 2019/09/03 15:33:43 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int				main(int argc, char **argv)
{
	t_lines		begin;
	t_data		data;

	if (argc == 2)
	{
		begin.index = 0;
		begin = read_arg(argv, begin, &data);
		data.begin = &begin;
		data.tab = ft_settab(&begin, &data);
		if (!data.tab)
		{
			write(1, "Invalide Map !\n", 15);
			return (0);
		}
		ft_initmlx(&data);
	}
	else
		write(1, "Argument error !\n", 18);
	return (0);
}
