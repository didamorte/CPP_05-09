NAME	:= Bureaucrat
CC		:= c++
FLAGS	:= -Wall -Wextra -Werror -g -std=c++98

# Source Files

SRCS := main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

OBJS := $(SRCS:.cpp=.o)

# Main Target
all: $(NAME)

# Executable Creation
$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	$(CC) $(FLAGS) -o $@ $(OBJS)

# Compilation Rule
%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

# Cleaning Rules
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f *_shrubbery

re: fclean all

.PHONY: all clean fclean re