/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:22:41 by ncharbog          #+#    #+#             */
/*   Updated: 2025/03/20 03:23:26 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../GNL/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

enum		e_id
{
	NO = 1,
	SO,
	WE,
	EA,
	F,
	C,
};

typedef struct s_data
{
	char	*n_txr;
	char	*s_txr;
	char	*w_txr;
	char	*e_txr;
	char	*f_color;
	char	*c_color;
	char	**map;
	int		x;
	int		y;
}			t_data;

bool		is_space(char c);
bool		parsing(char *file, t_data *data);

bool		check_identifier(char *buf, t_data *data);
bool		pars_identifier(t_data *data);

bool		check_map(char **file, t_data *data);

bool		flood_fill(char **map, int y, int x);

#endif