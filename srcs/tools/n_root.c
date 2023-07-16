/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_root.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 00:49:26 by jolopez-          #+#    #+#             */
/*   Updated: 2023/03/28 18:44:52 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_n_root(int nbr)
{
	int	pow;
	int	count;

	pow = 1;
	count = 1;
	while (pow < nbr)
	{
		pow = pow * 2;
		count = count + 1;
	}
	return (count - 1);
}
