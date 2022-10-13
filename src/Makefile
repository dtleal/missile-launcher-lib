NAME = libmlauncher.a
TARGET = ../bin/$(NAME)
INC = -I../include
INC += -I/usr/lib

LIBS = -lusb

OBJ = mlauncher.o 
SRC = mlauncher.c

$(OBJ): $(SRC)
	$(CC) -c $^ $(INC) -L $(LIBS)
	ar rcs $(TARGET) $@

clean:
	rm -f $(OBJ) $(TARGET)

purge: clean $(TARGET)
