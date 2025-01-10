.PHONY: all clean re

NAME = phonebook
FLAG = -std=c++98

CLASSES_DIR = classes
INCLUDE_DIR = include
SRCS_DIR = srcs

SRCS = \
$(addsuffix .cpp, \
	$(addprefix $(SRCS_DIR)/, \
		main \
	) \
	$(addprefix $(CLASSES_DIR)/, \
		Contact \
		PhoneBook \
	) \
) \

all: $(NAME)

$(NAME):
	g++ -o $(NAME) $(FLAG) -I$(INCLUDE_DIR) $(SRCS)

clean:
	rm -f $(NAME)

re: clean all
