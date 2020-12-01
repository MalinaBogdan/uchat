#include "../../../inc/server.h"

void	err_erroneuschar(t_users *user)
{
	int		len;
	char	buf[MAX_INPUT_LEN + CRLF];

	len = snprintf(buf, MAX_INPUT_LEN + CRLF, ERR_ERRONEUSCHAR);
	circular_send(user->socket, buf, len);
}
