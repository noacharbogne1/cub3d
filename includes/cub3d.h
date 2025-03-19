/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:22:41 by ncharbog          #+#    #+#             */
/*   Updated: 2025/03/19 17:13:41 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../GNL/get_next_line.h"


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
} 			t_data;

bool parsing(char *file, t_data *data);

#endif