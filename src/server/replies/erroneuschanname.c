#include "../../../inc/server.h"

void	err_erroneuschanname(t_users *user, char *name)
{
	int		len;
	char	buf[MAX_INPUT_LEN + CRLF];

	len = snprintf(buf, MAX_INPUT_LEN + CRLF, ERR_ERRONEUSCHANNAME, name);
	circular_send(user->socket, buf, len);
}
