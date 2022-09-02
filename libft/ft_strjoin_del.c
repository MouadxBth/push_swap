/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:13:10 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/02 14:19:26 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_del(char *s1, char const *s2, char c)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (!s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 2));
	if (result != NULL)
	{
		ft_strlcpy(result, s1, s1_len + 1);
		result[s1_len] = c;
		result[s1_len + 1] = '\0';
		ft_strlcat(result, s2, s1_len + s2_len + 2);
	}
	if (!s1)
		free(s1);
	return (result);
}
