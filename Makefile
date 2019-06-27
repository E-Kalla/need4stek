##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

#-------------#
#  Variables  #
#-------------#
sources	=	$(wildcard src/*.c)
obj	=	$(sources:.c=.o)
binary	=	ai

#----------------#
# Colors & Flags #
#----------------#
CFLAGS	=	-Iinclude -g3
red	=	\033[1;31m
blue	=	\033[1;34m
nocolor	=	\033[1;0m

#-----------------#
# Compile program #
#-----------------#
all:	$(obj)
	@printf "\n$(blue)[ Compiling Library & Sources ]\n\n$(nocolor)"
	gcc -o $(binary) $(obj)
	@printf "\n"

#----------#
# Cleaning #
#----------#
clean:
	@printf "\n$(red)[ Removing Objects ]\n\n$(nocolor)"
	rm -f $(obj)
	@printf "\n"

fclean:	clean
	@printf "\n$(red)[ Removing Binary ]\n\n$(nocolor)"
	rm -f  $(binary)
	@printf "\n"

re:	fclean	all

.PHONY: all clean fclean re