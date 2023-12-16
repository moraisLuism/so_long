/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:38:36 by lmorais-          #+#    #+#             */
/*   Updated: 2023/12/04 16:53:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_exit_error(void)
{
	ft_printf("ERROR\nWRONG MAP DIMENSIONS\n");
	exit(EXIT_FAILURE);
}
