MAIN_TEST := main

SRC_FILE := flist.f

# Đọc danh sách file .cpp từ flist.f (nếu tồn tại), cộng thêm main.cpp
ifeq ($(wildcard $(SRC_FILE)),)
    SRCS := $(MAIN_TEST).cpp
else
    SRCS := $(shell cat $(SRC_FILE)) $(MAIN_TEST).cpp
endif

TARGET := $(MAIN_TEST)

CXX := g++
CXXFLAGS := -Wall -O2 -std=c++17

all: clean complite run

complite:
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

run:
	./$(TARGET) | tee complite.log

clean:
	rm -rf $(TARGET) complite.log
