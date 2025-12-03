
#include "pipex.h"

static void	free_paths(char **paths)
{
	int	i;

	if (!paths)
		return ;
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
}

static char	**get_paths(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	return (ft_split(envp[i] + 5, ':'));
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*temp;
	int		i;

	paths = get_paths(envp);
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (!temp)
			return (free_paths(paths), NULL);
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (!path)
			return (free_paths(paths), NULL);
		if (access(path, F_OK) == 0)
			return (free_paths(paths), path);
		free(path);
	}
	return (free_paths(paths), NULL);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	if (!argv || !argv[0])
		exit(127);
	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0])
	{
		if (cmd)
			free(cmd);
		exit(127);
	}
	path = find_path(cmd[0], envp);
	if (!path)
		cmd_not_found(cmd);
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		i = -1;
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		error();
	}
}
