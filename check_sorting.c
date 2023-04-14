/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:51:09 by hoakoumi          #+#    #+#             */
/*   Updated: 2023/04/14 05:24:48 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_sorted(t_list **a)
{
	t_list	*temp;

	temp = (*a);
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	indice(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list->index = i;
		list = list->next;
		i++;
	}
}

int	get_index_min(t_list **list)
{
	t_list	*tmp;
	int		min;
	int		index_min;

	indice(*list);
	tmp = *list;
	min = tmp->data;
	index_min = 0;
	while (tmp)
	{
		if (min > tmp->data)
		{
			min = tmp->data;
			index_min = tmp->index;
		}
		tmp = tmp->next;
	}
	return (index_min);
}

void	sorting(t_list **a, t_list **b)
{
	int	size;

	if (check_is_sorted(a))
		return ;
	size = ft_lstsize(*a);
	if (size <= 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size <= 5)
		sort_4_5(a, b);
	else if (size <= 10)
		sort_10(a, b);
	else if (size <= 100)
		sort_100(a, b);
	else
		sort_500(a, b);
}
