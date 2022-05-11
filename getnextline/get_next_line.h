/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjoli <gjoli@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:30:00 by gjoli             #+#    #+#             */
/*   Updated: 2022/05/01 11:59:00 by gjoli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

char	*get_next_line(int fd);
unsigned int	ft_strlen(char const *str);
char	*ft_strcat(char *dest, char const *src);
void	*ft_calloc(unsigned long nmemb, unsigned long size);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(const void *s, unsigned long n);
#endif
