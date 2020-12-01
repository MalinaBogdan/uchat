#include "../../../inc/server.h"

void	err_needmoreparams(t_users *user, char *command)
{
	int		len;
	char	buf[MAX_INPUT_LEN + CRLF];

	len = snprintf(buf, MAX_INPUT_LEN + CRLF, ERR_NEEDMOREPARAMS, command);
	circular_send(user->socket, buf, len);
}
