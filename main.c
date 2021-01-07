/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 22:09:02 by adbenoit          #+#    #+#             */
/*   Updated: 2021/01/07 11:58:01 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	int		ret;
	int		fd;
	char	*line;

	(void)ac;
	line = NULL;
	fd = open(av[1], O_RDONLY);
	ret = get_next_line(fd, &line);
	while (ret == 1)
	{
		printf("\033[33m|%d|\033[0m %s\n", ret, line);
		ret = get_next_line(fd, &line);
	}
	if (ret == 0)
		printf("\033[32m|%d|\033[0m %s\n", ret, line);
	else
		printf("\033[31m|%d|\033[0m %s\n", ret, line);
	close(fd);
}
