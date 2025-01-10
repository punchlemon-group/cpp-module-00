.PHONY: all clean re

NAME = tests
FLAG = -std=c++98

CLASSES_DIR = classes

SRCS = \
$(addsuffix .cpp, \
	tests \
	Account \
) \

all: $(NAME)

$(NAME):
	g++ -o $(NAME) $(FLAG) $(SRCS)

clean:
	rm -f $(NAME)

re: clean all
