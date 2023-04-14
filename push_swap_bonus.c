/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:27:26 by hoakoumi          #+#    #+#             */
/*   Updated: 2023/04/14 05:57:31 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	printferror(void)
{
	write(2, "error\n", 6);
	exit(1);
}

static int	ft_checker_min(t_list **a, t_list **b, char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		sa(a);
	else if (!ft_strcmp(str, "sb\n"))
		sb(b);
	else if (!ft_strcmp(str, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(str, "ra\n"))
		ra(a);
	else if (!ft_strcmp(str, "rb\n"))
		rb(b);
	else if (!ft_strcmp(str, "rra\n"))
		rra(a);
	else if (!ft_strcmp(str, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(str, "rr\n"))
		ra(a);
	else if (!ft_strcmp(str, "rrr\n"))
		rrr(a, b);
	else if (!ft_strcmp(str, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(str, "pb\n"))
		pb(a, b);
	else
		printferror();
	return (1);
}

int	ft_checck(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if ((str[i] == '+' || str[i] == '-') && str[i + 1] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (is_digitt(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static void	ft_checker(t_list **a, t_list **b)
{
	int		i;
	char	*str;

	i = 1;
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		ft_checker_min(a, b, str);
		free(str);
	}
	if (check_is_sorted(a) && !ft_lstsize(*b))
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_list	*b;
	t_list	*a;
	int		coef;

	if (ac > 1)
	{
		a = NULL;
		b = NULL;
		coef = initialisation(ac, av, &a);
		if (coef == 0)
		{
			write(2, "error\n", 6);
			exit(1);
		}
		else
			ft_checker(&a, &b);
	}
	return (0);
}
