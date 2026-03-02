/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:14:02 by niguilbe          #+#    #+#             */
/*   Updated: 2025/09/19 11:23:05 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*find_new_line(char *s)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == '\n')
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*extract_line(char *saved)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!saved || saved[0] == '\0')
		return (NULL);
	while (saved[i] && saved[i] != '\n')
		i++;
	if (saved[i] == '\n')
		i++;
	line = ft_substr(saved, 0, i);
	return (line);
}

char	*read_until_line(int fd, char *saved, char *buf)
{
	int		bytes_read;
	char	*tmp;

	bytes_read = 1;
	if (find_new_line(saved))
		return (saved);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(saved);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		tmp = saved;
		saved = ft_strjoin(tmp, buf);
		free(tmp);
		if (!saved)
			return (NULL);
		if (find_new_line(saved))
			break ;
	}
	return (saved);
}

char	*extract_rest(char *full_line)
{
	size_t	i;
	char	*rest;

	i = 0;
	if (!full_line)
		return (NULL);
	while (full_line[i] && full_line[i] != '\n')
		i++;
	if (!full_line[i] || !full_line[i + 1])
	{
		free(full_line);
		return (NULL);
	}
	rest = ft_substr(full_line, i + 1, ft_strlen(full_line) - i - 1);
	free(full_line);
	if (!rest || rest[0] == '\0')
	{
		free(rest);
		return (NULL);
	}
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	saved = read_until_line(fd, saved, buffer);
	free(buffer);
	if (!saved)
		return (NULL);
	line = extract_line(saved);
	saved = extract_rest(saved);
	return (line);
}
/*
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		i;
	int		d;

	d = 1;
	i = -1;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while (++i < 1000 && (line = get_next_line(fd)) != NULL)
	{
		printf("ligne %d : %s", d++, line);
		free(line);
	}
	close(fd);
	return (0);
}
	*/