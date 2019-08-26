/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:46:12 by rboissel          #+#    #+#             */
/*   Updated: 2019/08/26 12:32:24 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <stdlib.h>

t_boolean	increment_pos(t_grid_struct *grid_struct, t_point *position)
{
	if (position->x < grid_struct->size)
	{
		position->x++;
		return (TRUE);
	}
	if (position->x == grid_struct->size - 1
			&& position->y < grid_struct->size - 1)
	{
		position->x = 0;
		position->y++;
		return (TRUE);
	}
	return (FALSE);
}

void		reset_positions(t_tetraset *tetraset, int from)
{
	while (from < tetraset->tetraminos_nb)
	{
		tetraset->tetratab[from].position.x = 0;
		tetraset->tetratab[from].position.y = 0;
		from++;
	}
}

void		reset_position(t_tetraset *tetraset, int i)
{
	tetraset->tetratab[i].position.x = 0;
	tetraset->tetratab[i].position.y = 0;
}

int			ft_print_usage(t_tetraset *tetraset)
{
	ft_putstr("usage : ./fillit tetraminos_list_file\n");
	free(tetraset);
	return (0);
}

int			main(int argc, char **argv)
{
	int			fd;
	t_boolean	valid;
	t_tetraset	*tetraset;

	if (!(tetraset = malloc(sizeof(t_tetraset))))
		return (0);
	if (argc == 2)
	{
		if (argv[1] == NULL)
			return (invalid(0, tetraset));
		else
		{
			if ((fd = open(argv[1], O_RDONLY)) == -1)
				return (invalid(fd, tetraset));
		}
	}
	else
		return (ft_print_usage(tetraset));
	valid = process_file(fd, tetraset);
	if (!valid)
		return (invalid(fd, tetraset));
	solve(tetraset);
	close(fd);
	free(tetraset);
	return (1);
}
