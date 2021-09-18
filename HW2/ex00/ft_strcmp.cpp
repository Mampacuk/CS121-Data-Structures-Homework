#include "sorting.hpp"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (1)
	{
		if (!*s1 || !*s2 || *s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
}