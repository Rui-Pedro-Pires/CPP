# Color variables
RED = \033[0;31m
GRN = \033[0;32m
YEL = \033[0;33m
BLU = \033[0;34m
MAG = \033[0;35m
CYN = \033[0;36m
WHT = \033[0;37m
RES = \033[0m

# Compiler-related variables
CC = c++
CFLAGS = -Werror -Wall -Wextra -g -std=c++98
VG = valgrind --leak-check=full --show-leak-kinds=all --suppressions=sup --track-origins=yes --log-file=leaks.log

# File-related variables
NAME = phonebook
RM = rm -rf
SDIR := src
ODIR := obj

# Source files
SOURCES := main.cpp \
			Contact.cpp \
			PhoneBook.cpp \

# Object files
OBJECTS := $(patsubst %.cpp,$(ODIR)/%.o,$(SOURCES))

TOTAL_FILES := $(words $(SOURCES))
COMPILED_FILES := $(shell if [ -d "$(ODIR)" ]; then find $(ODIR) -name "*.o" | wc -l; else echo 0; fi)

# Targets
all : ${NAME}

${NAME} : ${OBJECTS}
	@${CC} ${CFLAGS} ${OBJECTS} -o ${NAME}
	@printf "$(GRN)➾ Compilation progress: $$(echo "$(shell find $(ODIR) -name "*.o" | wc -l) $(TOTAL_FILES)" | awk '{printf "%.2f", $$1/$$2 * 100}')%%$(RES)\r"
	@echo "\n$(GRN)➾ ${NAME} created$(RES)"
	@printf "\n"

$(ODIR)/%.o: $(SDIR)/%.cpp | $(ODIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@printf "$(GRN)➾ Compilation progress: $$(echo "$(shell find $(ODIR) -name "*.o" | wc -l) $(TOTAL_FILES)" | awk '{printf "%.2f", $$1/$$2 * 100}')%%$(RES)\r"

# Rest of your Makefile
$(ODIR):
	@mkdir -p $@	

clean :
	@${RM} ${OBJECTS}
	@${RM} ${ODIR}

fclean : clean
	@${RM} ${NAME}
	@echo "${RED}➾ ${NAME} deleted${RES}"

re : fclean all

gdb: re
	gdb --tui $(NAME)

debug: all sup_file
	@echo "$(GREEN)$(NAME) compiled in debug mode!$(DEF_COLOR)"

leaks: ./$(NAME)
	@if [ -f leaks.log ]; then mv leaks.log leaks-old.log; fi
	$(VG) ./$(NAME)

.PHONY: all clean fclean re gdb leaks sup_file debug

define SUP_BODY
{
   name
   Memcheck:Leak
   fun:*alloc
   ...
   obj:*/libreadline.so.*
   ...
}
{
	leak readline
	Memcheck:Leak
	...
	fun:readline
}
{
	leak add_history
	Memcheck:Leak
	...
	fun:add_history
}
endef

sup_file:
	$(file > sup,$(SUP_BODY))
	@echo "$(MAG)Created suppression file to use with valgrind --suppressions=sup$(RES)"