/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:00:20 by famir             #+#    #+#             */
/*   Updated: 2023/10/30 20:01:48 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int find_line(char *str)
{
    int counter;

    counter = 0;
    while (counter < BUFFER_SIZE)
    {
        if (str[counter] == '\n')
        {
            if (str[counter + 1])
                str = str + (counter + 1);
            return (1);
        }
        counter++;
    }
    return (0);
}

t_queue *read_file(int fd)
{
    int bytes_read;
    t_queue *queue;
    char *buffer;

    buffer = (char *)malloc((BUFFER_SIZE) * sizeof(char));
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read == 0)
        return (NULL);
    queue = create_queue();
    while (!find_line(buffer))
    {
        enqueue(queue, buffer);
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == 0)
            return (NULL);
    }
    return (queue);
}

char *get_next_line(int fd)
{
    static char *buffer;
    // char *line;

    buffer = malloc((BUFFER_SIZE) * sizeof(char));
    t_queue *queue = read_file(fd);
    printf("first: %s\n", queue->rear->data);
    printf("buffer: %s\n", buffer);
    return (buffer);
}
