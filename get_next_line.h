/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:56:33 by famir             #+#    #+#             */
/*   Updated: 2023/10/30 19:36:52 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 6
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    void *content;
    struct queue *next;
    int top;
} t_queue;

typedef unsigned int t_bool;

#define TRUE 1
#define FALSE 0

char *get_next_line(int fd);
unsigned int ft_strlen(const char *s);
t_bool is_empty(t_queue *queue);
void enqueue(t_queue *queue, void *data);
void dequeue(t_queue *queue);
t_queue *create_queue();
#endif
