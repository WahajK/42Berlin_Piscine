#include "rush02.h"
#include <stdlib.h>

// Function to print strings
void ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

// Function to check if the string represents a valid positive number
int is_valid_number(char *str)
{
    int i = 0;

    if (str[0] == '-')
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

// Function to convert string to integer (similar to atoi)
int ft_atoi(char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    // Skip leading whitespaces
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;

    // Check for optional '+' or '-' sign
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;

    // Convert string to integer
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return (result * sign);
}

// Function to duplicate a string (like strdup)
char *ft_strdup(char *src)
{
    int len = 0;
    char *dup;
    int i = 0;

    // Calculate length of source string
    while (src[len])
        len++;

    // Allocate memory for the duplicate string
    dup = (char *)malloc(sizeof(char) * (len + 1));
    if (!dup)
        return (NULL);

    // Copy the string
    while (src[i])
    {
        dup[i] = src[i];
        i++;
    }
    dup[i] = '\0'; // Null-terminate the string

    return (dup);
}

// Function to trim leading and trailing spaces from a string
void trim_spaces(char *str)
{
    int start = 0;
    int end = 0;

    // Find the first non-space character
    while (str[start] == ' ' || str[start] == '\t')
        start++;

    // Find the last non-space character
    end = start;
    while (str[end])
        end++;
    end--;

    while (end > start && (str[end] == ' ' || str[end] == '\t'))
        end--;

    // Shift the string left to remove leading spaces
    int i = 0;
    while (start <= end)
    {
        str[i] = str[start];
        i++;
        start++;
    }
    str[i] = '\0'; // Null-terminate
}
// Function to concatenate two strings (like strcat)
char *ft_strcat(char *dest, const char *src)
{
    char *ptr = dest;

    // Move ptr to the end of dest string
    while (*ptr)
        ptr++;

    // Copy src to the end of dest
    while (*src)
        *ptr++ = *src++;

    *ptr = '\0';  // Null-terminate the concatenated string
    return dest;
}

// Function to free memory allocated for dictionary entries
void free_dict(t_dict *dictionary)
{
    int i = 0;

    while (dictionary[i].number)
    {
        free(dictionary[i].word);
        i++;
    }
    free(dictionary);
}
// Function to find the first occurrence of a character in a string
char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }
    // Check for '\0' character match
    if (*s == (char)c)
        return (char *)s;
    return NULL;
}

