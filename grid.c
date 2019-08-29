/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 09:07:47 by rboissel          #+#    #+#             */
/*   Updated: 2019/08/29 16:41:06 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

t_boolean		add_to_tetraset(t_tetraset *tetraset,
		t_tetraminos tetraminos)
{
	static int	i = 0;
	static char	let = 'A';

	if (i > 25)
		return (FALSE);
	tetra_coords(&tetraminos);
	tetraminos.letter = let;
	let++;
	tetraset->tetratab[i] = tetraminos;
	tetraset->tetratab[i].position.x = 0;
	tetraset->tetratab[i].position.y = 0;
	i++;
	tetraset->tetraminos_nb = i;
	return (TRUE);
}

void			set_h_vector(t_tetraminos *tetraminos)
{
	int			i;
	int			j;
	t_boolean	found;

	j = 0;
	tetraminos->vector.x = 0;
	found = FALSE;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tetraminos->description[i][j] == '#')
			{
				tetraminos->vector.x = (4 + j) % 4;
				found = TRUE;
				break ;
			}
			i++;
		}
		if (found)
			break ;
		j++;
	}
}

void			set_v_vector(t_tetraminos *tetraminos)
{
	int			i;
	int			j;
	t_boolean	found;

	i = 0;
	tetraminos->vector.y = 0;
	found = FALSE;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetraminos->description[i][j] == '#')
			{
				tetraminos->vector.y = (4 + i) % 4;
				found = TRUE;
				break ;
			}
			j++;
		}
		if (found)
			break ;
		i++;
	}
}

void			tetra_coords(t_tetraminos *tetraminos)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	set_h_vector(tetraminos);
	set_v_vector(tetraminos);
	while (i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (tetraminos->description[i][j] == '#')
			{
				tetraminos->coords[k].x = j - tetraminos->vector.x;
				tetraminos->coords[k].y = i - tetraminos->vector.y;
				tetraminos->description[i][j] = '.';
				tetraminos->description[tetraminos->coords[k].y]
					[tetraminos->coords[k].x] = '#';
				k++;
			}
		}
		i++;
	}
}

t_grid_struct	*new_grid_struct(int size)
{
	int				i;
	int				j;
	t_grid_struct	*new_grid;

	if (!(new_grid = malloc(sizeof(t_grid_struct))))
		return (NULL);
	if (!(new_grid->grid = malloc(sizeof(new_grid->grid) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(new_grid->grid[i] = malloc(sizeof(new_grid->grid[i]) * size + 1)))
			return (NULL);
		j = 0;
		while (j < size)
		{
			new_grid->grid[i][j] = '.';
			j++;
		}
		new_grid->grid[i][j] = '\0';
		i++;
	}
	new_grid->size = size;
	return (new_grid);
}
