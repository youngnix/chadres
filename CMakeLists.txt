cmake_minimum_required(VERSION 3.29.9)

project("Chadres"
	DESCRIPTION "Chadres"
	VERSION 0.1.0
	LANGUAGES C)

set(SRC main.c board.c util.h board.h pieces.h pieces.c)

add_executable(${PROJECT_NAME} ${SRC})
