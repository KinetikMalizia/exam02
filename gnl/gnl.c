/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:06:14 by fmalizia          #+#    #+#             */
/*   Updated: 2022/03/11 14:22:35 by fmalizia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char	*str)
{
	int	i = 0;

	while (str[i])
		++i;
	return (i);
}

char	*get_next_line(int fd)
{
	char	*result;

	if (fd < 0)
		return (NULL);
	result = get_line(fd);
	return (result);
}

char	*get_line(int fd)
{
	int		a = 1;
	char	*buffer = NULL;
	char	*line = NULL;

	buffer = malloc(sizeof(char) * 2);
	while (a)
	{
		a = read(fd, buffer, 1);
		if (a == -1)
		{
			if (buffer)
				free(buffer);
			free(line);
			return (NULL);
		}
		if (a == 0)
		{
			free(buffer);
			return (line);
		}
		buffer [1] = 0;
		if (buffer[0] == '\n')
		{
			line = ft_cadd(line, buffer[0]);
			free(buffer);
			return (line);
		}
		line = ft_cadd(line, buffer[0]);
	}
	return (line);
}

char	*ft_cadd(char *line, char c)
{
	char	*result;
	int		i = 0;

	if (!line)
	{
		line = malloc(1);
		line[1] = 0;
	}
	result = malloc(ft_strlen(line) + 2);
	while (line[i])
	{
		result[i] = line[i];
		++i;
	}
	result[i] = c;
	result[i + 1] = 0;
	free (line);
	return (result);
}
/*
int	main(void)
{
	int	fd = 0;
	int	i = 0;
	char	*butt;
	
	fd = open("test.txt", O_RDONLY);
	while (i < 10)
	{
		butt = ft_get_next_line(fd);
		printf("[%d] %s", i, butt);
		++i;
	}
}
*/
