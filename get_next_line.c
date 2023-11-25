/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:00:20 by famir             #+#    #+#             */
/*   Updated: 2023/11/25 19:37:40 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char **split_new_line(char *str, int index)
{
    char **res;
    int counter;

    counter = 0;
    res = (char **)malloc(3 * sizeof(char **));
    res[0] = (char *)malloc((index + 1) * sizeof(char));
    res[1] = (char *)malloc((BUFFER_SIZE - index ) * sizeof(char));
    while (counter < index + 1 && str[counter])
    {
        res[0][counter] = str[counter];
        counter++;
    }
    if (str[counter])
        res[1] = str + counter;
    else
        res[1] = NULL;
    return (res);
}

char *handle_remainder(t_queue *queue, char *remainder)
{
    char *buffer;
    char **split_buffer;
    int *line_exist;

    if (!remainder)
        return NULL;
    line_exist = find_line(remainder);
    while (!line_exist[0] && *remainder)
    {
        buffer = (char *)malloc(line_exist[1]  * sizeof(char));
        ft_memcpy(buffer, remainder, line_exist[1]);
        enqueue(queue, buffer);
        remainder = remainder + line_exist[1];
        line_exist = find_line(remainder);
    }
    if (line_exist[0])
    {
        split_buffer = split_new_line(remainder, line_exist[1]);
        enqueue(queue, split_buffer[0]);
        remainder = split_buffer[1];
        return remainder;
    }
    return (NULL);
}

char *read_file(int fd, t_queue *queue)
{
    int bytes_read;
    char *buffer;
    char **split_buffer;
    int *line_exist;

    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read == 0)
        return (NULL);
    buffer[bytes_read] = '\0';
    line_exist = find_line(buffer);
    while (!line_exist[0])
    {
        enqueue(queue, buffer);
        buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == 0)
            return (NULL);
        buffer[bytes_read] = '\0';
        line_exist = find_line(buffer);
    }
    if (line_exist[0])
    {
        split_buffer = split_new_line(buffer, line_exist[1]);
        enqueue(queue, split_buffer[0]);
        return (split_buffer[1]);
    }
    return (NULL);
}

char *get_next_line(int fd)
{
    static char *remainder;
    t_queue *queue;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (BUFFER_SIZE > 2147483647)
        return (NULL);
    queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue->front = queue->rear = NULL;
    remainder = handle_remainder(queue, remainder);
    if (queue->rear)
    {
        if (!find_line(queue->rear->data)[0])
            remainder = read_file(fd, queue);
    }else 
        remainder = read_file(fd, queue);
    line = join_queue(queue);
    if (line == NULL)
        return (NULL);
    return (line);
}
