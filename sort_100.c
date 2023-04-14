/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:51:54 by hoakoumi          #+#    #+#             */
/*   Updated: 2023/04/14 05:06:18 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_10(t_list **a, t_list **b)
{
	push_to_b(a, b, 5);
	push_to_a(a, b);
}

void	sort_100(t_list **a, t_list **b)
{
	push_to_b(a, b, 8);
	push_to_a(a, b);
}

void	sort_500(t_list **a, t_list **b)
{
	push_to_b(a, b, 16);
	push_to_a(a, b);
}
