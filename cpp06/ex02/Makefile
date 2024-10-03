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
C++ = c++
CPPFLAGS = -Werror -Wall -Wextra -g -std=c++98

# File-related variables
NAME = Bureaucrat
RM = rm -rf
SDIR := srcs
ODIR := obj

# Source files
SOURCES := main.cpp\
			Serializer.cpp\

# Object files
OBJECTS := $(patsubst %.cpp,$(ODIR)/%.o,$(SOURCES))

TOTAL_FILES := $(words $(SOURCES))
COMPILED_FILES := $(shell if [ -d "$(ODIR)" ]; then find $(ODIR) -name "*.o" | wc -l; else echo 0; fi)

# Targets
all : ${NAME}

${NAME} : ${OBJECTS}
	@${C++} ${CPPFLAGS} ${OBJECTS} -o ${NAME}
	@printf "$(GRN)➾ Compilation progress: $$(echo "$(shell find $(ODIR) -name "*.o" | wc -l) $(TOTAL_FILES)" | awk '{printf "%.2f", $$1/$$2 * 100}')%%$(RES)\r"
	@echo "\n$(GRN)➾ ${NAME} created$(RES)"
	@printf "\n"

$(ODIR)/%.o: $(SDIR)/%.cpp | $(ODIR)
	@mkdir -p $(dir $@)
	@$(C++) $(CPPFLAGS) -c -o $@ $<
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
