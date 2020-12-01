#include "../../inc/server.h"

t_channel	*channel_create(char *name)
{
	int			len;
	t_channel	*new_chan;

	if (!(new_chan = malloc(sizeof(t_channel))))
		return (NULL);
	len = ft_strlen(name);
	if (len > MAX_CHAN_LEN)
		len = MAX_CHAN_LEN;
	ft_memset(new_chan->topic, 0x0, MAX_TOPIC_LEN + 1);
	ft_memset(new_chan->name, 0x0, MAX_CHAN_LEN + 1);
	ft_memcpy(new_chan->name, name, len);
	new_chan->num = 0;
	new_chan->name_len = len;
	new_chan->users = NULL;
	new_chan->next = NULL;
	printf("[LOG +] Channel created '%s'\n", new_chan->name);
	return (new_chan);
}

t_channel	*channel_add(t_channel **chan, char *name)
{
	t_channel *tmp;

	if (!db_checkchat(name)) {
	    db_createchat(name);
	}

	if ((*chan) == NULL)
	{
		(*chan) = channel_create(name);
		return (*chan);
	}
	else
	{
		tmp = (*chan);
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = channel_create(name);
		return (tmp->next);
	}
}

t_channel	*channel_search(t_channel **chan, char *name)
{
	int			len;
	t_channel	*tmp;

	tmp = (*chan);
	len = ft_strlen(name);
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->name, name, \
				len > tmp->name_len ? len : tmp->name_len) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void		channel_delete(t_channel **channel, char *name)
{
	int			len;
	t_channel	*tmp;
	t_channel	*prev;

	prev = NULL;
	tmp = (*channel);
	len = ft_strlen(name);
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->name, name, \
				len > tmp->name_len ? len : tmp->name_len) == 0)
		{
			printf("[LOG -] Remove channel '%s'\n", tmp->name);
			if (prev == NULL)
				(*channel) = tmp->next;
			else
				prev->next = tmp->next;
			channel_user_remove_all(&tmp->users);
			free(tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
