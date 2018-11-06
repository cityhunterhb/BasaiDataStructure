#makefile
TARGET = main

CC = gcc
# SRC = $(wildcard ./*.c)
ALLSRC += $(wildcard ./*.c) #当前目录下所有.c文件
ALLSRC += $(wildcard ./*/*.c)
# SRC += $(filter-out $(wildcard ./*.o), $(ALLSRC)) #去掉所有.o文件
# SRC += $(fileter-out $(wildcard ./*/*.o), $(ALLSRC))
# OBJS = main.o print.o
OBJS = $(patsubst %.c, %.o, $(ALLSRC)) #将SRC目录下的所有.c文件替换成.o

# CFLAGS = -I include
# CFLAGS = -I %.h

# VPATH = src:lib

#vpath %.h lib
#vpath %.c src

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS)


# %.o : %.c
# 	$(CC) $(CFLAGS) -c $<


.PHONY : clean
clean:
	-rm -f $(TARGET) $(OBJS)

