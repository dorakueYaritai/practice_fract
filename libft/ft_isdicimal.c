/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdicimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:31:23 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/19 12:02:22 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	get_nums_of_sign(char *str, size_t len);

int	ft_isdicimal(char *str, size_t sign_allowable)
{
	size_t	i;
	size_t	len;
	bool	decimal_point;

	decimal_point = FALSE;
	if (str == NULL)
		return (0);
	len = ft_strlen(str);
	i = get_nums_of_sign(str, len);
	if (i > sign_allowable)
		return (0);
	while (i < len)
	{
		if (ft_isdigit(str[i]) == TRUE)
			;
		else if (decimal_point == TRUE)
			return (0);
		else if (str[i] == '.')
			decimal_point = TRUE;
		else
			return (0);
		++i;
	}
	return (1);
}

static	size_t	get_nums_of_sign(char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && (str[i] == '+' || str[i] == '-'))
		++i;
	return (i);
}
