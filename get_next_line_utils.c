/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:21:42 by ede-cola          #+#    #+#             */
/*   Updated: 2023/12/15 15:38:15 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_check_str(char *str)
{
	if (!str)
	{
		str = malloc(1);
		str[0] = '\0';
	}
	return (str);
}

char	*ft_strndup(char *s, size_t n)
{
	size_t	len;
	size_t	i;
	char	*ret;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (n > len)
		n = len;
	ret = malloc(sizeof(char) * (n + 1));
	if (!ret)
		return (NULL);
	while (i < n)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin__gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	s1 = ft_check_str(s1);
	if (!s1 || !s2)
		return (NULL);
	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!ret)
		return (NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
		ret[i++] = s2[j++];
	ret[i] = '\0';
	free(s1);
	return (ret);
}
