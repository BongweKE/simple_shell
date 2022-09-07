#include "main.h"

/**
 * _strchr - return a pointer to the first occurence of a given char
 * in a given string or NULL if not found
 * @s: the given string
 * @c: the given character
 *
 * Return: pointer to c in s or NULL
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')/* terminate at the end of the string */
	{
		if (s[i] == c)
		{
			return (&s[i]);
		}
		i++;
	}
	if (s[i] == c)
	{
		/* on condition we were looking for \0 */
		return (&s[i]);
	}

	/* it was not found */
	return (NULL);

}

/**
 * _strcat - concatenates 2 strings
 * @dest: destination string
 * @src: source string
 * @n: number of bytes from src
 *
 * Return: pointer to resulting string
 */
char *_strcat(char *dest, char *src, int n)
{
	char *result = dest;

	while (*dest)
	{
		dest++;
	}

	while (n != 0)
	{
		*dest++ = *src++;
		n--;
	}

	*dest = '\0';
	return (result);
}

/**
 * _strcmp - compare two strings
 * @s1: first str
 * @s2: second str
 *
 * Return: an integer less than, equal to or greater than 0
 * if s1 is found to be less than, to match, or be greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	/**
	 * given:
	 * address location| *s1 |   |   |   | *s2|  |  |   |
	 * Value of address|   a | b | c | \0|   a| b| p| \0|
	 * compare the location of *s1 and *s2 then move to the next location
	 * until we either find a terminator or find a discrepancy
	 * in this case, it will be when *s1 is on c and *s2 is on p's address
	 */
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2) /* they are totally similar */
	{
		return (0);
	}
	else /* somewhere in the loop we found a disparity */
	{
		return (*s1 - *s2);
	}
}

/**
 * _strcpy - copy a given string to a buffer
 * @src: given string
 * @dest: buffer
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0, len = _strlen(src);

	/* first copy normal chars */
	while (i < len && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	/* fill the rest with terminator */
	while (i <= len)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/**
 * _strlen - count the length of a string
 * @s: the string that we want to know the length of
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

