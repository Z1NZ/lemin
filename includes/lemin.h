# ifndef LEMIN_H
# define LEMIN_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define CHECK_BIT(var, pos)	(var & pos)
# define ANTS	1
# define ROOMS	2
# define START	4
# define END	8
# define LINKS	16

# define BUFF_SIZE 4

# define STOP      	"\033[0m"
# define BOLD       "\033[1m"
# define ITALIC     "\033[3m"
# define UNDERLINE  "\033[4m"
# define BLACK   	"\033[30m"
# define RED     	"\033[31m"
# define GREEN   	"\033[32m"
# define YELLOW  	"\033[33m"
# define BLUE   	"\033[34m"
# define MAGENTA 	"\033[35m"
# define CYAN    	"\033[36m"
# define WHITE   	"\033[37m"


typedef struct			s_struct
{
	char				*s1;
	char				*s2;
	int					fd;
	int					pad;
	struct s_struct		*next;
	struct s_struct		*prev;
}						t_struct;

typedef struct			s_links
{
	struct s_lst		*lst;
	struct s_links		*next;
}						t_links;

typedef struct			s_lst
{
	int					x;
	int					y;
	int					value;
	int					ant;
	char				*name;
	t_links				*links;
	struct s_lst		*next;
}						t_lst;
typedef struct			s_data
{
	t_lst				*lst;
	int					status;
	int					nb_ant;
	char				*start;//wtf ????
	char				*end;// wtf ??
}						t_data;

/*
** algo
*/
void	init_tree(t_lst *start, t_lst *end, t_data *data);
void	clean_list(t_links *tmp);
t_links 	*add_list(t_links *dest, t_links *src, t_data *data);
int		find_way(t_data *data);
t_links *discover_tree(t_lst *end, t_data *data);
t_links *add_top_link(t_links *links, t_links *src, t_data *data);
/*
** parsing
*/

void	add_rooms(t_data *data, t_lst *ptr);
int		get_nb(char *s);
int		add_links(t_lst *ptr1, t_lst *ptr2, t_data *data);
int		check_line(char *line);
void	check_startend(char *line, t_data *data);
int		check_links(char *line, t_lst *lst, t_data *data);
int		get_ants(char *line, t_data *data);
t_lst	*check_exist(char *s, t_lst *lst);
int		get_links(char *line, t_data *data);
int		next_step(char *line, t_data *data);
int		check_room(char *s);
int		check_name(char *s);
int		count_space(char *s);
int		check_nb(char *s);
int		count_char(char *s, char c);
int		ft_error(int i);
int		get_rooms(char *line, t_data *data);

/*
**	printer
*/

void	print_lst(t_lst *lst);
void	print_lst_links(t_lst *lst);
void 	ft_print_way(t_data *data, t_links *tmp);
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
char			*ft_strdup(const char *s1);
int				ft_atoi(const char *str);
int				ft_isdig_str(char *ptr);
void			ft_free_tab(char **str);
int				tab_len(char **tab);
/*
** tools
*/
void			ft_free(t_data *data);
void			ft_free_lst(t_lst *lst);
void			ft_exit(t_data *data);





#endif
