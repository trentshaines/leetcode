#!/usr/bin/env python3
import os
import sys

def create_problem(problem_num=None, name=None):
    """Interactive problem creation"""
    if problem_num is None or name is None:
        print("🚀 Creating new LeetCode problem...")
        # Get problem number
        while True:
            try:
                problem_num = input("Problem number: ")
                int(problem_num)  # Validate it's a number
                break
            except ValueError:
                print("Please enter a valid number")
        # Get problem name
        name = input("Problem name: ")
    # Format problem number
    num_str = f"{int(problem_num):03d}"
    base_filename = f"{num_str}_{name.lower().replace(' ', '_')}"
    
    # Find next available filename
    filename = base_filename
    suffix = 2
    while (os.path.exists(f"problems/cpp/{filename}.cpp") or 
           os.path.exists(f"problems/python/{filename}.py")):
        filename = f"{base_filename}_{suffix}"
        suffix += 1
    
    # Ensure directories exist
    os.makedirs("problems/cpp", exist_ok=True)
    os.makedirs("problems/python", exist_ok=True)
    # Create C++ file
    cpp_content = '''#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
};
'''
    # Create Python file
    python_content = '''class Solution:
    pass
'''
    # Write files
    with open(f"problems/cpp/{filename}.cpp", 'w') as f:
        f.write(cpp_content)
    with open(f"problems/python/{filename}.py", 'w') as f:
        f.write(python_content)
    print(f"✅ Created:")
    print(f"   problems/cpp/{filename}.cpp")
    print(f"   problems/python/{filename}.py")

if __name__ == "__main__":
    if len(sys.argv) == 3:
        create_problem(sys.argv[1], sys.argv[2])
    else:
        create_problem()
