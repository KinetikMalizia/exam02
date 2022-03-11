#include <stdio.h>

int	find(char c, char *s)
{
	int	i = 0;
	
	while(s[i])
	{
		if(s[i] == c)
			return (1);
		++i;	
	}
	return (0);
}

void	ft_union(char *s1, char *s2, char *out)
{
	int	i = 0;
	int	j = 0;

	while (s1[i])
	{
		if (!find(s1[i], out))
		{
			out[j] = s1[i];
			++j;
		}
		++i;
	}
	i = 0;
	while (s2[i])
	{
		if (!find(s2[i], out))
		{
			out[j] = s2[i];
			++j;
		}
		++i;
	}
}

int	main(int ac, char **av)
{
	char	out[257];

	if (ac == 3)
	{
		ft_union(av[1], av[2], out);	
	}
	printf("%s\n", out);
}	
