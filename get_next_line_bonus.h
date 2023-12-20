/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:56:33 by famir             #+#    #+#             */
/*   Updated: 2023/12/20 20:33:12 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
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
	int		size;
}	t_queue;

typedef unsigned int	t_bool;

# define TRUE 1
# define FALSE 0

char	*get_next_line(int fd);
void	enqueue(t_queue *queue, char *data, int size);
t_bool	read_file(int fd, t_queue *queue, char **remainder);
char	*handle_remainder(t_queue *queue, char **remainder);
char	*ft_strdup(const char *s1, size_t start, size_t len);
char	*join_queue(t_queue *queue);
t_bool	line_exist(t_queue *queue, char **str);
t_queue	*create_queue(void);
void	safe_free(void **ptr);
void	free_queue(t_queue **queue);

#endif
