###################################################################################
#
#
#
#
#
#
###################################################################################

include sources.mk

TARGET = test
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
DEPS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.d, $(SOURCES))
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
GFLAGS = -Wall -Werror -g -O0
CPPFLAGS = -E

CC = g++
SIZE = size
OBJDUMP = objdump
LD=ld
LDFLAGS = -Wl,-Map=$(OBJ_DIR)/$(TARGET).map

$(OBJ_DIR)/%.o : src/%.cpp
	$(CC) $(INCLUDES) -c $< $(GFLAGS) -o $@
$(OBJ_DIR)/%.i : src/%.cpp
	$(CC) $(INCLUDES) -c $(CPPFLAGS)  $< $(GFLAGS) -o $@
$(OBJ_DIR)/%.asm : src/%.cpp
	$(CC) $(INCLUDES) -S $< $(GFLAGS) -o $@
$(OBJ_DIR)/%.d : src/%.cpp
	$(CC) $(INCLUDES) -M $< $(GFLAGS) -o $@

.PHONY: all
build: all
.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(INCLUDES) $(OBJS) $(GFLAGS) $(LDFLAGS) -o $@.out

.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) $(INCLUDES) $(OBJS) -c $(GFLAGS) -o $(TARGET).out

.PHONY: build 
build: $(OBJS) $(DEPS) 
	$(CC) $(INCLUDES) $(OBJS) $(GFLAGS) $(LDFLAGS) -o $(TARGET).out
	$(SIZE) -Atd $(TARGET).out
	$(SIZE) $(TARGET).out
.PHONY: debug
debug: $(OBJS) $(DEPS)
	$(CC) $(INCLUDES) $(OBJS) -ggdb -o $(TARGET).out
	$(SIZE) -Atd $(TARGET).out
	$(SIZE) $(TARGET).out

.PHONY: clean
clean:
	rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/*.i $(OBJ_DIR)/*.map $(OBJ_DIR)/*.out $(OBJ_DIR)/*.asm $(OBJ_DIR)/*.d ./*.out
