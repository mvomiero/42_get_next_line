/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:51:04 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/26 19:23:52 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// Headers for functions: malloc, free, read
# include <stdlib.h>
# include <unistd.h>

static char	*extract_stash(int fd, char *buf, char *stash);
static char	*extract_line(char *line);
char *get_next_line(int fd);


#ifndef BUFFER_SIZE
# define BUFFER_SIZE = 5
# endif





#endif