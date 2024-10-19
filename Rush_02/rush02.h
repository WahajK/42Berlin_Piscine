#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define MAX_DICT_SIZE 1000
#define BUFFER_SIZE 1024

typedef struct s_dict
{
	int	number;
	char	*word;
} t_dict;

void	ft_putstr(char *str);
int	is_valid_number(char *str);
t_dict	*parse_dict(char *filename);
void	free_dict(t_dict *dictionary);
void	print_number(t_dict *dictionary, char *num_str);
int	convert_to_word(t_dict *dictionary, int number);
int	parse_line(char *line, t_dict *entry);
void	trim_spaces(char *str);
int	ft_atoi(char *str);
char	*ft_strdup(char *src);
int	get_next_line(int fd, char **line);
char	*ft_strchr(const char *s, int c);
char	*ft_strcat(char *dest, const char *src);

#endif
