SRCS_DIR	= ./
SRCS_FILES	= 	main.cpp\
				BitcoinExchange.cpp

SRCS		:= ${patsubst %, ${SRCS_DIR}%, ${SRCS_FILES}}

O_DIR		= ./objs/
D_DIR		= ./debugs/
HEADS		= -I./includes/ -I ./includes/iterators

OBJS_FILES	:= ${SRCS_FILES:.cpp=.o}
OBJS		:= ${patsubst %, ${O_DIR}%, ${OBJS_FILES}}
DEBUGS		:= ${patsubst %, ${D_DIR}%, ${OBJS_FILES}}

NAME		= btc

CXX			= g++
HXX			= BitcoinExchange.hpp

AR			= ar rcs
MKDIR		= mkdir
CP			= cp -f
RM			= rm -f

CXXFLAGS	= -std=c++98 -Wall -Wextra -Werror -g -Wfatal-errors


all:		${NAME}

${NAME}:	${O_DIR} ${OBJS} Makefile ${HXX}
			${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS} ${LIBS}

#Create objects directory
${O_DIR}:
			${MKDIR} ${O_DIR}

#Compile normals objects
${O_DIR}%.o:${SRCS_DIR}%.cpp #| ${HXX}
			${CXX} ${CXXFLAGS} ${HEADS} -o $@ -c $<

#Compile and use valgrind
valgrind:	${D_DIR} ${DEBUGS}
			${RM} ${NAME}
			${CXX} ${CXXFLAGS} -o ${NAME} ${DEBUGS} #${LIBS} -ggdb
			${VALGRIND} ./${NAME}


#Compile a debug executable with -g and fsanitize
debug:		${D_DIR} ${DEBUGS}
			${CXX} ${CXXFLAGS} -fsanitize=address -o ${NAME} ${DEBUGS} #${LIBS}

#Create debug directory
${D_DIR}:
			${MKDIR} ${D_DIR}

#Compile debug objects
${D_DIR}%.o:${SRCS_DIR}%.c
			${CXX} ${CXXFLAGS} -g ${HEADS} -o $@ -c $<


clean:
			${RM} ${OBJS} ${OBJSB} ${DEBUGS}
			@${RM} -r ${O_DIR}
			@${RM} -r ${D_DIR}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re debug
