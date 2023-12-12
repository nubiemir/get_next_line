/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:00:20 by famir             #+#    #+#             */
/*   Updated: 2023/12/12 21:33:37 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	split_new_line(char *str, int index, char **left, char **right)
{
	int		counter;

	counter = 0;
	*left = (char *)malloc((index + 2) * sizeof(char));
	if ((BUFFER_SIZE - index) > 1)
		*right = (char *)malloc((BUFFER_SIZE - index) * sizeof(char));
	if (!left)
		return (safe_free((void **) right));
	if (!right)
		return (safe_free((void **) left));
	while (counter < index + 1 && str[counter])
	{
		(*left)[counter] = str[counter];
		counter++;
	}
	(*left)[counter] = '\0';
	if (str[counter])
		*right = str + counter;
}

t_bool	line_exist(t_queue *queue, char **str)
{
	int		i;
	char	*temp;
	char	*left;
	char	*right;

	temp = *str;
	i = 0;
	while (temp && temp[i])
	{
		if (temp[i] == '\n')
		{
			split_new_line(temp, i, &left, &right);
			enqueue(queue, left, i + 1);
			*str = right;
			return (TRUE);
		}
		i++;
	}
	enqueue(queue, *str, i);
	*str = NULL;
	return (FALSE);
}

char	*handle_remainder(t_queue *queue, char **remainder)
{
	char	*line;

	if (!(*remainder))
		return (NULL);
	if (line_exist(queue, remainder))
	{
		line = dequeue(queue);
		return (line);
	}
	return (NULL);
}

t_bool	read_file(int fd, t_queue *queue, char **remainder)
{
	int		bytes_read;
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (FALSE);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == 0)
		return (FALSE);
	buffer[bytes_read] = '\0';
	while (!line_exist(queue, &buffer))
	{
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (FALSE);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			return (FALSE);
		buffer[bytes_read] = '\0';
	}
	*remainder = buffer;
	return (TRUE);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	t_queue		*queue;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (BUFFER_SIZE > 2147483647)
		return (NULL);
	queue = create_queue();
	line = handle_remainder(queue, &remainder);
	if (!line)
	{
		if (read_file(fd, queue, &remainder) == FALSE)
			remainder = NULL;
		line = join_queue(queue);
	}
	safe_free((void **)&queue);
	return (line);
}
