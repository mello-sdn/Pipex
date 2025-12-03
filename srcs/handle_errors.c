
#include "pipex.h"

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

void	cmd_not_found(char **cmd)
{
	int	i;

	ft_putstr_fd(cmd[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	i = -1;
	while (cmd[++i])
		free(cmd[i]);
	free(cmd);
	exit(127);
}
