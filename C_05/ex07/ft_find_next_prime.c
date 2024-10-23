/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:05:38 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/23 16:05:39 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	else
	{
		while (i < nb)
		{
			if (nb % i == 0)
				return (0);
			i++;
		}
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	flag;
	int	temp;
	int	i;

	i = 2;
	flag = 1;
	if (ft_is_prime(nb))
		return nb;
	if (nb < 2)
		return (2);
	nb++;
	temp = nb + 1;
	while(1)
	{
		i = nb;
		while (i < nb)
		{
			if (nb % i == 0)
			{
				nb++;
				flag = 0;
				break;
			}
			i++;
		}
		if (nb == i && flag == 1)
			return nb;
		flag = 1;
	}
}
/*
int	main()
{
	printf("%d", ft_find_next_prime(2));
	return (0);
}*/
