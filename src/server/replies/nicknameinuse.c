#include "../../../inc/server.h"

void	err_nicknameinuse(t_users *user, char *nick)
{
	int		len;
	char	buf[MAX_INPUT_LEN + CRLF];

	len = snprintf(buf, MAX_INPUT_LEN + CRLF, ERR_NICKNAMEINUSE, nick);
	circular_send(user->socket, buf, len);
}
