/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:10:44 by jcameira          #+#    #+#             */
/*   Updated: 2023/10/23 15:49:47 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];
	int			flag;
	int			flag2;

	flag = 0;
	flag2 = 0;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		ft_remove_last_line(buffer, &flag, &flag2);
		return (NULL);
	}
	line = NULL;
	flag2 = 1;
	while (!flag && (*buffer != 0 || read(fd, buffer, BUFFER_SIZE) > 0))
	{
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
		ft_remove_last_line(buffer, &flag, &flag2);
	}
	return (line);
}

// int	main(void)
// {
// 	int		fd;
//  	char	*line;
//  	int 	i = 1;

//  	fd = open("file", O_RDONLY);
//  	while ((line = get_next_line(fd)))
//  	{
// 		printf("Line %d:\n", i++);
//  		printf("-> %s", line);
//  		free(line);
//  	}
// 	printf("\nCheck NULL:\n");
// 	printf("-> %s\n", line);
//  	close(fd);
// 		return (0);
// }