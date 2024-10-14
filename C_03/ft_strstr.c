#include <unistd.h>

char *strstr(char *str, char *to_find)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] == to_find[j])
        {
            while (str[i + j] == to_find[j])
            {
                if (!to_find[j + 1])
                    return (&str[i]);
                j++;
            }
        }
        i++;
    }
    return (0);
}