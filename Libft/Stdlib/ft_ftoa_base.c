/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:41:09 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/18 14:36:18 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"
#include "../Includes/math_42.h"
#include "../Includes/macros.h"

char	*ft_ftoa_base(long double n, char *base, int width, int precision)
{
	unsigned long long	val;
	int					sign;
	char				*float_str;
	char				*tmp_str;
	char				*pad_str;

	float_str = NULL;
	sign = (n < 0);
	n = (n < 0) ? -n : n;
	val = (unsigned long long)n;
	float_str = ft_strjoinfre(float_str, ft_ulltoa_base(val, base, -1), 0, 1);
	MALLOC_GUARD((tmp_str = float_str), NULL);
	precision = ((precision >= 0) ? precision : 6);
	if (precision)
	{
		float_str = ft_strjoin(float_str, ".");
		free(tmp_str);
		MALLOC_GUARD((tmp_str = float_str), NULL);
		val = ((n - (unsigned long long)n)) * ft_powl(10, precision + (precision < 20));
		if (precision < 20)
			val = ft_round_with_prior((long double)val);
		float_str = ft_strjoin(float_str, ft_ulltoa_base(val, base, precision));
		free(tmp_str);
		MALLOC_GUARD((tmp_str = float_str), NULL);
	}
	pad_str = ft_padding(width - ft_strlen(float_str) - sign, '0');
	float_str = ft_strjoin(pad_str, float_str);
	free(pad_str);
	free(tmp_str);
	MALLOC_GUARD((tmp_str = float_str), NULL);
	float_str = ft_strjoin((sign) ? "-" : "", float_str);
	MALLOC_GUARD((tmp_str = float_str), NULL);
	free(tmp_str);
	return (float_str);
}
