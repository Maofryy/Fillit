/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 15:17:43 by rboissel          #+#    #+#             */
/*   Updated: 2019/08/29 16:40:17 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <stdlib.h>

int		resolve(t_grid_struct *grid_struct, t_tetraset *tetraset, int i)
{
	int		placed;
	int		ret;

	if (i < 0)
		return (0);
	reset_position(tetraset, i);
	placed = try_placing(grid_struct, &tetraset->tetratab[i]);
	while (placed)
	{
		if (i == tetraset->tetraminos_nb - 1)
			return (1);
		else
		{
			ret = resolve(grid_struct, tetraset, i + 1);
			if (ret == 1)
				return (1);
			else
			{
				remove_tetra(grid_struct, tetraset, i);
				increment_pos(grid_struct, &tetraset->tetratab[i].position);
				placed = try_placing(grid_struct, &tetraset->tetratab[i]);
			}
		}
	}
	return (0);
}

int		solve(t_tetraset *tetraset)
{
	t_grid_struct	*grid_struct;
	t_grid_struct	*tmp_grid_struct;
	t_point			starting_point;
	int				size;

	tmp_grid_struct = NULL;
	size = square(tetraset->tetraminos_nb * 4);
	grid_struct = new_grid_struct(size);
	if (!grid_struct)
		return (0);
	starting_point.x = -1;
	starting_point.y = 0;
	while ((resolve(grid_struct, tetraset, 0)) == 0)
	{
		tmp_grid_struct = grid_struct;
		grid_struct = new_grid_struct(grid_struct->size + 1);
		free_grid_struct(tmp_grid_struct);
		reset_positions(tetraset, 0);
	}
	display_grid(grid_struct);
	free_grid_struct(grid_struct);
	return (1);
}

int		square(int nb)
{
	int		i;

	i = 1;
	while (i * i != nb)
	{
		if (i * i > nb)
			return (i);
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i);
}
