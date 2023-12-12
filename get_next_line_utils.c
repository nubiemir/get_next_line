/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_v2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekeste <htekeste@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:56:42 by famir             #+#    #+#             */
/*   Updated: 2023/12/12 01:04:16 by htekeste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*dequeue(t_queue *queue)
{
	char *data;

	if (!queue || queue->front == NULL)
		return (NULL);
	data = queue->front->data;
	queue->front = queue->front->next;
	if (queue->front == NULL)
		queue->rear = NULL;
	return (data);
}

void	enqueue(t_queue *queue, char *data, int size)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = data;
	new_node->next = NULL;
	if (queue->front == NULL)
	{
		queue->front = new_node; 
		queue->rear = new_node;
	}
	else
	{
		queue->rear->next = new_node;
		queue->rear = new_node;
	}
	queue->size += size;
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

char	*join_queue(t_queue *queue)
{
	char	*res;
	int		counter;
	int		res_size;

	counter = 0;
	res_size = 0;
	res = (char *)malloc(queue->size * sizeof(char));
	while (queue->front)
	{
		while (queue->front->data[counter])
			res[res_size++] = queue->front->data[counter++];
		counter = 0;
		queue->front = queue->front->next;
	}
	if (res_size == 0)
		return (NULL);
	return (res);
}

t_queue	*create_queue(void)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
	return (queue);
}
