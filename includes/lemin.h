	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 05:59:47 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/04 06:35:12 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LEMIN_H
# define LEMIN_H
# include <stdlib.h>

# define CHECK_BIT(var, pos)	(var & pos)
# define ANTS	1
# define ROOMS	2
# define START	4
# define END	8
# define LINKS	16

# define BUFF_SIZE 4

typedef struct			s_struct
{
	char				*s1;
	char				*s2;
	int					fd;
	struct s_struct		*next;
	struct s_struct		*prev;
}						t_struct;

typedef struct			s_links
{
	char				*name;
	struct s_links		*next;
}						t_links;

typedef struct			s_lst
{
	int					x;
	int					y;
	char				*name;
	struct s_lst		*next;
}						t_lst;
typedef struct	s_data
{
	t_lst		*lst;
	int			status;
	int			nb_ant;
	char		*start; // wtf ????
	char		*end;// wtf ??
}				t_data;

/*
** ft_splitnb.c
 */
t_lst	*add_rooms(t_lst *lst, char *str, int y, int x);
int		get_nb(char *s);
int		ft_splitnb(char *s, t_rooms *r);
/*
** checking.c
 */
int		check_line(char *line);
void	check_startend(char *line, t_rooms *r, t_lst *lst);
void	check_links(char *line, t_lst *lst);
int		get_ants(char *line);
int		check_exist(char *s, t_lst *lst);

void	init_all(char **line, t_rooms *r, t_lst *lst);

int		get_links(char *line, t_lst *lst);
int		next_step(char *line, t_lst *lst, t_rooms *r);
int		check_hash(char *line, t_rooms *r, t_lst *lst);
int		check_room(char *s);
int		check_name(char *s);
int		count_space(char *s);
int		check_nb(char *s);
int		count_char(char *s, char c);
int		ft_error(int i);
int		get_rooms(char *line, t_rooms *r, t_lst *lst);
void	print_lst(t_lst *lst);
/*
** libft
*/
int				get_next_line(int const fd, char **line);
size_t			ft_strlen(const char *s);
void			ft_putstr(char const *s);



#endif
