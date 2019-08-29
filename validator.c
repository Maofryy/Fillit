/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 15:16:40 by rboissel          #+#    #+#             */
/*   Updated: 2019/08/29 16:40:58 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_boolean	valid_line(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '#' && line[i] != '.')
			return (FALSE);
		i++;
	}
	if (i != 4)
		return (FALSE);
	else
		return (TRUE);
}

void		is_in_contact_d(t_tetraminos *tetraminos, int i,
		int j, int *hashtag_nb)
{
	tetraminos->description[i][j] = 0;
	if (i < 3 && tetraminos->description[i + 1][j] == '#')
	{
		*hashtag_nb += 1;
		is_in_contact_b(tetraminos, i + 1, j, hashtag_nb);
	}
	if (j < 3 && tetraminos->description[i][j + 1] == '#')
	{
		*hashtag_nb += 1;
		is_in_contact_d(tetraminos, i, j + 1, hashtag_nb);
	}
}

void		is_in_contact_g(t_tetraminos *tetraminos, int i,
		int j, int *hashtag_nb)
{
	tetraminos->description[i][j] = 0;
	if (i < 3 && tetraminos->description[i + 1][j] == '#')
	{
		*hashtag_nb += 1;
		is_in_contact_b(tetraminos, i + 1, j, hashtag_nb);
	}
	if (j > 0 && tetraminos->description[i][j - 1] == '#')
	{
		*hashtag_nb += 1;
		is_in_contact_g(tetraminos, i, j - 1, hashtag_nb);
	}
}

void		is_in_contact_b(t_tetraminos *tetraminos, int i,
		int j, int *hashtag_nb)
{
	tetraminos->description[i][j] = 0;
	if (j > 0 && tetraminos->description[i][j - 1] == '#')
	{
		*hashtag_nb += 1;
		is_in_contact_g(tetraminos, i, j - 1, hashtag_nb);
	}
	if (i < 3 && tetraminos->description[i + 1][j] == '#')
	{
		*hashtag_nb += 1;
		is_in_contact_b(tetraminos, i + 1, j, hashtag_nb);
	}
	if (j < 3 && tetraminos->description[i][j + 1] == '#')
	{
		*hashtag_nb += 1;
		is_in_contact_d(tetraminos, i, j + 1, hashtag_nb);
	}
}

t_boolean	valid_tetraminos(t_tetraminos tetraminos)
{
	int		hashtag_nb;
	int		i;
	int		j;

	hashtag_nb = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetraminos.description[i][j] == '#')
			{
				hashtag_nb++;
				is_in_contact_d(&tetraminos, i, j, &(hashtag_nb));
				j = 3;
				i = 3;
			}
			j++;
		}
		i++;
	}
	if (hashtag_nb != 4)
		return (FALSE);
	return (TRUE);
}
