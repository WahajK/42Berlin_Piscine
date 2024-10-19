#include "rush02.h"

void print_number(t_dict *dictionary, char *num_str)
{
    int number = ft_atoi(num_str);
    
    if (!convert_to_word(dictionary, number))
        ft_putstr("Dict Error\n");
}

int convert_to_word(t_dict *dictionary, int number)
{
    int i = 0;
    while (dictionary[i].number)
    {
        if (dictionary[i].number == number)
        {
            ft_putstr(dictionary[i].word);
            ft_putstr("\n");
            return (1);
        }
        i++;
    }
    return (0);
}

