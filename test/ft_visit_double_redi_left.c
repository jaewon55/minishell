#include "minishell.h"
#include <fcntl.h>

int	ft_visit_double_redi_left(t_token token, t_cmd *cmd)
{
	if (cmd->out_fd > 1)
		close(cmd->out_fd);
	return (SUCCESS);
}
