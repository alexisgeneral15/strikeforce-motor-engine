CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := bin/strike_engine.exe

CFLAGS := -std=c++17 -Wall -Wextra -O3 -I$(SRCDIR) -I/mingw64/include
LDLIBS := -lglfw3 -lSDL2 -lBulletDynamics -lBulletCollision -lLinearMath -lfmod

SOURCES := $(shell find $(SRCDIR) -name '*.cpp')
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.cpp=.o))

$(TARGET): $(OBJECTS)
	@mkdir -p bin
	$(CC) $^ -o $@ $(LDLIBS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR) bin

.PHONY: clean