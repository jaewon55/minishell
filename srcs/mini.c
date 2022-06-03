# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

int main(void)
{
	char	*str;
	// t_tree	*tree;

	while (1)
	{
		str = readline(">");
		// tree = parser(str);
		printf("%s\n", str);
		add_history(str);
		free(str);
	}
	return (0);
}
