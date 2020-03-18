

CC = gcc -g
CINCLUDE  = -I$(MESA_PATH)/include 
CLIB      = -L$(MESA_PATH)/lib -lGL -lGLU -lglut  -lm


COMPILE    = $(CC) $(CFLAGS)  $(CINCLUDE)  -c  


.SUFFIXES:      .c .o  

.c.o:
	$(COMPILE) $<

SRC = main.c display.c 

all:  $(SRC:.c=.o) 
	$(CC)  $(SRC:.c=.o) $(CLIB) -o executable

clean: 
	rm -f *.o executable
