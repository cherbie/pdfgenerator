TARGET_EXEC := program

SRC_DIR := ./src
BUILD_DIR := ./build
INC_FILES := $(shell find $(SRC_DIR) -name *.h)
SRC_FILES ?= $(shell find $(SRC_DIR) -name *.cc)

INC := $(INC_FILES:%=-L%)
OBJS ?= $(SRC_FILES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o) 

CXX := g++
INC_FLAGS := $(INC)
CFLAGS := --std=c++17 -MMD -MP $(INC_FLAGS)

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(CFLAGS)  -o $@ $^


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	mkdir -p $(dir $@)
	$(CXX) $(CFLAGS)  -c $< -o $@


.PHONY: clean
clean :
	rm -rf $(BUILD_DIR)
