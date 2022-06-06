#include "minishell.h"
#include "libft.h"

void	ft_inorder(t_tree_node *node, t_cmd	*cmd)
{
	if (!node)
		return ;
	ft_visit(node->data, cmd);
	ft_inorder(node->left, cmd);
	if (node->data.type == CMD);
	{
		ft_cmd_run(cmd);
		cmd->out_fd = 1;
	}
	ft_inorder(node->right, cmd);
}
