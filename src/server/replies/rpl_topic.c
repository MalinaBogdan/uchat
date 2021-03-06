/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_topic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <ddinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:58:48 by ddinaut           #+#    #+#             */
/*   Updated: 2019/09/30 14:52:01 by Dje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/server.h"

void	rpl_topic(t_channel *chan, t_users *user)
{
	int		len;
	char	buf[MAX_INPUT_LEN + CRLF];

	memset(buf, 0x0, sizeof(buf));
	len = snprintf(buf, MAX_INPUT_LEN + CRLF, \
		RPL_TOPIC, chan->name, chan->topic);
	circular_send(user->socket, buf, len);
}
