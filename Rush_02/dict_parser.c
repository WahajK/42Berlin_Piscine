#include "rush02.h"

t_dict *parse_dict(char *filename)
{
    int fd;
    char *line;
    t_dict *dictionary;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (NULL);

    dictionary = malloc(sizeof(t_dict) * MAX_DICT_SIZE);
    if (!dictionary)
        return (NULL);

    int i = 0;
    while (get_next_line(fd, &line) > 0)
    {
        if (!parse_line(line, &dictionary[i]))
        {
            free(line);
            free_dict(dictionary);
            return (NULL);
        }
        free(line);
        i++;
    }
    close(fd);
    return (dictionary);
}

int parse_line(char *line, t_dict *entry)
{
    char *delimiter = ft_strchr(line, ':');
    if (!delimiter)
        return (0);

    *delimiter = '\0';
    entry->number = ft_atoi(line);
    entry->word = ft_strdup(delimiter + 1);

    trim_spaces(entry->word);
    return (1);
}

