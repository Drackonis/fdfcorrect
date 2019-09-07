/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:50:09 by rkergast          #+#    #+#             */
/*   Updated: 2019/09/07 14:59:47 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void				malloc_error(void)
{
	write(1, "Malloc Error !\n", 15);
	exit(0);
}

void				read_fail(void)
{
	write(1, "Read FD Fail !\n", 15);
	exit(0);
}

void				invalid_map(void)
{
	write(1, "Invalide Map !\n", 15);
	exit(0);
}

void				open_fail(void)
{
	write(1, "Open FD Fail !\n", 15);
	exit(0);
}

void				fd_empty(void)
{
	write(1, "FD Empty !\n", 11);
	exit(0);
}
