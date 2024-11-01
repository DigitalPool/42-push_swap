/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:35:44 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/19 18:30:34 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isalpha_sym(int c)
{
	if ((c >= 58 && c <= 126) || (c >= 33 && c <= 42)
		|| (c == 44) || (c == 46) || (c == 47))
		return (1);
	return (0);
}

void	check_alpha_sym(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j]) != '\0')
		{
			if (ft_isalpha_sym(argv[i][j]))
				ft_print_error();
			j++;
		}
		i++;
	}
}

int	ft_Min_Max(int c)
{
	if ((c > INT_MAX) || (c < INT_MIN))
		return (1);
	return (0);
}
// int	ft_check_args(char **argv)
// {
// 	check_alpha_sym(argv);
// 	if (!check_error(argv, 1, 0))
// 		return (false);
// 	return (true);
// }
