#include "minishell.h"
#include "libft.h"

void	ft_visit_cmd(t_token token, t_cmd *cmd)
{
	cmd->argv = ft_split(token.token, ' ');
	if (!cmd->argv)
		ft_error("split malloc fail\n");
	cmd->path = ft_get_path(cmd->argv[0]);
}
