/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:56:28 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/19 19:13:48 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_bool	legal_connections(t_char buf[PIECE_SIZE])
{
	t_uint8		block_connections;
	t_uint8		i;

	i = 0;
	block_connections = 0;
	while (PIECE_SIZE > i)
	{
		if (buf[i] == '#')
		{
			if ((i + 1) < PIECE_SIZE && buf[i + 1] == '#')
				block_connections++;
			if ((i - 1) >= 0 && buf[i - 1] == '#')
				block_connections++;
			if ((i + 5) < PIECE_SIZE && buf[i + 5] == '#')
				block_connections++;
			if ((i - 5) >= 0 && buf[i - 5] == '#')
				block_connections++;
		}
		i++;
	}
	return (block_connections == 6 || block_connections == 8);
}

/*
** The checksum starts with the number of times the conditions should
** return true (i.e 1). 4 times for the hash character, 12 times for the
** dot character and 4 times for the return line; not more, not less.
**
** By the end of the process, 'checksum' should be equal to precisely 0.
*/

static t_bool	legal_characters(t_char buf[PIECE_SIZE])
{
	t_uint8		checksum;
	t_uint8		row;
	t_uint8		i;

	i = -1;
	row = -1;
	checksum = (4 * 1) + (12 * 2) + (4 * 3);
	while (PIECE_ROWS > ++row)
	{
		checksum -= (buf[++i] == '#');
		checksum -= (buf[i] == '.') ? 2 : 0;
		checksum -= (buf[++i] == '#');
		checksum -= (buf[i] == '.') ? 2 : 0;
		checksum -= (buf[++i] == '#');
		checksum -= (buf[i] == '.') ? 2 : 0;
		checksum -= (buf[++i] == '#');
		checksum -= (buf[i] == '.') ? 2 : 0;
		checksum -= (buf[++i] == '\n') ? 3 : 0;
	}
	return (checksum == 0);
}

t_game			read_pieces(ssize_t fd)
{
	t_game		tetromino;
	t_char		buf[PIECE_SIZE];
	t_char		piece_id;
	t_int8		i;

	i = -1;
	piece_id = 'A';
	while (MAX_PIECES > ++i)
	{
		read(fd, buf, PIECE_SIZE);
		if (!(legal_characters(buf) && legal_connections(buf)))
			EXIT(INVALID_INPUT);
		PIECE(i).id = piece_id++;
		PIECE(i).mask = get_piece_mask(0, buf);
		PIECE(i).width = get_piece_width(buf);
		PIECE(i).height = get_piece_height(buf);
		if (read(fd, buf, 1) == 0)
			break ;
		else if (buf[0] != '\n')
			EXIT(INVALID_INPUT);
	}
	tetromino.num_pieces = i + 1;
	return (tetromino);
}