/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 11:11:31 by mbenhass          #+#    #+#             */
/*   Updated: 2019/08/26 11:11:41 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, int n)
{
	char *ret;

	if ((ret = ft_strjoin(s1, s2)) == NULL)
		return (NULL);
	if (n == 1)
		ft_strdel(&s1);
	else if (n == 2)
		ft_strdel(&s2);
	else if (n == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (ret);
}
