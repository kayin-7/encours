/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjoli <gjoli@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:30:00 by gjoli             #+#    #+#             */
/*   Updated: 2022/05/10 22:00:00 by gjoli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

unsigned int	ft_strlen(char const *str)
{
	char	*a;

	a = (char *)str;
	while (*a)
		a++;
	return (a - str);
}

char	*ft_strcpy(char *dest, char *src)
{	
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
int	ft_strchri(const char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			return (i);	
	return (-2);
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
			return(NULL);
		}
		r[j] = '\0';
	}
	return (r);
}

char	*get_next_line(int fd)
{
	       char	*r;
	       char	*s;
		   char	*t;
	static char	lect[2048];
		    int	i;

	if (fd == -1 || BUFFER_SIZE == 0)
			return(NULL);
		if (lect[0] == '\0')
	{
		r = readfile(fd);
		if (r == 0 || r[0] == '\0')
			return (NULL);
		t = ft_strjoin(lect, r);
//		t = ft_substr(r,0 ,ft_strlen(r));
		free(r);
	}
	else
		t = ft_substr(lect,0 ,ft_strlen(lect));
	i = ft_strchri(t);
	while (i == -2)
	{
		r = readfile(fd);
		if (r == 0 || r[0] == '\0')
		{
			lect[0] = '\0';
			return (t);
		}
		s = ft_substr(t,0,ft_strlen(t));
		free(t);
		t = ft_strjoin(s, r);
		free(r);
		free(s);
		i = ft_strchri(t);
	}
	s = ft_substr(t, 0, i+1);
	r = ft_substr(t, (i + 1), ft_strlen(t));
	free(t);
	ft_strcpy(lect, r);
	return(free(r),s);
}