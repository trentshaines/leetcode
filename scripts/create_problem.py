#!/usr/bin/env python3
import os
import sys
import glob

def create_problem(problem_num=None, name=None, cpp_only=False, python_only=False):
    """Interactive problem creation"""
    if problem_num is None:
        print("🚀 Creating new LeetCode problem...")
        # Get problem number
        while True:
            try:
                problem_num = input("Problem number: ")
                int(problem_num)  # Validate it's a number
                break
            except ValueError:
                print("Please enter a valid number")
    
    # Format problem number
    num_str = f"{int(problem_num):03d}"
    
    # Check if problem folder already exists
    existing_folders = glob.glob(f"problems/{num_str}_*")
    
    if existing_folders and name is None:
        # Use existing folder name
        folder_name = os.path.basename(existing_folders[0])
        print(f"📁 Found existing problem: {folder_name}")
    else:
        # Need to get problem name
        if name is None:
            name = input("Problem name: ")
        folder_name = f"{num_str}_{name.lower().replace(' ', '_')}"
    
    # Create problem folder
    problem_dir = f"problems/{folder_name}"
    os.makedirs(problem_dir, exist_ok=True)
    
    created_files = []
    
    # Create C++ file (empty)
    if not python_only:
        # Find next available C++ iteration number
        cpp_iteration = 1
        while os.path.exists(f"{problem_dir}/{cpp_iteration}.cpp"):
            cpp_iteration += 1
        
        cpp_file = f"{problem_dir}/{cpp_iteration}.cpp"
        with open(cpp_file, 'w') as f:
            f.write("")
        created_files.append(cpp_file)
    
    # Create Python file (empty)
    if not cpp_only:
        # Find next available Python iteration number
        py_iteration = 1
        while os.path.exists(f"{problem_dir}/{py_iteration}.py"):
            py_iteration += 1
        
        py_file = f"{problem_dir}/{py_iteration}.py"
        with open(py_file, 'w') as f:
            f.write("")
        created_files.append(py_file)
    
    print(f"✅ Created:")
    for file in created_files:
        print(f"   {file}")

if __name__ == "__main__":
    cpp_only = "--cpp-only" in sys.argv
    python_only = "--python-only" in sys.argv
    
    # Remove flags from argv
    args = [arg for arg in sys.argv if not arg.startswith("--")]
    
    if len(args) == 3:
        create_problem(args[1], args[2], cpp_only, python_only)
    else:
        create_problem(cpp_only=cpp_only, python_only=python_only)
