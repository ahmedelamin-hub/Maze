CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -Iinc
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/globals.c $(SRC_DIR)/input.c $(SRC_DIR)/player.c $(SRC_DIR)/raycasting.c $(SRC_DIR)/map.c $(SRC_DIR)/textures.c $(SRC_DIR)/render.c
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
EXEC = maze_game

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lSDL2 -lSDL2_image -lm

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(EXEC)
