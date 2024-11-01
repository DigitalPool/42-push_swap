/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:19:12 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/29 22:52:29 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
		long			nbr;
		long			pos;
		struct s_stack	*next;
		struct s_stack	*prev;
}		t_stack;

void print_stack(t_stack *stack);
int ft_lst_size(t_stack *lst);
void	ft_free_stack(t_stack **stack);
int		ft_get_lst_size(t_stack *stack);
void	ft_sort_stack(t_stack **stack_a);
int		ft_min(t_stack *stack_a);
int		ft_max(t_stack *stack_a);
void	ft_sort(t_stack **stack_a);
void	ft_sort_100(t_stack **stack_a);
void	ft_sort_three(t_stack **stack_a);
void	ft_print_error(void);
t_stack	*ft_create_new_node(int value);
int		is_sorted(t_stack **stack);
int		ft_check_duplicate(t_stack *a);
int		ft_isalpha_sym(int c);
void	check_alpha_sym(char **argv);
int		ft_Min_Max(int c);
void	add_from_back(t_stack **stack, t_stack *stack_new);
void	ft_add_args_to_stack(char **argv, t_stack **stack_a);
void	ft_sa(t_stack **a, int j);
void	ft_sb(t_stack **b, int j);
void	ft_ss(t_stack **a, t_stack **b, int j);
void	ft_pa(t_stack **a, t_stack **b, int j);
void	ft_pb(t_stack **a, t_stack **b, int j);
void	ft_ra(t_stack **a, int j);
void	ft_rb(t_stack **b, int j);
void	ft_rr(t_stack **a, t_stack **b, int j);
void	ft_rra(t_stack **a, int j);
void	ft_rrb(t_stack **b, int j);
void	ft_rrr(t_stack **a, t_stack **b, int j);
t_stack *ft_lst_last(t_stack *lst);
int	ft_atoi_stack(const char *str);
t_stack	*ft_sub_process(char **argv);
t_stack	*ft_get_stack(int argc, char **argv);
void	ft_freestr(char **lst);
char	**ft_split_string(char const *s, char c);
void ft_sort_five(t_stack **stack_a);
int ft_second_min(t_stack *stack_a);
void ft_sort_four(t_stack **stack_a);
int ft_stack_mean(t_stack **stack);
int move_count_ra(t_stack **stack_a, int target);
int move_count_rra(t_stack **stack_a, int target);
int move_count_rbpa(t_stack **stack_b, int target);
int move_count_rrbpa(t_stack **stack_b, int target);
int find_next_max_top(t_stack **stack);
int find_next_min_bottom(t_stack **stack);
int find_next_memmean1_top(t_stack **stack, int mean1_stack_a);
int find_next_memmean1_bottom(t_stack **stack, int mean1_stack_a);
int find_next_memmean_top(t_stack **stack, int stack_mean);
int find_next_memmean_bottom(t_stack **stack, int stack_mean);
int find_next_memmean3_top(t_stack **stack, int mean3_stack);
int find_next_memmean3_bottom(t_stack **stack, int mean3_stack);
int move_count_rra_stack(t_stack **stack);
int move_count_ra_stack(t_stack **stack);
int ft_mean1_stack(t_stack **stack_a);
int ft_mean2_stack(t_stack **stack_a);
int ft_mean3_stack(t_stack **stack_a);
int ft_mean4_stack(t_stack **stack_a);
int ft_mean5_stack(t_stack **stack_a);
int ft_mean6_stack(t_stack **stack_a);
int ft_mean7_stack(t_stack **stack_a);
int ft_mean9_stack(t_stack **stack_a);
int ft_mean10_stack(t_stack **stack_a);
int ft_mean11_stack(t_stack **stack_a);
int ft_mean12_stack(t_stack **stack_a);
int ft_mean13_stack(t_stack **stack_a);
int ft_mean14_stack(t_stack **stack_a);
int ft_mean15_stack(t_stack **stack_a);


void push_tob_rot(t_stack **stack_a, t_stack **stack_b, int mean_value);
void push_tob(t_stack **stack_a, t_stack **stack_b, int mean_value);
void pusha_tob(t_stack **stack_a, t_stack **stack_b, int mean_value);


int pushb_bot2(t_stack **stack_a, t_stack **stack_b);
int pushb_bot(t_stack **stack_a, t_stack **stack_b);
int pushb_top2(t_stack **stack_a, t_stack **stack_b);
int pushb_top(t_stack **stack_a, t_stack **stack_b);

// int pushb_bot2_tmp(t_stack **stack_a, t_stack **stack_b);
int pushb_bot_tmp(t_stack **stack_a, t_stack **stack_b);
int pushb_top2_tmp(t_stack **stack_a, t_stack **stack_b);
int pushb_top_tmp(t_stack **stack_a, t_stack **stack_b);
#endif
