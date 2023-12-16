/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyze_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:47:46 by lmorais-          #+#    #+#             */
/*   Updated: 2023/12/04 16:52:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_map_error(char *error_msg)
{
	ft_printf("%s", error_msg);
	exit(EXIT_FAILURE);
}

static void	ft_check_borders(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < (data->size_y / IMG_H))
	{
		if ((int)ft_strlen(data->map->map[y]) != data->size_x / IMG_W)
			ft_map_error("ERROR\nMAP HAS TO BE RECTANGULAR\n");
		x = 0;
		while (x < (data->size_x / IMG_W))
		{
			if (data->map->map[y][x] != '0' && data->map->map[y][x] != '1' &&
				data->map->map[y][x] != 'C' && data->map->map[y][x] != 'P' &&
				data->map->map[y][x] != 'E')
				ft_map_error("ERROR\nFOR MAP '0','1','C','P','E' ARE VALID\n");
			else if ((y == 0 || x == 0) && data->map->map[y][x] != '1')
				ft_map_error("ERROR\nMAP HAS TO BE SURROUNDED BY WALLS\n");
			else if ((y == (data->size_y / IMG_H - 1)
					|| x == (data->size_x / IMG_W - 1))
				&& data->map->map[y][x] != '1')
				ft_map_error("ERROR\nMAP HAS TO BE SURROUNDED BY WALLS\n");
			x++;
		}
		y++;
	}
}

static void	ft_check_content(t_data *data)
{
	int	y;
	int	exit;
	int	player;

	exit = 0;
	player = 0;
	data->map->prizes = 0;
	y = 0;
	while (data->map->map && data->map->map[y])
	{
		exit += ft_count_specific_c(data->map->map[y], 'E');
		player += ft_count_specific_c(data->map->map[y], 'P');
		data->map->prizes += ft_count_specific_c(data->map->map[y], 'C');
		y++;
	}
	if (player != 1)
		ft_map_error("ERROR\nONLY VALID MAP IF ONE PLAYER IS CONTAINED\n");
	if (exit == 0)
		ft_map_error("ERROR\nONLY VALID MAP IF AT LEAST ONE EXIT"
			" IS CONTAINED\n");
	if (data->map->prizes == 0)
		ft_map_error("ERROR\nONLY VALID MAP IF AT LEAST ONE PRIZE"
			" IS CONTAINED\n");
}

static void	ft_input_error(int argc)
{
	if (argc != 2)
	{
		ft_map_error("ERROR\nUSAGE: './so_long mappath/mapname.ber'\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_analyze_input(t_data *data, char **argv, int argc)
{
	int		fd;
	int		i;
	int		bytes;
	char	buffer[2];

	ft_input_error(argc);
	i = 0;
	bytes = 1;
	buffer[1] = '\0';
	fd = open(argv[1], O_RDONLY);
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes != 1)
			break ;
		if (buffer[0] != '\n' && buffer[0] != '\0')
		{
			data->map->map[i] = ft_strjoin(data->map->map[i], buffer);
		}
		else
			i++;
	}
	ft_check_content(data);
	ft_check_borders(data);
	close(fd);
}
