/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:23:29 by cesar             #+#    #+#             */
/*   Updated: 2023/11/29 11:41:35 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define FILENAME ".tests/test2.txt"

int main(void)
{	
	int		fd;
	char	*line;
	int		i;

	fd = open(FILENAME, O_RDONLY);
	i = 1;
	while (i <= 15)
	{
		line = get_next_line(fd);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	// printf("\n\n///////////\n\n");




	// char *line_buf = NULL;
	// size_t line_buf_size = 0;
	// int line_count = 0;
	// ssize_t line_size;
	// FILE *fp = fopen(FILENAME, "r");

	// line_size = getline(&line_buf, &line_buf_size, fp);
	// while (line_size >= 0)
	// {
	// 	line_count++;
	// 	printf("line [%02d]: %s", line_count, line_buf);
	// 	line_size = getline(&line_buf, &line_buf_size, fp);
	// }
	// free(line_buf);
	// line_buf = NULL;
	// fclose(fp);
	// return EXIT_SUCCESS;
}