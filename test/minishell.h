#ifndef MINISHELL_H
# define MINISHELL_H

enum e_token_type
{
	CMD = 0,
	REDI_L,
	REDI_R,
	DREDI_L,
	DREDI_R
};

typedef struct s_token
{
	int		type;
	char	*token;
}			t_token;

typedef struct s_tree_node
{
	t_token	data;
	int		visited;

	struct s_tree_node	*left;
	struct s_tree_node	*right;
} t_tree_node;

typedef struct s_tree
{
	struct s_tree_node	*root;
} t_tree;

typedef struct s_cmd
{
	char	*path;
	char	**argv;
	int		in_fd;
	int		out_fd;
}	t_cmd;


t_tree		*create_bin_tree(t_tree_node root_node);
t_tree_node	*insert_left_node(t_tree_node *parent, t_tree_node child);
t_tree_node	*insert_right_node(t_tree_node *parent, t_tree_node child);
void		delete_tree(t_tree *tree);

void	ft_error(char *str);
// t_tree	*parser(char *str);
// void	ft_parsing(t_tree *tree, char *cmd_line);

#endif