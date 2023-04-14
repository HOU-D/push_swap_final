/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_to_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:23:17 by hoakoumi          #+#    #+#             */
/*   Updated: 2023/04/14 02:27:08 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*tab_list(t_list **a, int size)
{
	int		*tab;
	t_list	*tmp;
	int		i;

	size = ft_lstsize(*a);
	tab = malloc(sizeof(int) * size);
	if (tab == NULL)
		return (0);
	i = 0;
	tmp = *a;
	while (tmp)
	{
		tab[i++] = tmp->data;
		tmp = tmp->next;
	}
	tri_selection(tab, size);
	return (tab);
}

void	tri_selection(int Tab[], int taille)
{
	int	i;
	int	index_min;
	int	j;
	int	tmp;

	i = 0;
	while (i < taille - 1)
	{
		index_min = i;
		j = i + 1;
		while (j < taille)
		{
			if (Tab[j] < Tab[index_min])
			{
				index_min = j;
			}
			j++;
		}
		tmp = Tab[i];
		Tab[i] = Tab[index_min];
		Tab[index_min] = tmp;
		i++;
	}
}
