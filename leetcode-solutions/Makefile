# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2
PYTHON = python3

# Default target
all: help

# Help
help:
	@echo "Usage:"
	@echo "  make create                         - Create new problem (interactive)"
	@echo "  make compile PROBLEM=001_two_sum    - Compile C++ solution"
	@echo "  make run-cpp PROBLEM=001_two_sum    - Compile and run C++ solution"
	@echo "  make run-py PROBLEM=001_two_sum     - Run Python solution"
	@echo "  make clean                          - Clean compiled files"
	@echo "  make list                           - List all problems"

# Create new problem
create:
	@$(PYTHON) scripts/create_problem.py

# Compile C++ solution
compile:
	@if [ -f "problems/cpp/$(PROBLEM).cpp" ]; then \
		echo "🔨 Compiling C++ $(PROBLEM)..."; \
		$(CXX) $(CXXFLAGS) -o /tmp/$(PROBLEM)_cpp problems/cpp/$(PROBLEM).cpp && \
		echo "✅ Compiled successfully: /tmp/$(PROBLEM)_cpp"; \
	else \
		echo "❌ C++ file not found: problems/cpp/$(PROBLEM).cpp"; \
	fi

# Run C++ solution
run-cpp:
	@$(CXX) $(CXXFLAGS) -o /tmp/$(PROBLEM)_cpp problems/cpp/$(PROBLEM).cpp && /tmp/$(PROBLEM)_cpp

# Run Python solution
run-py:
	@$(PYTHON) problems/python/$(PROBLEM).py

# Clean compiled files
clean:
	@rm -f /tmp/*_cpp /tmp/*.exe

# List all problems
list:
	@echo "📁 Available problems:"
	@ls problems/cpp/*.cpp 2>/dev/null | sed 's/problems\/cpp\///g' | sed 's/\.cpp//g' | sort || echo "No problems found"
