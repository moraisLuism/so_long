/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:44:36 by lmorais-          #+#    #+#             */
/*   Updated: 2023/12/04 17:06:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_render_next_frame(t_data *data)
{
	ft_put_background(data);
	ft_init_map(data);
	mlx_hook(data->win, 17, 1L << 2, ft_exit, data);
	mlx_key_hook(data->win, ft_key_event_handler, data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;

	ft_window_size(&data, argv);
	map.map = ft_calloc(data.size_y + 1, sizeof(char *));
	if (!map.map)
	{
		perror("ERROR\nCALLOC FAILED\n");
		exit(EXIT_FAILURE);
	}
	ft_init_data(&data, &map);
	ft_analyze_input(&data, argv, argc);
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		perror("ERROR\nPROGRAMM INIT FAILED\n");
		exit(EXIT_FAILURE);
	}
	data.win = mlx_new_window(data.mlx, data.size_x,
			data.size_y, "./so_long");
	ft_render_next_frame(&data);
	mlx_loop(data.mlx);
	perror("ERROR\nLOOP FAILED\n");
	exit(EXIT_FAILURE);
}
