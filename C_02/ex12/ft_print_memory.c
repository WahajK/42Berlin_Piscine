/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:08:01 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/14 17:08:03 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, &hex[c / 16], 1);
	write(1, &hex[c % 16], 1);
}

void	print_address(unsigned long addr)
{
	int		i;
	char	address[16];

	i = 15;
	while (i >= 0)
	{
		address[i] = "0123456789abcdef"[addr % 16];
		addr /= 16;
		i--;
	}
	write(1, address, 16);
	write(1, ": ", 2);
}

void	print_content_hex(unsigned char *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			print_hex(addr[i]);
			if (i % 2)
				write(1, " ", 1);
		}
		else
		{
			write(1, "  ", 2);
			if (i % 2)
				write(1, " ", 1);
		}
		i++;
	}
}

void	print_content_char(unsigned char *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size && i < 16)
	{
		if (addr[i] >= 32 && addr[i] <= 126)
			write(1, &addr[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*ptr;

	ptr = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		print_address((unsigned long)(ptr + i));
		print_content_hex(ptr + i, size - i);
		print_content_char(ptr + i, size - i);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}

/*
int	main(void)
{
	char	*str;

	str = "Bonjour les aminches\t\n\tc  est fou.tout.ce 
	qu on peut faire avec...print_memory....lol.lol. ";
	ft_print_memory(str, 92);
	return (0);
}*/
