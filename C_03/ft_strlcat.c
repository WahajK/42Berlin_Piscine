#include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int	i;
    unsigned int	j;
    unsigned int	dest_len;
    unsigned int	src_len;

    i = 0;
    j = 0;
    dest_len = 0;
    src_len = 0;
    while (dest[dest_len])
        dest_len++;
    while (src[src_len])
        src_len++;
    if (size <= dest_len)
        return (size + src_len);
    while (src[j] && j < size - dest_len - 1)
    {
        dest[dest_len + j] = src[j];
        j++;
    }
    dest[dest_len + j] = '\0';
    return (dest_len + src_len);
}