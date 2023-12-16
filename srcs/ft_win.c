/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:13:32 by lmorais-          #+#    #+#             */
/*   Updated: 2023/12/04 17:03:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_win(t_data *data)
{
	ft_printf("CONGRATULATIONS, YOU FOUND ALL THE PRIZES AND THE EXIT\n");
	ft_printf("YOU WON THE GAME\n");
	ft_printf("IS %d MOVES REALLY THE BEST YOU CAN DO?\n", data->counter);
	exit(EXIT_SUCCESS);
}
