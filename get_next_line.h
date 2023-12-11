/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v2.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekeste <htekeste@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:56:33 by famir             #+#    #+#             */
/*   Updated: 2023/12/12 00:50:37 by htekeste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct node
{
	char		*data;
	struct node	*next;

}	t_node;

typedef struct queue
{
	t_node	*front;
	t_node	*rear;
}	t_queue;

typedef unsigned int	t_bool;

# define TRUE 1
# define FALSE 0

char	*get_next_line(int fd);
void	enqueue(t_queue *queue, char *data);
t_bool	read_file(int fd, t_queue *queue, char **remainder);
char	*handle_remainder(t_queue *queue, char **remainder);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*dequeue(t_queue *queue);
void	*split_new_line(char *str, int index, char **left, char **right);
char	*join_queue(t_queue *queue);
t_queue	*create_queue(void);

#endif
