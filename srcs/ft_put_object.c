/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:05:19 by lmorais-          #+#    #+#             */
/*   Updated: 2023/12/01 10:05:30 by lmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_put_object(t_data *data, char *relative_path)
{
	int		img_width;
	int		img_height;

	data->map->object = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	mlx_put_image_to_window(data->mlx, data->win, data->map->object,
		(data->map->x * IMG_W), (data->map->y * IMG_H));
}
