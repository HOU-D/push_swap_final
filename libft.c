/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:40:50 by hoakoumi          #+#    #+#             */
/*   Updated: 2023/04/14 06:03:37 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "error\n", 6);
	exit(1);
}

int	ft_atoi(const	char	*str)
{
	int				i;
	int				sig;
	size_t			r;

	r = 0;
	sig = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		sig = sig * (-1);
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0' )
		r = r * 10 + (str[i++] - '0');
	if (sig == 1 && r > INT_MAX)
		error();
	if (sig == -1 && r > INT_MAX)
		error();
	return (r * sig);
}

void	free_table(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
}

static	char	**result(char const *s, char c, char **k, int i)
{
	int	j;
	int	l;
	int	d;

	l = 0;
	d = nbr_word (s, c);
	while (s[i] && l < d)
	{
		while (s[i] == c)
			i++;
		j = 0;
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
			j++;
		}
		k[l++] = ft_substr (s, i - j, j);
		if (!k)
		{
			free_table (k);
			return (NULL);
		}
	}
	k[l] = 0;
	return (k);
}

char	**ft_split(char	const	*s, char c)
{
	char	**k;

	if (!s)
		return (NULL);
	k = (char **) malloc((1 + nbr_word(s, c)) * sizeof(char *));
	if (!k)
		return (NULL);
	return (result(s, c, k, 0));
}
