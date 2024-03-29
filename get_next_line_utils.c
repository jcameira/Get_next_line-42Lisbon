/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:20:29 by jcameira          #+#    #+#             */
/*   Updated: 2023/10/21 13:09:14 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*new_str;
	int		i;
	int		j;

	new_str = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (str1 && str1[i])
	{
		new_str[i] = str1[i];
		i++;
	}
	j = -1;
	while (str2[++j])
	{
		new_str[i++] = str2[j];
		if (str2[j] == '\n')
			break ;
	}
	free(str1);
	new_str[i] = '\0';
	return (new_str);
}

void	ft_remove_last_line(char *buffer, int *flag, int *flag2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (*flag && *flag2)
		{
			buffer[j] = buffer[i];
			j++;
		}
		if (buffer[i] == '\n' && *flag2)
			*flag = 1;
		buffer[i] = 0;
		i++;
	}
}
