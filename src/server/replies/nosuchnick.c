#include "../../../inc/server.h"

void	err_nosuchnick(t_users *user, char *nick)
{
	int		len;
	char	buf[MAX_INPUT_LEN + CRLF];

	len = snprintf(buf, MAX_INPUT_LEN + CRLF, ERR_NOSUCHNICK, nick);
	circular_send(user->socket, buf, len);
}
