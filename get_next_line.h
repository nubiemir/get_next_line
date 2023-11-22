/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:56:33 by famir             #+#    #+#             */
/*   Updated: 2023/11/19 17:09:17 by famir            ###   ########.fr       */
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

typedef struct node
{
    char *data;
    struct node *next;

} t_node;

typedef struct queue
{
    t_node *front;
    t_node *rear;
} t_queue;

typedef unsigned int t_bool;

#define TRUE 1
#define FALSE 0

char *get_next_line(int fd);
void enqueue(t_queue *queue, char *data);
t_queue *create_queue();
char *read_file(int fd, t_queue *queue, char *remainder);
char *handle_remainder(t_queue *queue, char *remainder);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int *find_line(char *str);
#endif
