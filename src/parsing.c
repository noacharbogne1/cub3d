/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:22:02 by ncharbog          #+#    #+#             */
/*   Updated: 2025/03/19 17:53:36 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_space(char c)
{
	if ((c >= 7 && c <= 13) || c == 32)
		return (true);
	return (false);
}

int	compare_identifier(char *id, int len)
{
	if (len > 2)
		return (0);
	if (!ft_strncmp(id, "NO", len))
		return (NO);
	else if (!ft_strncmp(id, "SO", len))
		return (SO);
	else if (!ft_strncmp(id, "WE", len))
		return (WE);
	else if (!ft_strncmp(id, "EA", len))
		return (EA);
	else if (!ft_strncmp(id, "F", len))
		return (F);
	else if (!ft_strncmp(id, "C", len))
		return (C);
	return (0);
}

char	*take_path(char *buf)
{
	char *path;
	int len;

	len = 0;
	while (buf[len] && !is_space(buf[len]))
		len++;
	path = ft_substr(buf, 0, len);
	if (!path)
		return (NULL);
	return (path);
}

void	assign_texture(int id, char *buf, t_data *data)
{
	char *path;

	path = take_path(buf);
	if (!path)
		return ;
	if (id == NO)
		data->n_txr = path;
	else if (id == NO)
		data->s_txr = path;
	else if (id == WE)
		data->w_txr = path;
	else if (id == EA)
		data->e_txr = path;
	else if (id == F)
		data->f_color = path;
	else if (id == C)
		data->c_color = path;
	printf("id: %d |path: %s\n", id, path);
}

bool	check_identifier(char *buf, t_data *data)
{
	int	i;
	int len;
	int id;

	i = 0;
	len = 0;
	while (buf[i] && is_space(buf[i]))
		i++;
	if (!buf[i] || buf[i] == '\n')
		return (false);
	while (buf[i + len] && !is_space(buf[i + len]))
		len++;
	id = compare_identifier(buf + i, len);
	if (!id)
		return (false);
	i += len;
	while (buf[i] && is_space(buf[i]))
		i++;
	assign_texture(id, buf + i, data);
	return (true);
}

static bool	copy_file(char *file, t_data *data)
{
	int		i;
	int		fd;
	char	*buf;
	int		is_map;

	i = 0;
	is_map = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nFailed to open file %s\n", file);
		return (false);
	}
	while (1)
	{
		buf = get_next_line(fd);
		if (is_map < 6)
		{
			if (!check_identifier(buf, data))
			{
				free(buf);
				return (false);
			}
			is_map++;
		}
		else
			check_map(buf, data);
		free(buf);
	}
	close(fd);
	return (true);
}

static bool	check_extension(char *file)
{
	if (!file || ft_strlen(file) < 5)
		return (false);
	if (ft_strncmp(file + ft_strlen(file) - 4, ".cub", 4))
		return (false);
	return (true);
}

bool parsing(char *file, t_data *data)
{
	if (!check_extension(file))
		return (false);
	if (!copy_file(file, data))
		return (false);
	return (true);
}
