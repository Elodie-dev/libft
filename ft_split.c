/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:30:54 by ede-cola          #+#    #+#             */
/*   Updated: 2023/11/07 13:55:19 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countword(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c || *(s + 1) == '\0')
			count++;
		s++;
	}
	return (count);
}

void	*ft_setmem(int count, char *type, int val)
{
	void	*ret;
	char	*comp1;
	char	*comp2;
	char	*comp3;

	comp1 = "char **";
	comp2 = "char *";
	comp3 = "int";
	if (type == comp1)
		ret = malloc(sizeof(char *) * (count + 1));
	else if (type == comp2)
		ret = malloc((sizeof(char) * val) + 1);
	else if (type == comp3)
		ret = malloc(sizeof(int) * count);
	else
		ret = NULL;
	if (ret == NULL)
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

int	*ft_countwordsize(int count, char const *s, char c, int i)
{
	int	size;
	int	*ret;

	size = 0;
	ret = ft_setmem(count, "int", 0);
	while (*s)
	{
		if (*s == c || *(s + 1) == '\0')
		{
			if (*(s + 1) == '\0')
				ret[i] = size + 1;
			else
				ret[i] = size;
			size = 0;
			i++;
		}
		else
			size++;
		s++;
	}
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		count;
	int		*val;
	char	**ret;

	i = 0;
	count = ft_countword(s, c);
	val = ft_countwordsize(count, s, c, i);
	ret = ft_setmem(count, "char **", 0);
	while (i < count)
	{
		j = 0;
		ret[i] = ft_setmem(count, "char *", val[i]);
		while (*s != c && *s != '\0')
		{
			ret[i][j] = *s;
			j++;
			s++;
		}
		ret[i][j] = '\0';
		i++;
		s++;
	}
	ret[i] = NULL;
	return (ret);
}

int	main(void)
{
	char const *s = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
	char c = ',';
	char **str;
	int i;

	i = 0;
	str = ft_split(s, c);
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	free(str);
	return (0);
}