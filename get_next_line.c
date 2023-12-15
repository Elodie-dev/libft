/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:24:51 by ede-cola          #+#    #+#             */
/*   Updated: 2023/12/15 15:37:32 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join_to_nl(char *s1, char *s2)
{
	char	*ret;
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = ft_strjoin(s1, s2);
	if (!str)
		return (NULL);
	ret = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!ret)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			ret[j++] = str[i++];
			break ;
		}
		ret[j++] = str[i++];
	}
	ret[i] = '\0';
	free(str);
	return (ret);
}

char	*ft_read(int fd, char *buffer, char *next_line, ssize_t bytes_read)
{
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		next_line = ft_strjoin(next_line, buffer);
		if (!next_line)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (bytes_read == -1 || (bytes_read == 0 && next_line
			&& next_line[0] == '\0'))
	{
		free(next_line);
		return (NULL);
	}
	return (next_line);
}

char	*ft_set_line(char *next_line, char *line)
{
	char	*temp;

	if (next_line && next_line[0] != '\0')
	{
		temp = ft_strndup(next_line, ft_strlen(next_line));
		line = ft_join_to_nl(line, temp);
		free(temp);
		if (!line)
		{
			free(next_line);
			return (NULL);
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	char		*temp;
	static char	*next_line[MAX_OPEN_FILES];
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	buffer = malloc(BUFFER_SIZE + 1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	next_line[fd] = ft_read(fd, buffer, next_line[fd], bytes_read);
	if (next_line[fd] && next_line[fd][0] != '\0')
	{
		line = ft_set_line(next_line[fd], line);
		temp = next_line[fd];
		next_line[fd] = ft_strndup(next_line[fd] + ft_strlen(line),
				ft_strlen(next_line[fd] + ft_strlen(line)));
		free(temp);
	}
	return (line);
}

// int	main(void)
// {
// 	int		fd1;
// 	int		fd2;
// 	char	*str1;
// 	char	*str2;

// 	fd1 = open("multiple_nlx5", O_RDWR);
// 	fd2 = open("43_with_nl", O_RDWR);
// 	if (fd1 == -1 || fd2 == -1)
// 		return (-1);
// 	str1 = get_next_line(fd1);
// 	str2 = get_next_line(fd2);
// 	while (str1 || str2)
// 	{
// 		printf("\nline 1 = '%s'\n", str1);
// 		free(str1);
// 		str1 = get_next_line(fd1);
// 		printf("\nline 2 = '%s'\n", str2);
// 		free(str2);
// 		str2 = get_next_line(fd2);
// 	}
// 	free(str1);
// 	free(str2);
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }
