/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjoli <gjoli@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:30:00 by gjoli             #+#    #+#             */
/*   Updated: 2022/04/30 14:30:00 by gjoli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include "get_next_line.h"

void	ft_bzero(const void *s, unsigned long n)
{
	unsigned long	i;
	unsigned char	*r;

	r = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		r[i] = '\0';
		i++;
	}
}

char	*ft_strcat(char *dest, char const *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	return (dest);
}

void	*ft_calloc(unsigned long nmemb, unsigned long size)
{
	void	*ptr;

	if ((nmemb == SIZE_MAX || size == SIZE_MAX) && (nmemb > 1 || size > 1))
		return (NULL);
	ptr = (void *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	 int	lon;
	char	*chaine;

	lon = (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	chaine = ft_calloc(lon, 1);
	if (chaine)
	{
		ft_strcat(chaine, s1);
		ft_strcat(chaine, s2);
		chaine[lon - 1] = '\0';
	}
	return (chaine);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	        char	*str;
	unsigned int	i;
	unsigned int	j;

	i = start;
	j = 0;
	str = malloc (sizeof (char) * (len + 1));
	if (str)
	{	
		while (i < (start + len) && s[i])
			str[j++] = s[i++];
		str[j] = '\0';
	}
	return (str);
}
