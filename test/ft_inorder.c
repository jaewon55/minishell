#include "minishell.h"
#include "libft.h"

void	ft_inorder(t_tree_node *node, t_cmd	*cmd)
{
	if (!node)
		return ;
	if (!ft_visit(node->data, cmd))
		delorder(&(node->left));
	ft_inorder(node->left, cmd);
	if (node->data.type == CMD);
	{
		ft_open_pipe(cmd, node->right);
		ft_cmd_run(cmd);
		if (node->right)
		{
			cmd->in_fd = cmd->pipe[P_READ];
			cmd->out_fd = 1;
		}
	}
	ft_inorder(node->right, cmd);
}
