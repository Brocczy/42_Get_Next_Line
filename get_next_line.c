/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:50:51 by amarques          #+#    #+#             */
/*   Updated: 2022/05/26 12:33:14 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	cloud[BUFFER_SIZE + 1];
	int			byte_read;

	line = NULL;
	byte_read = 1;
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	while (byte_read)
	{
		if (!cloud[0])
			byte_read = read(fd, cloud, BUFFER_SIZE);
		if (byte_read > 0)
			line = joinstr(line, cloud);
		if (nl_check(cloud) || byte_read < 1)
			break ;
	}
	return (line);
}
