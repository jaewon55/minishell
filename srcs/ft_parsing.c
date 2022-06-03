#include "minishell.h"
#include "libft.h"

static	t_token	ft_init_redirection_token(char *str, int *i)
{
	t_token	token;

	ft_memset(&token, 0, sizeof(token));
	if (str[*i] == '<')
	{
		if (str[*i + 1] == '<')
			token.type = DREDI_L;
		else if (str[*i + 1] == '>' || str[*i + 1] == '|')
	}
	else

}

void	ft_parsing(t_tree *tree, char *cmd_line)
{
	t_token	element;
	int		i;

	i = -1;
	while (cmd_line[++i])
	{
		if (cmd_line[i] == '<' || cmd_line == '>')
		{
			element = ft_init_redirection_token(cmd_line, &i);
		}
	}
	}
}
