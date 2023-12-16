/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:40:38 by lmorais-          #+#    #+#             */
/*   Updated: 2023/12/01 09:40:42 by lmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_key_event_handler(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_exit(data);
	else if (keycode == W)
		ft_move(data, 'y', UP);
	else if (keycode == A)
		ft_move(data, 'x', LEFT);
	else if (keycode == S)
		ft_move(data, 'y', DOWN);
	else if (keycode == D)
		ft_move(data, 'x', RIGHT);
	if (data->map->map[data->p_y][data->p_x] == 'E')
		ft_win(data);
	return (0);
}
