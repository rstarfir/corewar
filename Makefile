NAME = project

PROJECT_PART_PATHS = disaasm

$(NAME):
	@for i in $(PROJECT_PART_PATHS); do \
		make -C $$i; \
	done

all: $(NAME)

clean: 
	@for i in $(PROJECT_PART_PATHS); do \
		make clean -C $$i; \
	done

fclean: 
	@for i in $(PROJECT_PART_PATHS); do \
		make fclean -C $$i; \
	done

re: 
	@for i in $(PROJECT_PART_PATHS); do \
		make re -C $$i; \
	done