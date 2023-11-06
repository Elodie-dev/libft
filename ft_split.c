/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:30:54 by ede-cola          #+#    #+#             */
/*   Updated: 2023/11/06 19:45:59 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    **ft_split(char const *s, char c)
{
    int i;
    int j;
    int size;
    int *val;
    int count;
    char    *temp;
    char    **ret;
    
    i = 0;
    temp = (char *)s;
    size = 0;
    count = 0;
    while (*temp)
    {
        if (*temp == c || *(temp + 1) == '\0')
            count++;
        temp++;
    }
    temp = (char *)s;
    val = malloc((sizeof(int) * count) + sizeof(int));
    while (*temp)
    {
        if (*temp == c || *(temp + 1) == '\0')
        {
            if (*(temp + 1) == '\0')
                val[i] = size + 1;
            else
                val[i] = size;
            size = 0;
            i++;
        }
        else
            size++;
        temp++;           
    }
    ret = malloc((sizeof(char *) * (count + 1)));
    size = 0;
    i = 0;
    while (size < count)
    {
        j = 0;
        ret[i] = malloc((sizeof(char) * val[i]) + 1);
        while(*s != c && *s != '\0') 
        {
            ret[i][j] = *s;
            j++;
            s++;
        }
        ret[i][j] = '\0';
        i++;
        size++;
        s++;
    }
    ret[i] = NULL;
    return (ret);
}

int main(void)
{
    char const    *s = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,NOV,DEC";
    char    c = ',';
    int i;

    i = 0;
    while (ft_split(s, c)[i])
    {
        printf("%s\n", ft_split(s, c)[i]);
        i++;
    }
}