#include "parsing.h"

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}

void	parsing(char *file)
{
	int		fd;
	char	*line;
	t_pars	pars;

	pars.id = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("File doesn't exist\n");
	file = get_next_line(fd);
	if (!file)
		ft_error("Empty map\n");
	while (file)
	{
		
		file = get_next_line(fd);
	}
	
}
