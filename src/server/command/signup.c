#include "../../../inc/server.h"

static bool	is_available(t_users *usr_list, t_users *user, char *nick, int size)
{
    t_users *tmp;

    tmp = usr_list;
    while (tmp != NULL)
    {
        if (user->socket != tmp->socket)
        {
            if (ft_strncmp(tmp->nick.nick, nick,  \
				size > tmp->nick.nick_len ? size : tmp->nick.nick_len) == 0)
                return (false);
        }
        tmp = tmp->next;
    }
    return (true);
}

static bool	check_nick(t_users *users_list, t_users *user, char *nick, int size)
{
    if (size < 1 || size > MAX_NICK_LEN)
    {
        err_erroneusnickname(user, nick);
        return (false);
    }
    if (is_available(users_list, user, nick, size) != true)
    {
        err_nicknameinuse(user, nick);
        return (false);
    }
    return (true);
}
static void	send_response_bad(t_users *user)
{
    int		len;
    char	buf[MAX_INPUT_LEN + CRLF];

    len = snprintf(buf, MAX_INPUT_LEN + CRLF, SIGN_BAD);
    circular_send(user->socket, buf, len);
}

static void	send_response_good(t_users *user)
{
    int		len;
    char	buf[MAX_INPUT_LEN + CRLF];

    len = snprintf(buf, MAX_INPUT_LEN + CRLF, SIGN_GOOD);
    circular_send(user->socket, buf, len);
}

void irc_signup(t_server *server, t_users *user, char **command) {
    char *tmp = strdup(command[1]);
    char *nick = strdup(db_getfield(tmp, 1));
    free(tmp);
    tmp = strdup(command[1]);
    char *password = strdup(db_getfield(tmp, 2));
    free(tmp);
    if (check_nick(server->users, user, nick, (int) strlen(nick)) != true)
        return;
    if (db_checkuser(nick)||!db_validatenick(nick)) {
        send_response_bad(user);
        return;
    }
    db_adduser(nick,password);
    if (!db_validateuser(user,nick,password))
        send_response_bad(user);
    else
        send_response_good(user);
    free(nick);
    free(password);
}
