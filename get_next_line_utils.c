/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:55:48 by eamirkha          #+#    #+#             */
/*   Updated: 2022/04/12 14:55:51 by eamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		len;
	int		i;

	len = ft_strlen(s1) + ft_strlen(s2);
	newstr = malloc(sizeof(*newstr) * len + 1);
	if (newstr == NULL)
		return (0);
	len = 0;
	while (s1[len] != '\0')
	{
		newstr[len] = s1[len];
		len++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		newstr[len] = s2[i];
		i++;
		len++;
	}
	newstr[len] = '\0';
	return (newstr);
}

char	*free_join(char *dst, char *src)
{
	char	*temp;

	temp = dst;
	dst = ft_strjoin(dst, src);
	free(temp);
	return (dst);
}
