/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedalexa <pedalexa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:47:45 by pedalexa          #+#    #+#             */
/*   Updated: 2024/03/07 15:05:01 by pedalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_ber(char *map_file)
{
	int	i;

	i = 0;
	if (!map_file)
		return (0);
	while (map_file[i])
	{
		i++;
	}
	i--;
	if (map_file[i] == 'r' && map_file[i - 1] == 'e'
		&& map_file[i - 2] == 'b' && map_file[i - 3] == '.')
		return (1);
	else
		return (0);
}

static void	if_endline(char	*line, char *map_temp)
{
	if (line[0] == '\0' || line[0] == '\n')
	{
		free(line);
		free(map_temp);
		error_messages("Insert a valid map!\n");
	}
}

static void	if_map_is_empty(char *map_temp)
{
	if (map_temp == NULL || map_temp[0] == '\0')
	{
		free(map_temp);
		error_messages("Map is not valid!");
	}
}

char	**read_map(char *path)
{
	int		fd;
	char	*line;
	char	*temp;
	char	*map_temp;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_temp = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if_endline(line, map_temp);
		temp = map_temp;
		map_temp = ft_strjoin(temp, line);
		free(temp);
		free(line);
	}
	if_map_is_empty(map_temp);
	map = ft_split(map_temp, '\n');
	close(fd);
	return (free(map_temp), map);
}
