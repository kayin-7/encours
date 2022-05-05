/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjoli <gjoli@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:30:00 by gjoli             #+#    #+#             */
/*   Updated: 2022/04/30 14:30:00 by gjoli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*readfile(int fd)
{
	char	*r;
	 int	j;

	r = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (r)
	{
		j = read (fd, r, BUFFER_SIZE);
		if (j < 1 || fd == -1 || BUFFER_SIZE == 0)
		{
			free (r);
			r = 0;
		}
		r[j] = '\0';
	}
	return (r);
}

char	*get_next_line(int fd)
{
	      char	*r;
	      char	*s;
	static int	lect;
	       int	j;
	       int	i;

	r = malloc(sizeof (char) * (lect));
	j = read (fd, r, lect);
	free (r);
	r = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (r)
	{
		j = read (fd, r, BUFFER_SIZE);
		if (j < 1 || fd == -1 || BUFFER_SIZE == 0)
		{
			free (r);
			return (0);
		}
		r[j] = '\0';
		s = malloc(sizeof (char) * (unsigned int)(j + 1));
		i = -1;
//		s[0] =0;
//		s = ft_strjoingnl(s, r);
		while (++i < j && r[i])
		{	
			s[i] = r[i];
			if (r[i] == '\n')
				break;
		}

		lect += i;
		free (r);
//		if (r[i])
//			readfile(fd);
//		s[i+1]='\0';
		return (s);
	}
	return (0);
}
