/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:59:35 by hoakoumi          #+#    #+#             */
/*   Updated: 2023/04/12 23:44:41 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_elem_index(t_list *a, int start, int end)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->data >= start && a->data <= end)
			return (i);
		a = a->next;
		i++;
	}
	return (-1);
}

void	update_ends(t_vars *vars)
{
	vars->start -= vars->offset;
	vars->end += vars->offset;
	if (vars->start < 0)
		vars->start = 0;
	if (vars->end >= vars->size)
		vars->end = vars->size - 1;
}

void	vars_init(t_vars *vars, int div, t_list *a)
{
	vars->size = ft_lstsize(a);
	vars->tmp_size = vars->size;
	vars->mid = (vars->size / 2) - 1;
	vars->offset = vars->size / div;
	vars->start = vars->mid - vars->offset;
	vars->end = vars->mid + vars->offset;
}

void	push_to_b(t_list **a, t_list **b, int div)
{
	t_vars	vars;
	int		*tab;
	int		elem_index;
	int		i;

	vars_init(&vars, div, *a);
	tab = tab_list(a, vars.size);
	while (*a)
	{
		elem_index = get_elem_index(*a, tab[vars.start], tab[vars.end]);
		while (elem_index != -1)
		{
			i = -1;
			if (elem_index <= vars.tmp_size / 2)
				while (++i < elem_index)
					ra(a);
			else
				while (++i < vars.tmp_size - elem_index)
					rra(a);
			(pb(a, b), vars.tmp_size--);
			(((*b)->data < tab[vars.mid]) && rb(b));
			elem_index = get_elem_index(*a, tab[vars.start], tab[vars.end]);
		}
		update_ends(&vars);
	}
}
