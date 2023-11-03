/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:18:01 by ede-cola          #+#    #+#             */
/*   Updated: 2023/11/02 13:22:20 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <ctype.h>

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

// int main(void)
// {
//     char c = 'C';
//     char c2 = '3';

//     printf("%d : %d\n", ft_isalpha(c), isalpha(c));
//     printf("%d : %d", ft_isalpha(c2), isalpha(c2));
// }