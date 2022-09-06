/**
 * *_strncat - concatenates 2 strings
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
