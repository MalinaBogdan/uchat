#include "../../../inc/server.h"

void	err_erroneusnickname(t_users *user, char *nick)
{
	int		len;
	char	buf[MAX_INPUT_LEN + CRLF];

	len = snprintf(buf, MAX_INPUT_LEN + CRLF, ERR_ERRONEUSNICKNAME, nick);
	circular_send(user->socket, buf, len);
}
