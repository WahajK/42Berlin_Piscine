int	ft_iterative_factorial(int nb)
{
	if (nb < 0)
		return (0);
	int	ans;

	ans = 1;
	while (nb > 0)
	{
		ans *= nb;
		nb--;
	}
	return (ans);
}
/*
int	main(void)
{
	ft_iterative_factorial(5);
}*/
