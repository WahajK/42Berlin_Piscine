#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);	
}
int	is_valid_base(char *base)
{
	//Just do this part yourself, I am too lazy to copy paste lol
	return 1;
}
int	get_index(char ch, char *base)
{
	int i = 0;
	while (base[i])
	{
		if (ch == base[i])
			return i;
		i++;
	}
	return -1;
}
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (!is_valid_base(base_from) && !is_valid_base(base_to))
		return 0;
	int i = 0;
	int result = 0;
	int base_from_len = ft_strlen(base_from);
	int base_to_len = ft_strlen(base_to);
	int index = get_index(nbr[i], base_from);
	char *ptr = (char *) malloc(34);
	while (index >= 0)
	{
		result = result * base_from_len + index;
		i++;
		index = get_index(nbr[i], base_from);
	}
	i = 0;
	while (result > 0)
	{
		ptr[i] = result % base_to_len + '0';
		result /= base_to_len;
		i++;
	}
	ptr[i] = '\0';
	return ptr;
}
int main()
{
	char *ptr = ft_convert_base("FF","0123456789ABCDEF","01");
    printf("%s", ptr);
	free(ptr);
    return 0;
}