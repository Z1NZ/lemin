/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 04:41:43 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/09 06:23:30 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>

# define BUFF_SIZE 4

int						get_next_line(int const fd, char **line);

typedef struct			s_struct
{
	char				*s1;
	char				*s2;
	int					fd;
	struct s_struct		*next;
	struct s_struct		*prev;
}						t_struct;

#endif
