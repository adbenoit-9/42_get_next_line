/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 22:09:02 by adbenoit          #+#    #+#             */
/*   Updated: 2021/01/06 22:09:26 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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
		printf("|%d| %s\n", ret, line);
		ret = get_next_line(fd, &line);
	}
	printf("|%d| %s\n", ret, line);
	close(fd);
}
