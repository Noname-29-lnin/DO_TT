MAIN_TEST := main
SRC_FILE := flist.f
BUILD_DIR := build
TARGET := $(MAIN_TEST)

CXX := g++
CXXFLAGS := -Wall -O2 -std=c++17
LDFLAGS := -pthread

VALUE_SERIAL 	?= 10
VALUE_PARALLEL 	?= 10

ifeq ($(wildcard $(SRC_FILE)),)
    SRC_LIST := $(MAIN_TEST).cpp
else
    SRC_LIST := $(shell cat $(SRC_FILE)) $(MAIN_TEST).cpp
endif

OBJ_LIST := $(addprefix $(BUILD_DIR)/, $(SRC_LIST:.cpp=.o))

all: clean $(TARGET) run

$(TARGET): $(OBJ_LIST)
	$(CXX) $(LDFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run:
	./$(TARGET) $(VALUE_SERIAL) | tee complite.log

clean:
	rm -rf $(BUILD_DIR) 
