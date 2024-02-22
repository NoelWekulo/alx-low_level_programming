/* dynamic_library.c */

#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to write
 * Return: On success, returns the written character. On error, -1 is returned.
 */
int _putchar(char c) {
    return write(1, &c, 1);
}

/**
 * _islower - Checks if a character is lowercase
 * @c: The character to check
 * Return: 1 if the character is lowercase, 0 otherwise.
 */
int _islower(int c) {
    return (c >= 'a' && c <= 'z');
}

/**
 * _isalpha - Checks if a character is alphabetic
 * @c: The character to check
 * Return: 1 if the character is alphabetic, 0 otherwise.
 */
int _isalpha(int c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * _abs - Computes the absolute value of an integer
 * @n: The integer to compute the absolute value of
 * Return: The absolute value of the integer.
 */
int _abs(int n) {
    return (n < 0) ? -n : n;
}

/**
 * _isupper - Checks if a character is uppercase
 * @c: The character to check
 * Return: 1 if the character is uppercase, 0 otherwise.
 */
int _isupper(int c) {
    return (c >= 'A' && c <= 'Z');
}

/**
 * _isdigit - Checks if a character is a digit
 * @c: The character to check
 * Return: 1 if the character is a digit, 0 otherwise.
 */
int _isdigit(int c) {
    return (c >= '0' && c <= '9');
}

/**
 * _strlen - Computes the length of a string
 * @s: The string to compute the length of
 * Return: The length of the string.
 */
int _strlen(char *s) {
    int length = 0;
    while (*s != '\0') {
        length++;
        s++;
    }
    return length;
}

/**
 * _puts - Writes a string to stdout followed by a newline
 * @s: The string to write
 */
void _puts(char *s) {
    while (*s != '\0') {
        _putchar(*s);
        s++;
    }
    _putchar('\n');
}

/**
 * _strcpy - Copies a string to another string
 * @dest: The destination string
 * @src: The source string
 * Return: The pointer to the destination string.
 */
char *_strcpy(char *dest, char *src) {
    char *original_dest = dest;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; /* Null-terminate the destination string */
    return original_dest;
}
/**
 * _atoi - Converts a string to an integer
 * @s: The string to convert
 * Return: The converted integer.
 */
int _atoi(char *s) {
    int result = 0;
    int sign = 1;

    if (*s == '-') {
        sign = -1;
        s++;
    }

    while (*s >= '0' && *s <= '9') {
        result = result * 10 + (*s - '0');
        s++;
    }

    return sign * result;
}

/**
 * _strcat - Concatenates two strings
 * @dest: The destination string
 * @src: The source string
 * Return: The pointer to the destination string.
 */
char *_strcat(char *dest, char *src) {
    char *original_dest = dest;

    while (*dest != '\0') {
        dest++;
    }

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0'; /* Null-terminate the concatenated string */
    return original_dest;
}

/**
 * _strncat - Concatenates n characters from one string to another
 * @dest: The destination string
 * @src: The source string
 * @n: The number of characters to concatenate
 * Return: The pointer to the destination string.
 */
char *_strncat(char *dest, char *src, int n) {
    char *original_dest = dest;

    while (*dest != '\0') {
        dest++;
    }

    while (*src != '\0' && n > 0) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }

    *dest = '\0'; /* Null-terminate the concatenated string */
    return original_dest;
}

/**
 * _strncpy - Copies n characters from one string to another
 * @dest: The destination string
 * @src: The source string
 * @n: The number of characters to copy
 * Return: The pointer to the destination string.
 */
char *_strncpy(char *dest, char *src, int n) {
    char *original_dest = dest;

    while (*src != '\0' && n > 0) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }

    /* Pad the destination string with null characters if needed */
    while (n > 0) {
        *dest = '\0';
        dest++;
        n--;
    }

    return original_dest;
}

/**
 * _strcmp - Compares two strings
 * @s1: The first string
 * @s2: The second string
 * Return: 0 if the strings are equal, a negative value if s1 is less than s2,
 * and a positive value if s1 is greater than s2.
 */
int _strcmp(char *s1, char *s2) {
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }

    return (*s1 - *s2);
}

/**
 * _memset - Sets the first n bytes of a memory area to a specific value
 * @s: The memory area to set
 * @b: The value to set
 * @n: The number of bytes to set
 * Return: The pointer to the memory area.
 */
char *_memset(char *s, char b, unsigned int n) {
    while (n > 0) {
        *s = b;
        s++;
        n--;
    }
    return s;
}

/**
 * _memcpy - Copies n bytes from one memory area to another
 * @dest: The destination memory area
 * @src: The source memory area
 * @n: The number of bytes to copy
 * Return: The pointer to the destination memory area.
 */
char *_memcpy(char *dest, char *src, unsigned int n) {
    char *original_dest = dest;

    while (n > 0) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }

    return original_dest;
}

/**
 * _strchr - Locates the first occurrence of a character in a string
 * @s: The string to search
 * @c: The character to locate
 * Return: The pointer to the first occurrence of the character in the string,
 * or NULL if the character is not found.
 */
char *_strchr(char *s, char c) {
    while (*s != '\0') {
        if (*s == c) {
            return s;
        }
        s++;
    }

    return NULL; /* Character not found */
}

/**
 * _strspn - Calculates the length of the initial segment of a string
 * consisting of only characters from another string
 * @s: The string to check
 * @accept: The string containing characters to match
 * Return: The length of the initial segment of s consisting of only characters
 * from accept.
 */
unsigned int _strspn(char *s, char *accept) {
    unsigned int count = 0;

    while (*s != '\0' && strchr(accept, *s) != NULL) {
        count++;
        s++;
    }

    return count;
}

/**
 * _strpbrk - Searches a string for any of a set of characters
 * @s: The string to search
 * @accept: The string containing characters to search for
 * Return: The pointer to the first occurrence of any character from accept
 * in the string s, or NULL if no such character is found.
 */
char *_strpbrk(char *s, char *accept) {
    while (*s != '\0') {
        if (strchr(accept, *s) != NULL) {
            return s;
        }
        s++;
    }

    return NULL; /* No matching characters found */
}

/**
 * _strstr - Locates a substring in another string
 * @haystack: The string to search
 * @needle: The substring to locate
 * Return: The pointer to the first occurrence of the substring in the string,
 * or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle) {
    while (*haystack != '\0') {
        char *h = haystack;
        char *n = needle;

        while (*n != '\0' && *h == *n) {
            h++;
            n++;
        }

        if (*n == '\0') {
            return haystack; /* Needle found in haystack */
        }

        haystack++;
    }

    return NULL; /* Needle not found in haystack */
}
