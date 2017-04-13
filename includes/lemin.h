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
# include <unistd.h>

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
void    add_rooms(t_lst *src, t_lst *ptr);
int		get_nb(char *s);
/*
** checking.c
 */
int		check_line(char *line);
void	check_startend(char *line, t_data *data);
int		check_links(char *line, t_lst *lst);
int		get_ants(char *line);
int		check_exist(char *s, t_lst *lst);
int		get_links(char *line, t_lst *lst);
int		next_step(char *line, t_data *data);
int		check_room(char *s);
int		check_name(char *s);
int		count_space(char *s);
int		check_nb(char *s);
int		count_char(char *s, char c);
int		ft_error(int i);
int		get_rooms(char *line, t_data *data);
void	print_lst(t_lst *lst);
/*
** libft
*/
int				get_next_line(int const fd, char **line);
size_t			ft_strlen(const char *s);
void			ft_putstr(char const *s);
void			*ft_memalloc(size_t size);
void			ft_putnbr(int n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			ft_putchar(char c);
char			*ft_strchr(char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
char			**ft_strsplit(char *s, char c);
int				ft_isdigit(int c);





#endif
