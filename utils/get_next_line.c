//
// Created by Dali on 16/03/2023.
//

#include "../headers/utils.h"

char
*get_next_line(int fd)
{
	char	tmp[2];
	char	*dest = "";
	int	i = 0;
	int	j = 0;

	my_memset(dest, 0, my_strlen(dest));
	while ("Dali") {
		if ((read(fd, tmp, 1)) == -1)
			return (j == 0 ? NULL : dest);
		if (tmp[i] == '\n')
			return (dest);
		if ((tmp[0]) == 0)
			return (NULL);
		dest = my_strcat(dest, tmp);
		j += 1;
	}
}

void
my_memset(char *src, int j, int m)
{
	int	i = 0;

	for (i = 0; i < m; i += 1)
		src[i] = j;
}
