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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c > 256)
		c -= 256;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}	
	if (c == '\0')
		return ((char *)s + i);
	return (0);
}

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
			return(0);
		}
		r[j] = '\0';
	}
	return (r);
}

char	*get_next_line(int fd)
{
	       char	*r;
	       char	*s;
	static char	*lect = 0;
	        int	j;
	       int	i;

	j = -42;
//	if(lect !=0)
//		s = malloc(sizeof (char) * (ft_strlen(lect) + 1));
		
//	ajoute lect jusqua \n
//      modifie lect a partir de \n avec la suite de lect 
//	s = (char *)lect;
	while ((j == BUFFER_SIZE) || j == -42)
	{
		r = readfile(fd);
		if (r == 0)
		{
			s = 0;
			return(free (r),s);
		}
		j = ft_strlen(r);
		s = malloc(sizeof (char) * j + 1);
//		s = ft_strjoin(s, r);
		i = -1;
		while (++i < j && r[i])
		{	
			s[i] = r[i];
			if (r[i] == '\n')
			{
				i++;
				break;
			}
		}
		s[i]='\0';
		i = -1;
		lect = ((char *)(ft_strchr(r,'\n')));
		lect ++;
		return (free (r), s);
	}
	s = 0;
	return (s);
}

