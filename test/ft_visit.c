#include "minishell.h"

void	ft_visit(t_token token, t_cmd *cmd)
{
	if (token.type == CMD)
		ft_visit_cmd(token, cmd);
	else if (token.type == REDI_L)
		ft_visit_redi_left(token, cmd);
	else if (token.type == REDI_R)
		ft_visit_redi_right(token, cmd);
	else if (token.type == DREDI_L)
		ft_visit_double_redi_left(token, cmd);
	else
		ft_visit_double_redi_right(token, cmd);
}
