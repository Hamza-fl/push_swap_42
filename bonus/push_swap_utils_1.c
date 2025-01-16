/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:16:26 by hfalati           #+#    #+#             */
/*   Updated: 2025/01/16 10:32:19 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
short basic_check(int ac, char **nums);
short	empty(int ac, char **nums);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while ((i < (dstsize - 1)) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dl;
	size_t	sl;
	size_t	i;

	i = 0;
	sl = 0;
	dl = 0;
	if (!dst && !dstsize)
		return (ft_strlen(src));
	while (dst[dl] && dl < dstsize)
		dl++;
	while (src[sl])
		sl++;
	if (dl >= dstsize)
		return (dstsize + sl);
	while (src[i] && ((dl + i) < dstsize - 1))
	{
		dst[dl + i] = src[i];
		i++;
	}
	dst[dl + i] = '\0';
	return (dl + sl);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == NULL)
		return (NULL);
	ft_strlcpy(s3, s1, ft_strlen(s1) + 1);
	ft_strlcat(s3, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (s3);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*str;

	str = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_join_args(char **av, char **str)
{
	int		i;
	char	*tmp;

	i = 1;
	*str = ft_strdup("");
	if (*str == NULL)
		return ;
	while (av[i])
	{
		tmp = *str;
		*str = ft_strjoin(tmp, av[i]);
		free(tmp);
		if (av[i + 1])
		{
			tmp = *str;
			*str = ft_strjoin(tmp, " ");
			free(tmp);
		}
		if (str == NULL)
			break ;
		i++;
	}
}
