/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 22:25:01 by akharrou          #+#    #+#             */
/*   Updated: 2018/11/03 10:51:21 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		match(char *s1, char *s2)
{
	if (*s1 && *s2 == '*')
		return (match(s1 + 1, s2) || match(s1, s2 + 1));
	else if (*s1 && *s2 && *s1 == *s2)
		return (match(s1 + 1, s2 + 1));
	else if (!*s1 && *s2 == '*')
		return (match(s1, s2 + 1));
	else if (!*s1 && !*s2)
		return (1);
	return (0);
}