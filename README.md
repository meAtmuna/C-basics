# C Basics

This is my first time coding in C language but i like to learn new things.

## calculator

This is a simple calculator written in C.

### Features:
- Supports +, -, *, /
- Works with user input
- Works with command line arguments

### Example:

Interactive mode:
./calculator

Command line mode:
./calculator 4 * 100


# Word Counter (C)

A simple command line tool written in C that counts lines, words and finds the longest line in one more text files. It can also count how many times a specific word appears and measure execution time.

### Features:
- Count lines and words
- Find longest line length
- Support for multiple files
- Count occurrences of a specific word
- --help option for usage instructions
- Measure execution time

### How to use:

- Compilation
  gcc word_counter.c -o word_counter

- Usage (Show help)
  ./word_counter --help

- Single file
  ./word_counter file.txt

- Multiple files
  ./word_counter file1.txt file2.txt

- Count specific word (last argument is treated as the target word)
  ./word_counter file.txt hahaha

- Multiple files + word count
  ./word_counter file1.txt file2.txt hahaha

### Example Output:

- File: file.txt
- Lines: 10
- Words: 50
- Longest line: 80 characters
- 'hello' found: 3 times
- Time taken: 0.000123 seconds
