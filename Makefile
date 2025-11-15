# Compiler
CXX = g++
CXXFLAGS = -std=gnu++17 -O2 -Wall -Wextra -Iinclude
# Source files (all cpp files)
SRC = $(wildcard src/*.cpp src/systems/*.cpp)
OBJ = $(SRC:.cpp=.o)

# Output binary name
TARGET = PhysSim

# -------------------------------------------------
.PHONY: all clean run-projectile run-pendulum run-oscillator

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Helper: make sure the output folder exists
data:
	@mkdir -p data

clean:
	rm -rf $(OBJ) $(TARGET) data/*.csv data/__pycache__

# Python utilities
PYTHON = python
MODULE_NAME = data_visualization

run-projectile: data $(TARGET)
	./$(TARGET) projectile $(if $(INT),--integrator=$(INT),)
	$(PYTHON) -c "import sys; sys.path.insert(0, 'data'); from $(MODULE_NAME) import plot_projectile; plot_projectile()"

run-pendulum: data $(TARGET)
	./$(TARGET) pendulum $(if $(INT),--integrator=$(INT),)
	$(PYTHON) -c "import sys; sys.path.insert(0, 'data'); from $(MODULE_NAME) import plot_pendulum; plot_pendulum()"

run-oscillator: data $(TARGET)
	./$(TARGET) oscillator $(if $(INT),--integrator=$(INT),)
	$(PYTHON) -c "import sys; sys.path.insert(0, 'data'); from $(MODULE_NAME) import plot_oscillator; plot_oscillator()"