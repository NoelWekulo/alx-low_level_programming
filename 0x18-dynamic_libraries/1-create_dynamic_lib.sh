#!/bin/bash

# Compile all .c files in the current directory into a dynamic library

# List all .c files in the current directory
c_files=$(ls *.c 2>/dev/null)

# Check if there are any .c files
if [ -z "$c_files" ]; then
    echo "No .c files found in the current directory."
    exit 1
fi

# Compile the dynamic library using Betty-style formatted .c files
gcc -Wall -Werror -Wextra -pedantic -fPIC -shared -o liball.so $c_files

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Dynamic library liball.so created successfully."
else
    echo "Compilation failed. Check for errors."
fi

