/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:47:38 by ede-cola          #+#    #+#             */
/*   Updated: 2023/11/07 16:03:54 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_nbr_length(int n)
{
    int count;
 
    count = 0;
    while (n != 0)
    {
        n = n / 10;
        count ++;
    }
    return (count);
  }

char    *ft_itoa(int n)
{
    char    *ret;
    long    nb;
    int     i;
    int     len;
    char    c;

    len = ft_nbr_length(n);
    nb = n;
    if (nb < 0)
    {
        ret = malloc((sizeof(char) * len));
        if (!ret)
            return (NULL);
        nb = -n;
        ret[0] = '-';
        i = 1;
    }
    else
    {
        ret = malloc((sizeof(char) * len));
        if (!ret)
            return (NULL);
        i = 0;
    }
    while (i < len)
    {
        if (nb > 9)
        {
            ret[i] = '0' + (nb % 10);
            nb /= 10;
        }
        else
            ret[i] = '0' + nb;
        i++;
    }
    i = 0;
    while (i < len / 2)
    {
        c = ret[i];
        ret[i] = ret[len - i - 1];
        ret[len - i - 1] = c;
        i++;
    }
    ret[len] = '\0';
    i = 0;
    return (ret);
}

int main(void)
{
    printf("%s", ft_itoa(175));
    return (0);
}