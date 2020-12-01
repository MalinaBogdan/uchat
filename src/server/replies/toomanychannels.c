/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toomanychannels.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <ddinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:57:38 by ddinaut           #+#    #+#             */
/*   Updated: 2019/10/01 11:33:08 by Dje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/server.h"

void	err_toomanychannels(t_users *user, char *chan_name)
{
	int		len;
	char	buf[MAX_INPUT_LEN + CRLF];

	len = snprintf(buf, MAX_INPUT_LEN + CRLF, ERR_TOOMANYCHANNELS, chan_name);
	circular_send(user->socket, buf, len);
}
