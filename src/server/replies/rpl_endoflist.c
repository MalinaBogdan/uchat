#include "../../../inc/server.h"

void	rpl_endoflist(t_users *user, char *buf)
{
	int	len;

	len = snprintf(buf, MAX_INPUT_LEN + CRLF, RPL_ENDOFLIST);
	circular_send(user->socket, buf, len);
}
