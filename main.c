/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahaddac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 15:33:08 by nahaddac          #+#    #+#             */
/*   Updated: 2019/07/20 23:13:44 by hibenfet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 32000

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int c;

	i = 0;
	c = ft_strlen(dest);
	while (src[i])
	{
		dest[c + i] = src[i];
		i++;
	}
	dest[c + 1] = '\0';
	return (dest);
}

int		ft_read(int len, char *cont)
{
	int fd;
	char buf[BUF_SIZE + 1];
	//char *cont;

	fd = open("dict", O_RDONLY);
	if (fd == -1)
		ft_putstr("open() failed\n");
	while ((len = read(fd, buf, BUF_SIZE)) != '\0')
	{
		;
	}

	cont = malloc(len * sizeof(char));
	len = 0;
	while ((len = read(fd, buf, BUF_SIZE)) != '\0')
	{
		ft_strcat(cont, buf);
	}

	ft_putstr(buf);
	if (close(fd) == -1)
	{
		ft_putstr("close() error");
	}
	return (0);
}

int main(int argc, char **argv)
{
	int i;
	int j;

	j = 0;
	i = 1;
	if (argc > 3 || argc == 1)
		write(1, "error\n", 6);
	if (argc == 2)
	{
		j = ft_strlen(argv[1]);
		ft_read(j, argv[1]);

	}
}

