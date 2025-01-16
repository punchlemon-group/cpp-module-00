.PHONY: all clean fclean re

NAME = megaphone

OUT_DIR = out

SRCS = \
$(addsuffix .cpp, \
	main \
)\

OBJS = $(addprefix $(OUT_DIR)/, $(SRCS:.cpp=.o))
DEPS = $(addprefix $(OUT_DIR)/, $(SRCS:.cpp=.o))

CFLAGS = -Wall -Wextra -Werror
CXXFLAGS = -std=c++98
IFLAGS =
LFLAGS =
MFLAGS = -MMD -MP

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $@ $(CFLAGS) $(IFLAGS) $(LFLAGS) $(CXXFLAGS) $^

$(OUT_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) -o $@ $(CFLAGS) $(IFLAGS) $(CXXFLAGS) $(MFLAGS) -c $<

clean:
	@rm -rf $(OUT_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
