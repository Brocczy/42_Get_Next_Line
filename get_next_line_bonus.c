/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:41:46 by amarques          #+#    #+#             */
/*   Updated: 2022/04/19 18:36:25 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	int			byte_read;
	static char	cloud[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (NULL);
	line = NULL;
	byte_read = 1;
	while (byte_read)
	{
		if (!cloud[fd][0])
			byte_read = read(fd, cloud[fd], BUFFER_SIZE);
		if (byte_read > 0)
			line = joinstr(line, cloud[fd]);
		if (byte_read < 1 || nl_check(cloud[fd]))
			return (line);
	}
	return (line);
}
