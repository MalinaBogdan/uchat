#include "../../../inc/server.h"

static void	send_response(t_users *user, char *nick,char *text)
{
    int		len;
    char	buf[MAX_INPUT_LEN + CRLF];

    len = snprintf(buf, MAX_INPUT_LEN + CRLF, CHANNEL_MSG,
                   ((t_channel*)user->chan)->name, nick, text);
    circular_send(user->socket, buf, len);
}

void irc_gethistory(t_server *server, t_users *user, char **command) {
    int				len;
    char			to_send[MAX_INPUT_LEN + CRLF];
    t_channel_user	*usr_list;

    ft_memset(to_send, 0x0, MAX_INPUT_LEN + CRLF);
    usr_list = ((t_channel*)user->chan)->users;
    if (usr_list == NULL)
        return ;
    db_sendhistory(user,((t_channel*)user->chan)->name,send_response);
}

