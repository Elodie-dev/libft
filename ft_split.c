/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:30:54 by ede-cola          #+#    #+#             */
/*   Updated: 2023/11/09 13:03:45 by ede-cola         ###   ########.fr       */
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
	if (!ret)
		return (NULL);
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
			if (*(s + 1) == '\0' && *s != c)
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
			ret[i][j++] = *s++;
		ret[i][j] = '\0';
		i++;
		s++;
	}
	ret[i] = NULL;
	free(val);
	return (ret);
}

int	main(void)
{
	char	*tosplit = "          ";
	char	**res = ft_split(tosplit, ' ');
	int	i;
	
	i = 0;
	while(res[i])
	{
		printf("%s", res[i]);
		i ++;
	}
}
