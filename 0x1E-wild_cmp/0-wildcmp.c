#include "holberton.h"

/**
 * wildcmp - compares two strings and handles wildcards
 *
 * @s1: first string (no wildcards)
 * @s2: second string (with wildcards)
 *
 * Return: 1 if match, or 0
 */

int wildcmp(char *s1, char *s2)
{
	if ((*s1 == *s2) || (*s1 == 0 && *s2 == 0))
	{
		if (*s1 == 0 && *s2 == 0)
			return (1);
		return (wildcmp(s1 + 1, s2 + 1));
	}
	else if (*s1 == 0 && *s2 == '*')
		return (wildcmp(s1, s2 + 1));
	else if (*s2 == '*' && !(*s1 == 0))
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	return (0);
}
