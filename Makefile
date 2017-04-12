#	Library output
NAME = lem-in

#	GCC flags
CFLAGS = -Wall -Wextra -Werror -g

#	Includes directories
INC_TR = includes
INCLUDES += $(addprefix -iquote , $(INC_TR))

#	Sources
LEM_IN_SOURCES = $(shell find lib | grep "\.c$$" | sed "s/\.c$$//g")
LEM_IN_HEADERS = $(shell find includes | grep "\.h$$")
SRCS = $(addsuffix .c, $(LEM_IN_SOURCES))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo ">>>>> Génération de LEM_IN"
	@gcc $(OBJS) -o $(NAME)
	@echo "Terminée"

# To obtain object files
%.o: %.c $(LEM_IN_HEADERS)
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

# To remove generated files
clean:
	@echo "RM\ttous les objects (.o)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "RM\tprojet ($(NAME))"
	@$(RM) $(NAME)

re: fclean all

git:
	@git add .
	@echo "Enter Your Commit :"
	@read var1 ; git commit -m "$$var1"
	@git push