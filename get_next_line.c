/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:58:28 by husaltam          #+#    #+#             */
/*   Updated: 2025/03/01 14:59:21 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_first_line(char *text)
{
	char	*str;
	int		i;
	int		len;

	if (!text)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
	{
		free(text);
		return (NULL);
	}
	len = ft_strlen(text + i + 1);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
	{
		free(text);
		return (NULL);
	}
	ft_strlcpy(str, text + i + 1, len + 1);
	free(text);
	return (str);
}

char	*ft_join_free(char *text, char *buffer)
{
	char	*new_str;
	char	*start;
	int		len1;
	int		len2;

	if (!text || !buffer)
		return (NULL);
	len1 = ft_strlen(text);
	len2 = ft_strlen(buffer);
	new_str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!new_str)
	{
		free(text);
		return (NULL);
	}
	start = new_str;
	while (*text)
		*new_str++ = *text++;
	while (*buffer)
		*new_str++ = *buffer++;
	*new_str = '\0';
	free(text - len1);
	return (start);
}

char	*first_line(int fd, char *text)
{
	char	*temp;
	int		bytes_size;

	bytes_size = 1;
	if (!text)
		text = ft_calloc(1, 1);
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (bytes_size > 0)
	{
		bytes_size = read(fd, temp, BUFFER_SIZE);
		if (bytes_size == -1)
		{
			free (text);
			free (temp);
			return (NULL);
		}
		temp[bytes_size] = '\0';
		text = ft_join_free(text, temp);
		if (ft_strchr(text, '\n'))
			break ;
	}
	free (temp);
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;
	int			i;

	text = first_line(fd, text);
	i = 0;
	if (!text || !text[i] || fd < 0 || BUFFER_SIZE <= 0)
	{
		free(text);
		text = NULL;
		return (NULL);
	}
	while (text[i] && text[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (text[++i] && text[i] != '\n')
		line[i] = text[i];
	if (text[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	text = clean_first_line(text);
	return (line);
}

/*int main(void)
{
    int		fd;
    char	*line;

    fd = open("file1.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);

    return (0);
}*/
