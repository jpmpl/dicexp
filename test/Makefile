CXX = /usr/bin/g++
CXX_FLAGS = -std=c++11

INCLUDE_DIRS += -I../dependencies/json_nlohmann/include/ -I../src/ -I../dependencies/gtest/include/ -I../dependencies/gtest/lib/
INCLUDE_LIBS += -lgtest

MODULE_BIN1 = rollertest

SRCS += ../src/die.cpp ../src/roller.cpp ../src/cassinoAdm.cpp
SRC1 = rollerTest.cpp

default: clean
	mkdir bin
	$(CXX) -o $(MODULE_BIN1) $(CXX_FLAGS) $(INCLUDE_DIRS) $(INCLUDE_LIBS) $(SRC1) $(SRCS)
	mv $(MODULE_BIN1) bin/
clean:
	rm -rf bin