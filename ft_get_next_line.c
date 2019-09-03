/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:05:18 by rkergast          #+#    #+#             */
/*   Updated: 2019/09/03 15:47:30 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_lines				*set_link(int idx, char *line)
{
	t_lines			*new;

	if (!(new = (t_lines*)malloc(sizeof(t_lines))))
	{
		write(1, "Malloc Error !\n", 15);
		exit(0);
	}
	new->index = idx;
	new->line = ft_strdup(line);
	return (new);
}

void				set_value(t_data *data)
{
	data->ret = 0;
	data->idx = 0;
	data->start = 0;
}

t_lines				set_chain(int fd, t_lines begin, t_data *data)
{
	char			*line;
	t_lines			*current;

	set_value(data);
	while ((data->ret = get_next_line(fd, &line)) == 1)
	{
		if (data->start == 0)
		{
			begin.index = data->idx;
			begin.line = ft_strdup(line);
			current = &begin;
		}
		else
		{
			current->next = set_link(data->idx, line);
			current = current->next;
		}
		data->idx++;
		data->start++;
		free(line);
		line = NULL;
	}
	data->nblin = data->idx;
	current->next = NULL;
	return (begin);
}

t_lines				read_arg(char **argv, t_lines begin, t_data *data)
{
	int				fd;
	int				ret;

	fd = 0;
	ret = 0;
	if (argv[1])
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "Open FD Fail !\n", 15);
		exit(0);
	}
	begin = set_chain(fd, begin, data);
	if (argv[1])
		close(fd);
	return (begin);
}
