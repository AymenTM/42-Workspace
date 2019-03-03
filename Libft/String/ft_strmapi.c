/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 07:23:46 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/02 18:38:25 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;

	if (s != '\0' && *f)
	{
		if (!(new_str = (char *)malloc(ft_strlen(s) + 1)))
			return (NULL);
		i = -1;
		while (s[++i])
			new_str[i] = (*f)(i, s[i]);
		new_str[i] = '\0';
		return (new_str);
	}
	return (NULL);
}
