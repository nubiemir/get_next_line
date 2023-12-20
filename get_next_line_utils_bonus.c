/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:56:42 by famir             #+#    #+#             */
/*   Updated: 2023/12/20 16:38:34 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1, size_t start, size_t len)
{
	char	*res;
	int		counter;

	if (!s1)
		return (NULL);
	res = (char *)malloc((len - start + 1) * sizeof(char));
	counter = 0;
	if (res != NULL)
	{
		while ((start < len) && s1[start])
		{
			res[counter] = s1[start];
			counter++;
			start++;
		}
		res[counter] = '\0';
	}
	return (res);
}

void	enqueue(t_queue *queue, char *data, int size)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = ft_strdup(data, 0, size);
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

void	free_queue(t_queue **queue)
{
	t_node	*tmp;
	t_node	*nextnode;

	tmp = (*queue)->front;
	while (tmp)
	{
		nextnode = tmp->next;
		safe_free((void **) &tmp->data);
		safe_free((void **) &tmp);
		tmp = nextnode;
	}
	safe_free((void **) queue);
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
		return (safe_free((void **)&res), NULL);
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
