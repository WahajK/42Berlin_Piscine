#include "rush02.h"

int get_next_line(int fd, char **line)
{
    char buffer[BUFFER_SIZE + 1];
    char *temp_line = malloc(1);
    int bytes_read;
    int i = 0;

    if (!temp_line)
        return (-1);

    temp_line[0] = '\0';

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';
        for (i = 0; buffer[i] && buffer[i] != '\n'; i++)
            ;
        if (buffer[i] == '\n')
        {
            buffer[i] = '\0';
            *line = ft_strdup(buffer);
            return (1);
        }
        temp_line = realloc(temp_line, bytes_read + i + 1);
        if (!temp_line)
            return (-1);
        temp_line = ft_strcat(temp_line, buffer);
    }

    *line = temp_line;
    return (0);
}

