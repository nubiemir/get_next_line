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

t_bool is_empty(t_queue *queue)
{
	if (!queue)
		return (0);
	if (queue->top == -1)
		return (0);
	return (1);
}
void enqueue(t_queue *queue, void *data)
{
}
void dequeue(t_queue *queue)
{
}
