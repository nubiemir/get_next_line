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
    int index;
    int counter;

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

char *handle_remainder(t_queue *queue, char *remainder)
{
    char *buffer;
    char **split_buffer;
    int *line_exist;

    if (!remainder)
        return NULL;
    line_exist = find_line(remainder);
    // I have reached here::::::::::::comeback here::::
    while (!line_exist[0] && remainder)
    {
        buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
        ft_memcpy(buffer, remainder, BUFFER_SIZE);
        enqueue(queue, buffer);
        remainder = remainder + BUFFER_SIZE;
        line_exist = find_line(remainder);
    }
    if (line_exist[0])
    {
        split_buffer = split_new_line(remainder);
        enqueue(queue, split_buffer[0]);
        return (split_buffer[1]);
    }
    return (NULL);
}

char *read_file(int fd, t_queue *queue)
{
    int bytes_read;
    char *buffer;
    char **split_buffer;
    int *line_exist;

    buffer = (char *)malloc((BUFFER_SIZE) * sizeof(char));
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read == 0)
        return (NULL);
    line_exist = find_line(buffer);
    while (!line_exist[0])
    {
        enqueue(queue, buffer);
        buffer = (char *)malloc((BUFFER_SIZE) * sizeof(char));
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == 0)
            return (NULL);
        line_exist = find_line(buffer);
    }
    if (line_exist[0])
    {
        split_buffer = split_new_line(buffer);
        enqueue(queue, split_buffer[0]);
        return (split_buffer[1]);
    }
    return (NULL);
}

char *get_next_line(int fd)
{
    static char *buffer;
    t_queue *queue;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (BUFFER_SIZE > 2147483647)
        return (NULL);
    queue = create_queue();
    line = handle_remainder(queue, buffer);
    if (!line)
    {
        buffer = read_file(fd, queue);
        // printf("rear: %s\n", queue->rear->data);
        line = "queue joined\n";
    }
    printf("first: %s\n", queue->front->data);
    printf("second: %s\n", queue->front->next->data);
    printf("remainder: %s\n", buffer);

    return (line);
}