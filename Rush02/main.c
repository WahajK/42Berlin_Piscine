#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <ctype.h>

typedef struct s_dict
{
	int		number;
	char	*word;
	int		length;
} t_dict;
void	ft_putstr(char *str);
int		get_line_count(char *fname);
t_dict	*parse_dict(char *fname);
int		get_line_count(char *fname);
char	*ft_strdup(char *src);
char	*get_next_line(int fd);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
void print_number(t_dict *dictionary, char *num_str);
int convert_to_word(t_dict *dictionary, int number);

int		main(int argc, char *argv[])
{
	t_dict *dict;
	printf("argc: %d\n", argc);
	if (argc == 2)
		dict = parse_dict("numbers.dict");
	else if (argc == 3)
		dict = parse_dict(argv[1]);
	else
	{
		ft_putstr("Error\n");
		return (1);
	}
	printf("dict[0].number: %d\n", dict[0].number);
	print_number(dict, argv[argc - 1]);
	return (0);
}
//This function is still not working
void print_number(t_dict *dictionary, char *num_str)
{
    int number = ft_atoi(num_str);
	int units = number % 10;
    int tens = (number / 10) % 10;
    int hundreds = (number / 100) % 10;
    int thousands = (number / 1000) % 10;
    int tenThousands = (number / 10000) % 10;
    
    if (!convert_to_word(dictionary, hundreds))
        ft_putstr("Dict Error\n");
}
//This function is not working yet
int convert_to_word(t_dict *dictionary, int number)
{
    int i = 0;
    while (dictionary[i].number < 1000000)
    {
		printf("dictionary[%d].number: %d\n", i, dictionary[i].number);
        if (dictionary[i].number == 100)
        {
            ft_putstr(dictionary[i].word);
            ft_putstr("\n");
            return (1);
        }
        i++;
    }
    return (0);
}
//Put this in utils
void	ft_putstr(char *str)
{
	while(*str)
		write(1, str++, 1);
}

/**
 * parse_dict - Parses a dictionary file and stores its contents in a t_dict array.
 * @fname: The name of the file to be parsed.
 *
 * This function reads the contents of the file specified by @fname, line by line,
 * and stores each line as an entry in a dynamically allocated array of t_dict structures.
 * Each line is expected to contain a number followed by a word, separated by a space.
 * The function returns a pointer to the array of t_dict structures.
 *
 * Return: A pointer to the array of t_dict structures, or NULL if an error occurs.
 */

//Put this in parse_dict.c
//This function needs some work, need to remove empty spaces and tabs from the string
t_dict	*parse_dict(char *fname)
{
	int	fd;
	char	*line;
	t_dict	*dict;
	
	printf("%d\n", get_line_count(fname));
	dict = malloc(sizeof(t_dict) * (get_line_count(fname) + 1));
	if (!dict)
		return NULL;
	int i = 0;
	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return NULL;
	int bytes_read=1;
	char buffer[1024];
	int line_count = 0;
	while (bytes_read > 0)
	{
		//Reads a single character from the file
		bytes_read = read(fd, &buffer[i], 1);
		i++;
		//If the character is a newline, we have read a complete line
		if(buffer[i-1] == '\n')
		{
			buffer[i-1] = '\0';
			dict[line_count].number = ft_atoi(buffer);
			dict[line_count].word = ft_strdup(buffer);
			dict[line_count].length = ft_strlen(buffer);
			i = 0;
			line_count++;
		}
	}
	printf("%d\n", dict[10].number);
	close(fd);
	return dict;
}
/**
 * @brief Counts the number of lines in a file.
 *
 * This function opens a file specified by the given filename, reads its content,
 * and counts the number of newline characters ('\n') to determine the number of lines.
 *
 * @param fname The name of the file to be read.
 * @return The number of lines in the file. Returns 0 if the file cannot be opened.
 */
int get_line_count(char *fname)
{
	int fd;
	int count = 0;
	char buffer[1024];
	int bytes_read;
	int i;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return 0;
	//Reads a block of data from the file and counts the number of newline characters
	while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
	{
		for (i = 0; i < bytes_read; i++)
		{
			if (buffer[i] == '\n')
				count++;
		}
	}
	close(fd);
	return count;
}
int	ft_atoi(char *str)
{
	int i = 0;
	int sign = 1;
	int result = 0;

	// Skip whitespace
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	// Check for sign
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	// Convert digits to integer
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
//Put this in utils
int	ft_strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return len;
}

//Put this in utils
//This function reads a single line from a file descriptor and returns it as a string inside a dynamically allocated buffer.
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
