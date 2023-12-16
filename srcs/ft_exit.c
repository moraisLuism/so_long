/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:38:59 by lmorais-          #+#    #+#             */
/*   Updated: 2023/12/01 09:39:04 by lmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_printf("YOU GAVE UP\n");
	ft_printf("IS THE MAP TO HARD FOR YOU?\n");
	exit(EXIT_SUCCESS);
}
