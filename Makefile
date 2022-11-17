NAME = miniescape

COLOR_ESC			= \033
COLOR_WHITE			= $(COLOR_ESC)[97m
COLOR_CYAN			= $(COLOR_ESC)[96m
COLOR_GREEN			= $(COLOR_ESC)[32m
COLOR_BLUE			= $(COLOR_ESC)[34m
COLOR_YELLOW		= $(COLOR_ESC)[33m
COLOR_MAGENTA 		= $(COLOR_ESC)[35m
COLOR_BOLD			= $(COLOR_ESC)[1m
COLOR_RESET			= $(COLOR_ESC)[0m
COLOR_RESET_BOLD	= $(COLOR_ESC)[21m

PATH_HEADER			= includes/
PATH_GAME			= src_game/
PATH_LEVEL			= src_level/
PATH_UTIL			= src_util/
PATH_OBJ			= objs/

HEADER				= 	miniescape.h includes.h
SRC_GAME			= 	main.c game.c congratulation.c
SRC_LEVEL			= 	level1.c level2.c level3.c level4.c
SRC_UTIL			= 	utils.c

SRC_GAMES			= $(addprefix $(PATH_GAME),$(SRC_GAME))
SRC_LEVELS			= $(addprefix $(PATH_LEVEL),$(SRC_LEVEL))
SRC_UTILS			= $(addprefix $(PATH_UTIL),$(SRC_UTIL))

SRCS 				= $(SRC_GAMES) $(SRC_LEVELS) $(SRC_UTILS)

OBJ					= $(SRCS:.c=.o)
OBJS				= $(addprefix $(PATH_OBJ),$(OBJ))
HEADERS				= $(addprefix $(PATH_HEADER),$(HEADER))

DEBUG				= 0
DEBUGING			=  -g3 -fsanitize=address
CFLAGS				= -o3


#ifeq ($(DEBUG), 1)
	CFLAGS += $(DEBUGING)
#endif

OPTIONS				= -I$(PATH_HEADER) -I$(HOME)/.brew/opt/readline/include
LIBS				= -L$(HOME)/.brew/opt/readline/lib/ -lreadline -lhistory
CC					= gcc
RM					= rm -rf

$(PATH_OBJ)$(PATH_GAME)%.o	: $(PATH_GAME)%.c $(HEADERS)
	@mkdir -p $(PATH_OBJ)$(PATH_GAME)
	@$(CC) $(CFLAGS) $(OPTIONS) -o $(@) -c $(<)
	@printf "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] COMPILATION $(COLOR_CYAN)DEBUG => [%s] $(COLOR_BOLD)GAME\t=>\t$(COLOR_WHITE)%s$(COLOR_RESET)\n" $(DEBUG) $<

$(PATH_OBJ)$(PATH_LEVEL)%.o	: $(PATH_LEVEL)%.c $(HEADERS)
	@mkdir -p $(PATH_OBJ)$(PATH_LEVEL)
	@$(CC) $(CFLAGS) $(OPTIONS) -o $(@) -c $(<)
	@printf "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] COMPILATION $(COLOR_BLUE)LEVEL => [%s] $(COLOR_BOLD)LEVEL\t=>\t$(COLOR_WHITE)%s$(COLOR_RESET)\n" $(DEBUG) $<

$(PATH_OBJ)$(PATH_UTIL)%.o	: $(PATH_UTIL)%.c $(HEADERS)
	@mkdir -p $(PATH_OBJ)$(PATH_UTIL)
	@$(CC) $(CFLAGS) $(OPTIONS) -o $(@) -c $(<)
	@printf "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] COMPILATION $(COLOR_YELLOW)DEBUG => [%s] $(COLOR_BOLD)UTIL\t=>\t$(COLOR_WHITE)%s$(COLOR_RESET)\n" $(DEBUG) $<

all			: $(NAME)

$(NAME)		: $(OBJS)
	@$(CC) $(CFLAGS) $(OPTIONS) -o $(@) $(^) $(LIBS)
	@echo "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] LINKAGE $(COLOR_BOLD)ALL OBJS FILE =>\n\t $(COLOR_WHITE)$(^:.o=.o\n\t)"
	@echo "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] COMPILATION FINISH !$(COLOR_WHITE)$(COLOR_RESET_BOLD)"

clean		:
	@$(RM) $(OBJS)
	@$(RM) $(PATH_OBJ)
	@echo "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] DELETE $(COLOR_BOLD)ALL OBJS FILE =>\n\t $(COLOR_WHITE)$(OBJS:.o=.o\n\t)"
	@echo "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] CLEAN FINISH !$(COLOR_RESET)"

fclean		: clean
	@$(RM) $(NAME)
	@echo "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] DELETE $(COLOR_BOLD)PROGRAMME =>\n\t $(COLOR_WHITE)$(NAME)"
	@echo "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] FCLEAN FINISH !$(COLOR_RESET)"


re			: fclean all

.PHONY: all fclean clean re


