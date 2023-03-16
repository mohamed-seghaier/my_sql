//
// Created by Dali on 16/03/2023.
//

#include "../headers/utils.h"

int	my_strlen(char *str)
{
	int	i = 0;

	for (i = 0; str[i]; i += 1);
	return (i);
}

char	*my_strcpy(char *str)
{
	char	*dest;
	int	idx = my_strlen(str);

	if ((dest = malloc(sizeof(char) * idx + 1)) == NULL)
		return (NULL);
	for (idx = 0; str[idx]; idx += 1)
		dest[idx] = str[idx];
	dest[idx] = 0;
	return (dest);
}

int	my_getnbr(char *str)
{
	int	i = 0;
	int	nb = 0;
	int	neg = 1;

	if (str[0] == '-') {
		neg = -1;
		i += 1;
	}
	for (; str[i]; i += 1) {
		nb += (str[i] - 48);
		nb *= 10;
	}
	return ((nb * neg) / 10);
}

char	*my_strcat(char *src, char *dest)
{
	int	i = my_strlen(src);
	int	j = my_strlen(dest);
	int	k = 0;
	char	*tmp = malloc(sizeof(char) * (i + j) + 1);

	for (i = 0; src[i]; i += 1, k += 1)
		tmp[k] = src[i];
	for (i = 0; dest[i]; i += 1, k += 1)
		tmp[k] = dest[i];
	return (tmp);
}
