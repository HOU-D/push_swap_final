/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:20:27 by hoakoumi          #+#    #+#             */
/*   Updated: 2023/04/14 00:41:30 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rb(t_list **b)
{
	t_list	*tmp;

	if (!(*b) || ft_lstsize(*b) < 2)
		return (1);
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	ft_lstadd_back(b, tmp);
	write(1, "rb\n", 3);
	return (1);
}

void	rr(t_list **a, t_list **b)
{
	if (!(*a) || ft_lstsize(*a) < 2 || !(*b) || ft_lstsize(*b) < 2)
		return ;
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*b || ft_lstsize(*b) < 1)
		return ;
	tmp = (*b);
	(*b) = (*b)->next;
	tmp->next = NULL;
	ft_lstadd_front(a, tmp);
	write(1, "pa\n", 3);
}
