/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 09:11:14 by rboissel          #+#    #+#             */
/*   Updated: 2019/08/29 16:40:37 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	display_grid(t_grid_struct *grid_struct)
{
	int		i;
	int		j;

	i = 0;
	while (i < grid_struct->size)
	{
		j = 0;
		while (j < grid_struct->size)
		{
			ft_putchar(grid_struct->grid[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

void	remove_tetra(t_grid_struct *grid_struct, t_tetraset *tetraset,
		int k)
{
	int		i;
	int		j;

	i = 0;
	while (i < grid_struct->size)
	{
		j = 0;
		while (j < grid_struct->size)
		{
			if (grid_struct->grid[i][j] == tetraset->tetratab[k].letter)
				grid_struct->grid[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	parse_line(t_tetraminos *tetraminos, int i, char *line)
{
	int		j;

	j = 0;
	while (j < 4)
	{
		tetraminos->description[i][j] = line[j];
		j++;
	}
}

void	free_grid_struct(t_grid_struct *grid_struct)
{
	int		i;

	i = 0;
	while (i < grid_struct->size)
	{
		free(grid_struct->grid[i]);
		grid_struct->grid[i] = NULL;
		i++;
	}
	free(grid_struct->grid);
	grid_struct->grid = NULL;
	free(grid_struct);
	grid_struct = NULL;
}

int		out(t_tetraset *tetraset)
{
	free(tetraset);
	ft_putstr("error\n");
	return (0);
}
