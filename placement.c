/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:12:15 by rboissel          #+#    #+#             */
/*   Updated: 2019/08/29 16:40:06 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_boolean	try_placing(t_grid_struct *grid_struct, t_tetraminos *tetramino)
{
	int		i;
	int		j;
	t_point	starting_point;

	i = tetramino->position.y;
	starting_point.y = i;
	j = tetramino->position.x;
	while (i < grid_struct->size)
	{
		starting_point.x = j;
		while (j < grid_struct->size)
		{
			if (tetramino_placable(grid_struct, tetramino, &starting_point))
			{
				place_tetramino(grid_struct, tetramino, starting_point);
				return (TRUE);
			}
			j++;
			starting_point.x++;
		}
		i++;
		j = 0;
		starting_point.y++;
	}
	return (FALSE);
}

t_boolean	is_placable(t_grid_struct *grid_struct, t_tetraminos *tetramino)
{
	int		i;
	int		j;
	t_point	starting_point;

	i = tetramino->position.y;
	starting_point.y = i;
	j = tetramino->position.x;
	while (i < grid_struct->size)
	{
		starting_point.x = j;
		while (j < grid_struct->size)
		{
			if (tetramino_placable(grid_struct, tetramino, &starting_point))
				return (TRUE);
			j++;
			starting_point.x++;
		}
		i++;
		j = 0;
		starting_point.y++;
	}
	return (FALSE);
}

t_boolean	tetramino_placable(t_grid_struct *grid_struct,
		t_tetraminos *tetramino, t_point *starting_point)
{
	int			i;
	t_point		grid_point;

	i = 0;
	while (i < 4)
	{
		grid_point.y = starting_point->y + tetramino->coords[i].y;
		grid_point.x = starting_point->x + tetramino->coords[i].x;
		if (grid_point.y > grid_struct->size - 1
				|| grid_point.x > grid_struct->size - 1)
			return (FALSE);
		if (grid_struct->grid[grid_point.y][grid_point.x] != '.')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void		place_tetramino(t_grid_struct *grid_struct, t_tetraminos *tetramino,
		t_point starting_point)
{
	int		i;

	i = 0;
	tetramino->position.x = starting_point.x;
	tetramino->position.y = starting_point.y;
	while (i < 4)
	{
		grid_struct->grid[starting_point.y + tetramino->coords[i].y]
				[starting_point.x + tetramino->coords[i].x] = tetramino->letter;
		i++;
	}
}
