#include "minishell.h"
#include "libft.h"

static void	ft_set_fd(t_cmd *cmd)
{
	if (cmd->in_fd)
		dup2(cmd->in_fd, STDIN);
	if (cmd->out_fd > 1 && cmd->pipe[P_WRITE] > 0)
	{
		dup2(cmd->out_fd, STDOUT);
		close(cmd->pipe[P_WRITE]);
	}
	else if (cmd->out_fd > 1)
		dup2(cmd->out_fd, STDOUT);
	else if (cmd->pipe[P_WRITE] > 0)
		dup2(cmd->pipe[P_WRITE], STDOUT);
	close(cmd->in_fd);
	close(cmd->out_fd);
	close(cmd->pipe[P_READ]);
	close(cmd->pipe[P_WRITE]);
}

static void	ft_child_proc(t_cmd *cmd)
{
	// if (cmd->path) -> cmd |
	if (cmd->path && !cmd->path[0])
	{
		ft_putstr_fd("bash : ", 2);
		ft_putstr_fd(cmd->argv[0], 2);
		ft_putstr_fd(": command not found", 2);
		exit(127);
	}
	ft_set_fd(cmd);
	execve(cmd->path, cmd->argv, cmd->envp);
	exit(1);
}

static void	ft_clear_cmd(t_cmd *cmd)
{
	int	i;

	close(cmd->pipe[P_WRITE]);
	close(cmd->in_fd);
	close(cmd->out_fd);
	free(cmd->path);
	cmd->path = NULL;
	i = -1;
	while(cmd->argv[++i])
		free(cmd->argv[i]);
	free(cmd->argv);
	cmd->argv = NULL;
}

void	ft_cmd_run(t_cmd *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		ft_error("fork fail\n");
	else if (pid == 0)
		ft_child_proc(cmd);
	ft_clear_cmd(cmd);
	cmd->last_pid = pid;
}
