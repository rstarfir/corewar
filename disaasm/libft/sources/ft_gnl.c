/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:45:09 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:45:12 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"

/*
** fd_del() function deletes fd data in buffer.
**
** It takes a pointer to double chained looped list BF and a signal ret which is
** reterned in any case and the function extracts current fd-thread with
** dlst_cir_pop(), deletes its snips (single chained list) with lst_ht_del() and
** finally frees the fd-thread.
*/

int	fd_del(t_dlst_cir *bf, int ret)
{
	t_fd	*fd;

	fd = dlst_cir_pop(bf);
	lst_ht_clear(&fd->snips, free);
	free(fd);
	return (ret);
}

/*
** fd_read() function reads BUFF_SIZE bytes from File Descriptor into fd-buffer.
**
** If there is a prepared snip (i.e. existing and empty) in the buffer then the
** data is read into it, otherwise a new one is allocated with malloc(3). Snips
** are stored in single chaned list of structure t_lst_ht and every new one is
** pushed back with lst_ht_push_back(). If pushing fails then newly obtained
** snip is freed.
**
** The function returns ERROR (memory allocation or reading from fd fails)
** or EOF_ (number of bytes read is 0) or OK (any other case) signal.
**
** If number of bytes read is not zero and less then BUFF_SIZE, then end-of-line
** (EOL_ = '\n') char is appended to the data and read size is increased by 1.
**
** The fd_read() function should be followed by fd_del() function in case of
** non-OK output.
*/

int	fd_read(t_dlst_cir *bf)
{
	t_snip	*snip;

	if (FD->snips.len != 0 && SNPH->len == 0)
		snip = SNPH;
	else
	{
		if (!(snip = malloc(sizeof(t_snip))))
			return (ERROR);
		if (lst_ht_push_back(&FD->snips, snip))
		{
			free(snip);
			return (ERROR);
		}
	}
	snip->len = read(FD->fd, snip->str, BUFF_SIZE);
	snip->offset = 0;
	if (snip->len < 0)
		return (ERROR);
	else if (snip->len == 0)
		return (EOF_);
	else if (snip->len < BUFF_SIZE && snip->str[snip->len - 1] != EOL_)
		snip->str[snip->len++] = EOL_;
	return (OK);
}

/*
** fd_get() function obtains a buffer to handle fd.
**
** If fd is already in the buffer, then it makes it current in the buffer,
** otherwise the function creates a new one with malloc(3) and pushes it into
** double chaned list of structure t_dlst_cir pointed to by bf.
**
** If a new buffer for fd should be created then fd_get() initially reads from
** File Descriptor with fd_read() function.
**
** If no memory available for allocating new fd-buffer, then ERROR returned. If
** pushing fails then newly created fd is freed and ERROR returned. fd-buffer is
** deleted if non-OK value returuned from fd_read() and the value returned.
*/

int	fd_get(int fd, t_dlst_cir *bf)
{
	size_t	i;
	t_fd	*new_fd;
	int		ret;

	i = 0;
	while (i++ < bf->len && FD->fd != fd)
		bf->cur = bf->cur->next;
	if (i > bf->len)
	{
		if (!(new_fd = malloc(sizeof(t_fd))))
			return (ERROR);
		if (dlst_cir_push(bf, new_fd))
		{
			free(new_fd);
			return (ERROR);
		}
		new_fd->fd = fd;
		new_fd->snips.len = 0;
		new_fd->snips.head = NULL;
		new_fd->snips.tail = NULL;
		if ((ret = fd_read(bf)) != OK)
			return (fd_del(bf, ret));
	}
	return (OK);
}

/*
** The fd_process() function scans fd-buffer and acquire a substring
** representing the whole line in the File Descriptor.
**
** fd_process() firstly checks tail-snip for EOL_ presence and if one does not
** exist then reads another snip with fd_read() function until it does.
** Otherwise it collects all the strings in the snips from head to tail (snips
** are stored in the t_lst_ht structure) until EOL_ character in the tail-snip
** by copying them into newly created string with ft_strnew0() function ('\0' is
** appedned). ft_memmove() is used for copying.
**
** Snips are popped with lst_ht_pop() and freed if the length of the list is
** greater then 1. So there is always at least 1 snip in the fd-buffer.
*/

int	fd_process(t_dlst_cir *bf)
{
	size_t	l[2];
	char	*eol_ptr;
	int		ret;

	l[0] = 0;
	while (!(eol_ptr = ft_memchr(SNPT->str + SNPT->offset, EOL_, SNPT->len)))
	{
		l[0] += SNPT->len;
		if ((ret = fd_read(bf)) != OK)
			return (fd_del(bf, ret));
	}
	l[1] = eol_ptr - (SNPT->str + SNPT->offset);
	if (!(FD->line = ft_strnew0(l[0] + l[1])))
		return (ERROR);
	l[0] = 0;
	while (FD->snips.len > 1)
	{
		(void)ft_memmove(FD->line + l[0], SNPH->str + SNPH->offset, SNPH->len);
		l[0] += SNPH->len;
		free(lst_ht_pop(&FD->snips));
	}
	(void)ft_memmove(FD->line + l[0], SNPH->str + SNPH->offset, l[1]);
	SNPH->offset += l[1] + 1;
	SNPH->len -= l[1] + 1;
	return (OK);
}

/*
** DESCRIPTION
** The ft_gnl() function gets new line from File Descriptor (fd) and assigns
** it to the pointer **line. Can work with multiple fd's.
**
** RETURN VALUE
** The function returns -1 if an error occurs (reading, memory allocation or
** line == NULL), 1 if a new line obtained and 0 if fd-thread is empty
** (initailly or just was completely read).
**
** COMMENT
** If reading or memory allocation error occurs or fd-thread is empty then
** current fd-buffer is deleted and ptr *line is not changed.
** All the rest buffers stay the same.
*/

int	ft_gnl(int fd, char **line)
{
	static t_dlst_cir	bf = {0, NULL};
	int					ret;

	if (!line)
		return (ERROR);
	if ((ret = fd_get(fd, &bf)) != OK)
		return (ret);
	if ((ret = fd_process(&bf)) != OK)
		return (ret);
	*line = FD_LINE;
	return (ret);
}
