/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:00:20 by famir             #+#    #+#             */
/*   Updated: 2023/11/19 17:10:37 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char **split_new_line(char *str)
{
    char **res;
    int    index;
    int    counter;
    
    counter = 0;
    res = (char **)malloc(3 * sizeof(char **));
    index = find_line(str)[1];
    res[0] = (char *)malloc((index + 1) * sizeof(char));
    res[1] = (char *)malloc((BUFFER_SIZE - index - 1) * sizeof(char));
    while (counter < index + 1 && str[counter])
    {
        res[0][counter] = str[counter];
        counter++;
    }
    res[1] = str + counter;
    return (res);
}

char *read_file(int fd, t_queue *queue, char *remainder)
{
    int bytes_read;
    char *buffer;
    char **split_buffer;

    if (remainder)
    {
        while (!find_line(remainder)[0])
        {
            enqueue(queue, remainder);
            remainder = remainder + BUFFER_SIZE;
        }
        split_buffer = split_new_line(remainder);
        enqueue(queue, split_buffer[0]);
        return (split_buffer[1]);
    }
    buffer = (char *)malloc((BUFFER_SIZE) * sizeof(char));
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read == 0)
        return (NULL);
    while (!find_line(buffer)[0])
    {
        enqueue(queue, buffer);
        buffer = (char *)malloc((BUFFER_SIZE) * sizeof(char));
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == 0)
            return (NULL);
    }
    split_buffer = split_new_line(buffer);
    enqueue(queue, split_buffer[0]);
    return (split_buffer[1]);
}

char *get_next_line(int fd)
{
    static char *buffer;
    t_queue *queue;
    // char *line;
    queue = create_queue();

    buffer = read_file(fd, queue, "hel\nworld");
    
    printf("first: %s\n", queue->front->data);
    // printf("second: %s\n", queue->front->next->data);
    printf("rear: %s\n", queue->rear->data);
    // printf("remainder: %s\n", buffer);
    return (buffer);
}
