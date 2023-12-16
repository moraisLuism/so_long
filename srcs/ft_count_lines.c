/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:37:28 by lmorais-          #+#    #+#             */
/*   Updated: 2023/12/01 09:37:34 by lmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_count_lines(int fd, int x, int img_w)
{
	char	*line;
	int		linecount;

	linecount = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if ((int)ft_strlen(line) < x / img_w
			|| (ft_strlen(line) == 1 && *line != '\n'))
		{
			free(line);
			ft_exit_error();
		}
		else
		{
			free(line);
			linecount++;
		}
	}
	return (linecount);
}
