#include "minishell.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

static void	ft_write_input(char *str, int out_fd, size_t len)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '`' || str[i] == '$' )
	}
}

static void	ft_read_input(char *limiter, int out_fd)
{
	char	*str;
	size_t	len;

	str = NULL;
	while (1)
	{
		str = readline(">");
		len = ft_strlen(str);
		if (!ft_strncmp(limiter, str, len + 10))
			break ;
		ft_write_input(str, out_fd, len);
		free(str);
	}
	free(str);
	close(out_fd);
}

int	ft_visit_double_redi_left(t_token token, t_cmd *cmd)
{
	if (cmd->in_fd != STDIN)
		close(cmd->in_fd);
	ft_open_pipe(cmd, (t_tree_node *)TRUE);
	cmd->in_fd = cmd->pipe[P_READ];
	ft_read_input(token.token, cmd->pipe[P_WRITE]);
	return (SUCCESS);
}
