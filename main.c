#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>

int	main()
{
	char *buf;
	int	fd;
	
	fd = open("hola.txt", O_RDONLY);
	buf = get_next_line(fd);
	write(1, buf, ft_strlen(buf));
}