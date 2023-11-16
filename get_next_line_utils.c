/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:56:42 by famir             #+#    #+#             */
/*   Updated: 2023/10/30 19:36:41 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int ft_strlen(const char *s)
{
	unsigned int res;
	unsigned int counter;

	counter = 0;
	res = 0;
	while (s[counter])
	{
		counter++;
		res++;
	}
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

t_bool is_empty(t_queue *queue)
{
	return (queue->front == NULL);
}
void enqueue(t_queue *queue, void *data)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = data;
	new_node->next = NULL;

	if (is_empty(queue))
	{
		queue->front = queue->rear = new_node;
	}
	else
	{
		queue->rear->next = new_node;
		queue->rear = new_node;
	}
}
void *dequeue(t_queue *queue)
{
	void *data;

	if (!queue || is_empty(queue))
		return (NULL);
	data = queue->front->data;
	queue->front = queue->front->next;
	if (queue->front == NULL)
		queue->rear = NULL;
	return (data);
}
