#include "../../../inc/server.h"

void	err_nosuchchannel(t_users *user, char *channel)
{
	int		len;
	char	buf[MAX_INPUT_LEN + CRLF];

	len = snprintf(buf, MAX_INPUT_LEN + CRLF, ERR_NOSUCHCHANNEL, channel);
	circular_send(user->socket, buf, len);
}
