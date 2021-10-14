#include "philo.h"

char	*ft_strcat(char *dst, char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (dst && dst[i])
		++i;
	while (src && src[j])
	{
		dst[i + j] = src[j];
		++j;
	}
	dst[i + j] = '\0';
	return (dst);
}