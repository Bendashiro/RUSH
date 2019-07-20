/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahaddac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 15:33:08 by nahaddac          #+#    #+#             */
/*   Updated: 2019/07/20 19:32:30 by nahaddac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 32000

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_strlen(char *str)
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
int ft_read(int size_arg, char *av)
{
	int fd;
	int ret;
	char buf[BUF_SIZE + 1];
	char *const;

	fd = open("dict", O_RDONLY);
	if (fd == -1)
		ft_putstr("open() failed\n");
	while ((len = read(fd, buf, BUF_SIZE)) =! '\0')
	{
		;
	}

	const = malloc(len * sizeof(char));
	len = 0;
	while ((len = read(fd, buf, BUF_SIZE)) != '\0')
	{
		ft_strcat(const, buf);
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
	int fd;
	int ret;


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

