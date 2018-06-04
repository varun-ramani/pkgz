CC := clang++
OUT := build/out
OBJ := build/obj
MAIN_DEPS := ${OBJ}/pkgz.o ${OBJ}/package.o ${OBJ}/messages.o
CFLAGS := -Wall -std=c++14 -ggdb
LIBRARIES := -larchive


all: build

build: ${OUT}/pkgz

run: ${OUT}/pkgz
	./${OUT}/pkgz

clean:
	rm -rf ${OBJ}/*
	rm -rf ${OUT}/*

install:
	mv build/out/pkgz /usr/bin
uninstall:
	rm /usr/bin/pkgz

${OUT}/pkgz: ${MAIN_DEPS}
	${CC} $^ -o $@ ${CFLAGS} ${LIBRARIES}

${OBJ}/%.o: %.cc
	${CC} -c $< -o $@ ${CFLAGS}
