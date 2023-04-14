/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:19:08 by hoakoumi          #+#    #+#             */
/*   Updated: 2023/04/14 02:42:31 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		search(char *s);
char	*reading(int fd, char *s);
char	*join(char *left_str, char *buff);
char	*checking(char *s);
char	*testing(char *s);
size_t	ft_strlen(const char *s);
char	**ft_split(char	const	*s, char c);
int		ft_checck(char *str);
int		arg_to_at(int valeur, t_list **a);
int		is_digitt(char c);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content);
void	sa(t_list **a);
void	sb(t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	ft_pa(t_list **a, t_list **b);
void	ft_pb(t_list **a, t_list **b);
void	ss(t_list **a, t_list **b);
int		ft_atoi(const	char	*str);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	sorting(t_list **a, t_list **b);
void	ra(t_list **a);
void	rra(t_list **a);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
int		check_is_sorted(t_list **a);
void	rra(t_list **a);
void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	sort_4_5(t_list **a, t_list **b);
int		get_index_min(t_list **list);
void	indice(t_list *list);
int		*tab_list(t_list **a, int size);
void	rrb(t_list **b);
int		*tab_list(t_list **a, int size);
void	rrr(t_list**a, t_list **b);
int		initialisation(int ac, char **av, t_list **a);
int		arg_to_intt(char **arg, t_list **a);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
#endif