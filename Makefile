# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2
PYTHON = python3

# Default target
all: help

# Help
help:
	@echo "Usage:"
	@echo "  make create-cpp                     - Create new C++ problem file"
	@echo "  make create-py                      - Create new Python problem file"
	@echo "  make compile PROBLEM=001_two_sum FILE=1    - Compile C++ solution"
	@echo "  make run-cpp PROBLEM=001_two_sum FILE=1    - Compile and run C++ solution"
	@echo "  make run-py PROBLEM=001_two_sum FILE=1     - Run Python solution"
	@echo "  make clean                          - Clean compiled files"

# Create new problem (C++ only)
create-cpp:
	@$(PYTHON) scripts/create_problem.py --cpp-only

# Create new problem (Python only)
create-py:
	@$(PYTHON) scripts/create_problem.py --python-only

# Compile C++ solution
compile:
	@if [ -f "problems/$(PROBLEM)/$(FILE).cpp" ]; then \
		echo "🔨 Compiling C++ $(PROBLEM)/$(FILE).cpp..."; \
		$(CXX) $(CXXFLAGS) -o /tmp/$(PROBLEM)_$(FILE)_cpp problems/$(PROBLEM)/$(FILE).cpp && \
		echo "✅ Compiled successfully: /tmp/$(PROBLEM)_$(FILE)_cpp"; \
	else \
		echo "❌ C++ file not found: problems/$(PROBLEM)/$(FILE).cpp"; \
	fi

# Run C++ solution
run-cpp:
	@$(CXX) $(CXXFLAGS) -o /tmp/$(PROBLEM)_$(FILE)_cpp problems/$(PROBLEM)/$(FILE).cpp && /tmp/$(PROBLEM)_$(FILE)_cpp

# Run Python solution
run-py:
	@$(PYTHON) problems/$(PROBLEM)/$(FILE).py

# Clean compiled files
clean:
	@rm -f /tmp/*_cpp /tmp/*.exe
