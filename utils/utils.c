//
// Created by Dali on 16/03/2023.
//

#include "../headers/utils.h"

int
my_strlen(char *str)
{
	int	i = 0;

	for (i = 0; str[i]; i += 1);
	return (i);
}

char
*my_strcpy(char *str)
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

int
my_getnbr(char *str)
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

char
*my_strcat(char *src, char *dest)
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

int
my_strcmp(char *s1, char *s2)
{
    for (int i = 0; s1[i] && s2[i]; i += 1)
    {
        if (s1[i] != s2[i])
        {
            return -1;
        }
    }
    return (1);
}

char
**my_strtab(char *str, char sep)
{
    char	**tab;
    int	idx_tab;
    int	i = 0;
    int	len = 0;
    int	j = 0;
    int	toto = my_eolen(str, sep) + sizeof(char *);

    if ((tab = malloc(sizeof(char *) * toto)) == NULL)
        return (NULL);
    for (idx_tab = 0; idx_tab < my_eolen(str, sep) + 1; idx_tab += 1) {
        for (; str[i] != sep && str[i]; i += 1, len += 1);
        if ((tab[idx_tab] = malloc(sizeof(char) * len + 1)) == NULL)
            return (NULL);
        remplitab(tab[idx_tab], str, j, sep);
        for (; str[j] != sep && str[j]; j += 1);
        len = 0;
        i += 1;
        j += 1;
    }
    tab[idx_tab] = NULL;
    return (tab);
}

char
*remplitab(char *dest, char *src, int j, char sep)
{
    int	idx = 0;

    for (idx = 0; src[j] != sep && src[j]; idx += 1, j += 1)
        dest[idx] = src[j];
    dest[idx] = 0;
    return (dest);
}

int
my_eolen(char *str, char sep)
{
    int	idx_len = 0;
    int	idx_str = 0;

    for (idx_len = 0; str[idx_str]; idx_str += 1)
        str[idx_str] == sep ? idx_len += 1 : 0;
    return (idx_len);
}