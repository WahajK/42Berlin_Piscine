#include <unistd.h>

int	main(int argc, char *argv[])
{
	t_dict *dict;
	
	if (argc == 2)
		dict = parse_dict("numbers.dict");
	else if (argc == 3)
		dict = parse_dict(argv[1]);
	else
	{
		ft_putstr("Error\n");
		return (1);
	}

	if (!dict)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	if (is_valid_number(argv[argc - 1]))
		print_number(dict, argv[argc - 1]);
	else
		ft_putstr("Error\n");
	free_dic(dict);
	return (0);
}
//Put this in utils
void	ft_putstr(char *str)
{
	while(*str)
		write(1, str++, 1);
}
//Put this in a parse_dict file
t_dict	*parse_dict(char *fname)
{
	int	fd;
	char	*line;
	t_dict	*dict;
	
	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return NULL;
	dict = malloc(sizeof(t_dict));
}
//Put this in utils
char	*ft_strdup(char *src)
{
	int	len;
	char	*dup;
	int	i;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
