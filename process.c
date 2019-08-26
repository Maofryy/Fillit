/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 15:33:38 by rboissel          #+#    #+#             */
/*   Updated: 2019/08/25 16:45:03 by rboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/includes/libft.h"
#include <stdlib.h>
#include <unistd.h>

t_boolean	process_file2(t_tetraset *tetraset, t_tetraminos *current_tetra,
		char *line, int j)
{
	if (!valid_line(line))
	{
		free(line);
		return (FALSE);
	}
	parse_line(current_tetra, j, line);
	if (j == 3)
	{
		if (!valid_tetraminos(*current_tetra))
		{
			free(line);
			return (FALSE);
		}
		if (!(add_to_tetraset(tetraset, *current_tetra)))
		{
			free(line);
			return (FALSE);
		}
	}
	return (TRUE);
}

t_boolean	process_file(int fd, t_tetraset *tetraset)
{
	int				res;
	char			*line;
	int				j;
	t_tetraminos	current_tetra;

	j = 0;
	while ((res = get_next_line(fd, &line) > 0))
	{
		if (j == 4)
		{
			if (ft_strequ(line, "") != 0)
				j = 0;
			else
				return (FALSE);
		}
		else if (j < 4)
		{
			if (!(process_file2(tetraset, &current_tetra, line, j)))
				return (FALSE);
			j++;
		}
		free(line);
	}
	return (j == 4 ? TRUE : FALSE);
}

t_boolean	invalid(int fd, t_tetraset *tetraset)
{
	close(fd);
	free(tetraset);
	ft_putstr("error\n");
	return (FALSE);
}
