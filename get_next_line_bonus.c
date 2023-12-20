/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:00:20 by famir             #+#    #+#             */
/*   Updated: 2023/12/20 21:13:07 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_bool	line_exist(t_queue *queue, char **str)
{
	int		i;
	char	*temp;
	char	*right;

	if (!queue || !(*str))
		return (FALSE);
	temp = *str;
	i = 0;
	while (temp && temp[i])
	{
		if (temp[i] == '\n')
		{
			right = ft_strdup((*str), i + 1, BUFFER_SIZE);
			enqueue(queue, (*str), i + 1);
			safe_free((void **) str);
			*str = right;
			return (TRUE);
		}
		i++;
	}
	enqueue(queue, *str, i);
	safe_free((void **) str);
	return (FALSE);
}

char	*handle_remainder(t_queue *queue, char **remainder)
{
	char	*line;

	if (!(remainder) || !queue)
		return (NULL);
	if (line_exist(queue, remainder))
	{
		line = join_queue(queue);
		return (line);
	}
	return (NULL);
}

t_bool	read_file(int fd, t_queue *queue, char **remainder)
{
	int		bytes_read;
	char	*buffer;

	buffer = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (FALSE);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == 0 || bytes_read < 0)
		return (safe_free((void **) &buffer), FALSE);
	buffer[bytes_read] = '\0';
	while (!line_exist(queue, &buffer))
	{
		buffer = (char *)malloc(((size_t) BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (FALSE);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0 || bytes_read < 0)
			return (safe_free((void **) &buffer), FALSE);
		buffer[bytes_read] = '\0';
	}
	*remainder = buffer;
	return (TRUE);
}

char	*get_next_line(int fd)
{
	static char	*remainder[1024];
	t_queue		*queue;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (BUFFER_SIZE > 2147483647)
		return (NULL);
	queue = create_queue();
	line = handle_remainder(queue, &remainder[fd]);
	if (!line)
	{
		if (read_file(fd, queue, &remainder[fd]) == FALSE)
			remainder[fd] = NULL;
		line = join_queue(queue);
	}
	free_queue(&queue);
	return (line);
}

void	safe_free(void **ptr)
{
	if (ptr == NULL)
		return ;
	free(*ptr);
	*ptr = NULL;
}
