#include "minishell.h"
#include "libft.h"
#include <stdlib.h>

static void	ft_split_free(char **split_pipe)
{
	int	i;

	i = -1;
	while (split_pipe[++i])
		free(split_pipe[i]);
	free(split_pipe);
}

t_tree	*parser(char *str)
{
	char	**split_pipe;
	t_tree	*tree;
	int		i;

	split_pipe = ft_split(str, '|');
	if (!split_pipe)
		ft_error("split_pipe fail\n");
	tree = ft_create_tree(); //
	if (!tree)
	{
		ft_split_free(split_pipe);
		ft_error("malloc tree fail\n");
	}
	while (split_pipe[i])
	{
		if (is_valid_cmd(split_pipe[i]))
			ft_parsing(tree, split_pipe[i]);
		else
		{
			delete_tree(&tree);
			break ;
		}
	}
	ft_split_free(split_pipe);
	return (tree);
}
