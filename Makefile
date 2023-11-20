APP_NAME = 100_matches

CFLAGS = -Wall -Wextra -Werror -I src -MP -MMD
TESTFLAGS = -I thirdparty

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test

APP_PATH = $(BIN_DIR)/$(APP_NAME)
TEST_PATH = $(BIN_DIR)/test

SRC_EXT = c

APP_SOURCES = $(shell find $(SRC_DIR) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

DEPS = $(APP_OBJECTS:.o=.d) $(TEST_OBJECTS:.o=.d)

.PHONY: all
all: $(APP_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS)
	g++ $(CFLAGS) $^ -o $@ 

$(OBJ_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)
	g++ -c $(CFLAGS) $< -o $@


.PHONY: test
test: $(TEST_PATH)

$(TEST_PATH): obj/test/main.o obj/src/lib.o
	g++ $(CFLAGS) $(TESTFLAGS) $^ -o $@

obj/test/main.o: test/main.cpp
	g++ -c $(TESTFLAGS) $(CFLAGS) test/main.cpp -o obj/test/main.o

.PHONY: clean
clean:
	$(RM) $(APP_PATH) $(TEST_PATH)
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;
