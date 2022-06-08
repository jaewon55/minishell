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
}

static void	ft_child_proc(t_cmd *cmd)
{
	ft_set_fd(cmd);
	if (check_path)
	{
		
	}
}

void	ft_cmd_run(t_cmd *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		ft_error("fork fail\n");
	else if (pid == 0)
		ft_child_proc(cmd);
}
