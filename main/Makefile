# Masukkan semua file cpp Anda
OBJS = main.cpp oop.cpp ../src/Animal/Fish.cpp ../src/Animal/Guppy.cpp 

CC = g++
COMPILER_FLAGS = -std=c++11 -Wall -O2
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
OBJ_NAME = ArkavQuarium
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
