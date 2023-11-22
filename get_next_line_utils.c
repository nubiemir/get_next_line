/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:56:42 by famir             #+#    #+#             */
/*   Updated: 2023/11/19 17:09:15 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int *find_line(char *str)
{
    int counter;
    int *res;

    counter = 0;
    res = malloc(sizeof(int) * 2);
    while (counter < BUFFER_SIZE)
    {
        if (str[counter] == '\n')
        {
            res[0] = 1;
            res[1] = counter;
            return (res);
        }
        counter++;
    }
    res[0] = 0;
    res[1] = 0;
    return (res);
}

t_queue *create_queue()
{
	t_queue *queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue->front = queue->rear = NULL;
	return queue;
}

void enqueue(t_queue *queue, char *data)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = data;
	new_node->next = NULL;

	if (queue->front == NULL)
	{
		queue->front = queue->rear = new_node;
	}
	else
	{
		queue->rear->next = new_node;
		queue->rear = new_node;
	}
}
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!(char *) dst && !(char *) src)
		return (0);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
