#ifndef GET_NEXT_LINE_H
# define GET_NEXTLINE_H

# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>
# include<unistd.h>

char	*ft_cadd(char *line, char c);
int	ft_strlen(char	*str);
char	*get_next_line(int fd);
char	*get_line(int fd);

#endif