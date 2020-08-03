#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	int	ret;
	int fd;
	char *line;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	ret = get_next_line(fd, &line);
	printf("test %d\n", fd);
	while (ret == 1)
	{
		printf("-%d %s\n", ret, line);
		ret = get_next_line(fd, &line);
	}
	printf("-%d %s\n", ret, line);
	close(fd);
}
