/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antidote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 09:50:54 by akharrou          #+#    #+#             */
/*   Updated: 2018/11/02 13:18:17 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_antidote(int i, int j, int k)
{
	if ((i >= j && i <= k) || (i >= k && i <= j))
		return (i);
	if ((j >= i && j <= k) || (j >= k && j <= i))
		return (j);
	return (k);
}