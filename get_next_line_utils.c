/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:56:42 by famir             #+#    #+#             */
/*   Updated: 2023/12/18 20:30:23 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*dequeue(t_queue *queue)
{
	char	*data;
	
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
	if (!new_node)
		return ;
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

void	safe_free(void **ptr)
{
	if (ptr == NULL)
		return ;
	free(*ptr);
	*ptr = NULL;
}

char	*join_queue(t_queue *queue)
{
	char	*res;
	int		counter;
	int		res_size;
	t_node	*temp;
	
	counter = 0;
	res_size = 0;
	res = (char *)malloc((queue->size + 1) * sizeof(char));
	if (!res || !queue)
		return (NULL);
	temp = queue->front;
	while (temp)
	{
		while (temp->data[counter])
			res[res_size++] = temp->data[counter++];
		counter = 0;
		temp = temp->next;
	}
	if (res_size == 0)
		return (NULL);
	res[res_size] = '\0';
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
