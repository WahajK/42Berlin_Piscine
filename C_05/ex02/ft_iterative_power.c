int	ft_iterative_power(int nb, int power)
{
	int	temp;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		temp = nb;
		while (power > 1)
		{
			nb *= temp;
			power--;
		}
	}
	return nb;
}
