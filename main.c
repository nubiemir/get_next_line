/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:24:37 by famir             #+#    #+#             */
/*   Updated: 2023/11/25 19:12:49 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int main()
{ 
    int fd = open("index.txt", O_RDONLY);
    char *line = get_next_line(fd);
    while (line != NULL)
    {
        printf("%s", line); 
        line = get_next_line(fd);  
    }   
}