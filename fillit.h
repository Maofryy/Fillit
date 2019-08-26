/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:15:16 by rboissel          #+#    #+#             */
/*   Updated: 2019/08/26 11:43:22 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/includes/libft.h"

typedef enum
{
	FALSE,
	TRUE
}	t_boolean;

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_tetraminos
{
	char	description[4][4];
	t_point	coords[4];
	t_point	vector;
	t_point	position;
	char	letter;
}				t_tetraminos;

typedef struct	s_tetraset
{
	t_tetraminos	tetratab[26];
	int				tetraminos_nb;
}				t_tetraset;

typedef struct	s_grid_struct
{
	char		**grid;
	int			size;
}				t_grid_struct;

t_boolean		valid_line(char *line);
t_boolean		valid_tetraminos(t_tetraminos tetraminos);
void			parse_line(t_tetraminos *tetraminos, int i, char *line);
t_boolean		add_to_tetraset(t_tetraset *tetraset, t_tetraminos tetraminos);
t_grid_struct	*new_grid_struct(int size);
void			display_grid(t_grid_struct *grid_struct);
void			tetra_coords(t_tetraminos *tetraminos);
t_boolean		tetramino_placable(t_grid_struct *grid_struct, t_tetraminos
				*tetraminos, t_point *starting_point);
void			place_tetramino(t_grid_struct *grid_struct, t_tetraminos
				*tetraminos, t_point starting_point);
t_boolean		try_placing(t_grid_struct *grid_struct,
				t_tetraminos *tetramino);
void			remove_tetra(t_grid_struct *grid_struct, t_tetraset *tetraset,
				int k);
int				resolve(t_grid_struct *grid_struct,
				t_tetraset *tetraset, int i);
int				resolve2(t_grid_struct *grid_struct,
				t_tetraset *tetraset, int i);
t_boolean		is_placable(t_grid_struct *grid_struct,
				t_tetraminos *tetramino);
void			is_in_contact_d(t_tetraminos *tetraminos, int i,
				int j, int *hashtag_nb);
void			is_in_contact_g(t_tetraminos *tetraminos, int i,
				int j, int *hashtag_nb);
void			is_in_contact_b(t_tetraminos *tetraminos, int i,
				int j, int *hashtag_nb);
void			set_h_vector(t_tetraminos *tetraminos);
void			set_v_vector(t_tetraminos *tetraminos);
t_boolean		incrementable(t_grid_struct *grid_struct, t_point *position);
void			reset_position(t_tetraset *tetraset, int i);
void			reset_positions(t_tetraset *tetraset, int from);
t_boolean		increment_pos(t_grid_struct *grid_struct,
				t_point *position);
int				square(int nb);
void			free_grid_struct(t_grid_struct *grid_struct);
int				solve(t_tetraset *tetraset);
t_boolean		process_file(int fd, t_tetraset *tetraset);
t_boolean		process_file2(t_tetraset *tetraset, t_tetraminos *current_tetra,
				char *line, int j);
t_boolean		invalid(int fd, t_tetraset *tetraset);
int				out(t_tetraset *tetraset);

#endif
