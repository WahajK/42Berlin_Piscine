#include "rush02.h"

int main(int argc, char **argv)
{
    t_dict *dictionary;

    if (argc == 2)
        dictionary = parse_dict("numbers.dict");
    else if (argc == 3)
        dictionary = parse_dict(argv[1]);
    else
    {
        ft_putstr("Error\n");
        return (1);
    }

    if (!dictionary)
    {
        ft_putstr("Dict Error\n");
        return (1);
    }

    if (is_valid_number(argv[argc - 1]))
        print_number(dictionary, argv[argc - 1]);
    else
        ft_putstr("Error\n");

    free_dict(dictionary);
    return (0);
}

