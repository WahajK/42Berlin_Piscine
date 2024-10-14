#include <ctype.h>

int ft_atoi(char *str) {
    int result = 0;
    int sign = 1;

    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r') {
        str++;
    }

    while (*str == '+' || *str == '-') {
        if (*str == '-') {
            sign = -sign;
        }
        str++;
    }

    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    return result * sign;
}