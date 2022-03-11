#include <stdio.h>

int	find(char c, char *s2);

void	ft_inter(char *s1, char *s2, char *out)
{
	int		i = 0;
	int		j = 0;

	while (s1[i])
	{
		if(find(s1[i], s2))
			if(!find(s1[i], out))
				out[j++] = s1[i];
		++i;
	}
}

int	find(char c, char *s2)
{
	int	j = 0;

	while (s2[j])
	{
		if(s2[j] == c)
			return (1);
		j++;
	}
	return (0);
}

int main(int ac, char **av)
{
	int	i = 0;
	char out[257];
	
	while (i < 257)
		out[i++] = 0;
	if (ac == 3)
	{
		ft_inter(av[1], av[2], out);
	}
	printf("%s\n", out);
	return(0);
}
