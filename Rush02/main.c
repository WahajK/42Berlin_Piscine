#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <ctype.h>

typedef struct s_dict {
	char **numbers;
	char **words;
	int size;
} t_dict;

void ft_putstr(char *str);
char *ft_strdup(char *src);
char *get_next_line(int fd);
int ft_atoi(char *str);
int ft_strlen(char *str);
void print_number(t_dict *dictionary, char *num_str);
char *modify_string(char *string);
void modify_prints(char *string, int length, char *new_ptr);
char *ft_strcpy(char *dest, const char *src);
int read_dictionary(const char *dict_file_name, t_dict *dict);
void parse_dictionary_line(char *line_start, t_dict *dict, int index);
void destroy_dictionary(t_dict *dict);
int get_line_count(char *fname);
int count_lines(const char *content, int file_size);
int get_file_size(const char *file_name);
int ft_strcmp(const char *s1, const char *s2);
char *ft_strncpy(char *dest, const char *src, size_t n);
void print_word(t_dict *dictionary, int value);
void print_group(t_dict *dictionary, int group_value);
int sanitize_number(char *num_str);

int main(int argc, char *argv[])
{
	t_dict dict;
	int flag;

	if (argc == 2) {
		flag = read_dictionary("numbers.dict", &dict);
	} else if (argc == 3) {
		flag = read_dictionary(argv[1], &dict);
	} else {
		ft_putstr("Error\n");
		return 1;
	}
	if (flag != 0) {
		ft_putstr("Dict Error\n");
		return 1;
	}
	print_number(&dict, argv[argc - 1]);
	destroy_dictionary(&dict);
	return 0;
}
int ft_strcmp(const char *s1, const char *s2) {
	while (*s1 && (*s1 == *s2)) {
		s1++;
		s2++;
	}
	return *(unsigned char *)s1 - *(unsigned char *)s2;
}
char *ft_strncpy(char *dest, const char *src, size_t n) {
	size_t i;
	i = 0;
	while (i < n && src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	while (i < n) {
		dest[i] = '\0';
		i++;
	}
	return dest;
}
char *ft_strcpy(char *dest, const char *src) {
	int i = 0;
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

void print_number(t_dict *dictionary, char *num_str) 
{
	char suffix[][14] = {"", "thousand", "million", "billion", "trillion", "quadrillion", "quintillion", "sextillion", "septillion", 
	"octillion", "nonillion", "decillion", "undecillion"};
	int i = 0;
	while ((num_str[i] >= 9 && num_str[i] <= 13) || (num_str[i] == ' '))
	{
		i++;
	}
	if(num_str[i] == '-')
	{
		ft_putstr("Error\n");
		return;
	}
	while (num_str[i] >= '0' && num_str[i] <= '9')
	{
		i++;
	}
	num_str[i] = '\0';

	int len = ft_strlen(num_str);
	if(len > 39)
	{
		ft_putstr("Dict Error\n");
		return;
	}
	int group_count = (len + 2) / 3;
	int group_index = 0;
	int num_index = 0;

	while (group_index < group_count) {
		int group_len = len % 3;
		if (group_len == 0) {
			group_len = 3;
		}

		char group[4] = {0};
		ft_strncpy(group, &num_str[num_index], group_len);
		num_index += group_len;
		len -= group_len;

		int group_value = ft_atoi(group);
		if (group_value > 0) {
			if (group_index > 0) {
				ft_putstr(" ");
			}
			print_group(dictionary, group_value);
			if (group_count - group_index - 1 > 0) {
				ft_putstr(" ");
				ft_putstr(suffix[group_count - group_index - 1]);
			}
		}
		group_index++;
	}
	ft_putstr("\n");
}

void print_group(t_dict *dictionary, int group_value) {
	if (group_value >= 100) {
		print_word(dictionary, group_value / 100);
		ft_putstr(" hundred");
		group_value %= 100;
		if (group_value > 0) {
			ft_putstr(" ");
		}
	}
	if (group_value >= 20) {
		print_word(dictionary, (group_value / 10) * 10);
		group_value %= 10;
		if (group_value > 0) {
			ft_putstr("-");
		}
	}
	if (group_value > 0) {
		print_word(dictionary, group_value);
	}
}

void print_word(t_dict *dictionary, int value) {
	char num_str[12];
	int temp = value;
	int len = 0;

	// Calculate the length of the number
	while (temp > 0) {
		temp /= 10;
		len++;
	}

	// Handle the case when value is 0
	if (len == 0) {
		num_str[0] = '0';
		num_str[1] = '\0';
	} else {
		num_str[len] = '\0';
		while (value > 0) {
			num_str[--len] = (value % 10) + '0';
			value /= 10;
		}
	}
	int i = 0;
	while (i < dictionary->size) {
		if (ft_strcmp(dictionary->numbers[i], num_str) == 0) {
			ft_putstr(dictionary->words[i]);
			return;
		}
		i++;
	}
}
void ft_putstr(char *str) {
	while (*str) {
		write(1, str++, 1);
	}
}

int count_lines(const char *content, int file_size) {
	int lines = 0;
	int i = 0;
	while (i < file_size) {
		if (content[i] == '\n') {
			lines++;
		}
		i++;
	}
	return lines;
}

int get_file_size(const char *file_name) {
	int file_size = 0;
	char content;
	int fd = open(file_name, O_RDONLY);
	if (fd == -1) {
		return 0;
	}
	while (read(fd, &content, 1) == 1) {
		file_size++;
	}
	close(fd);
	return file_size;
}

int read_dictionary(const char *dict_file_name, t_dict *dict) 
{
	int flag;
	int fd = open(dict_file_name, O_RDONLY);
	if (fd == -1) {
		return 1;
	}

	int file_size = get_file_size(dict_file_name);
	if (file_size == 0) {
		close(fd);
		return 1;
	}

	char *content = (char *)malloc(file_size + 1);
	if (!content) {
		close(fd);
		return 1;
	}
	read(fd, content, file_size);
	content[file_size] = '\0';
	close(fd);

	int lines = count_lines(content, file_size);
	dict->numbers = (char **)malloc(lines * sizeof(char *));
	dict->words = (char **)malloc(lines * sizeof(char *));
	if (!dict->numbers || !dict->words) {
		free(content);
		return 1;
	}
	int index = 0;
	char *line_start = content;
	int i = 0;
	while (i < file_size) {
		if (content[i] == '\n' || content[i] == '\0') {
			content[i] = '\0';
			parse_dictionary_line(line_start, dict, index);
			flag = sanitize_number(dict->numbers[index]);
			if (flag == 1)
				return 1;
			index++;
			line_start = &content[i + 1];
		}
		i++;
	}
	dict->size = index;
	free(content);
	return 0;
}
int sanitize_number(char *num_str) 
{
	int i = 0;
	while (num_str[i] != '\0')
	{
		if (num_str[i] < '0' || num_str[i] > '9')
		{
			return 1;
		}
		i++;
	}
	return 0;
}
void destroy_dictionary(t_dict *dict) {
	int i = 0;
	while (i < dict->size) {
		free(dict->numbers[i]);
		free(dict->words[i]);
		i++;
	}
	free(dict->numbers);
	free(dict->words);
}

void parse_dictionary_line(char *line_start, t_dict *dict, int index) {
	char *number = line_start;
	char *word = NULL;

	int j = 0;
	while (line_start[j] != '\0')
	{
		if (line_start[j] == ':') 
		{
			line_start[j] = '\0';
			word = &line_start[j + 1];
			break;
		}
		j++;
	}
	while (*word == ' ') {
		word++;
	}

	if (number && word) {
		dict->numbers[index] = (char *)malloc(ft_strlen(number) + 1);
		dict->words[index] = (char *)malloc(ft_strlen(word) + 1);
		ft_strcpy(dict->numbers[index], number);
		ft_strcpy(dict->words[index], word);
	}
}

int get_line_count(char *fname) {
	int fd = open(fname, O_RDONLY);
	if (fd < 0) {
		return 0;
	}

	int count = 0;
	char buffer[1024];
	int bytes_read;
	while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
		int i = 0;
		while (i < bytes_read) {
			if (buffer[i] == '\n') {
				count++;
			}
			i++;
		}
	}
	close(fd);
	return count;
}

int ft_atoi(char *str) {
	int i = 0;
	int result = 0;

	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')) {
		i++;
	}

	if (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-') {
			return -1;
		}
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9') {
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return result;
}

int ft_strlen(char *str) {
	int len = 0;
	while (str[len]) {
		len++;
	}
	return len;
}

char *ft_strdup(char *src) {
	int len = ft_strlen(src);
	char *dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup) {
		return NULL;
	}
	int i = 0;
	while (i < len) {
		dup[i] = src[i];
		i++;
	}
	dup[len] = '\0';
	return dup;
}