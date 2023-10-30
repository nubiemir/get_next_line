/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:00:20 by famir             #+#    #+#             */
/*   Updated: 2023/10/30 20:01:48 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_line(char *str)
{
	int counter = 0;
	
	while (str[counter] && str[counter] != '\n')
		counter++;
	return counter;
}	

char	*get_next_line(int fd)
{
    // static char *remainder;
    char        *res;
    int			line_number;

	
    res = malloc((BUFFER_SIZE + 1) * sizeof(char));
    ssize_t read_value = read(fd, res, BUFFER_SIZE);
    line_number = find_line(res);
    printf("read_value ==> %ld\nline_number ==> %d", read_value, line_number);
	
	
    return res;
}