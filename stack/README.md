# Mathematical Expression Evaluator - ReadMe

## Overview
This C++ application evaluates mathematical expressions by converting infix notation to postfix notation and then evaluating the result. It supports basic arithmetic operations, functions like sin, cos, and log, as well as variables.

## Features
1. **Expression Parsing**:
   - Handles infix expressions with numbers, operators, functions, and variables.
   - Supports operators: +, -, *, /, ^ (exponentiation)
   - Supports functions: sin, cos, log
   - Supports constants like pi
   - Supports variables

2. **Infix to Postfix Conversion**:
   - Implements the Shunting Yard algorithm
   - Handles operator precedence correctly
   - Validates expressions for balanced parentheses and proper syntax

3. **Expression Evaluation**:
   - Evaluates postfix expressions using a stack-based approach
   - Handles numeric constants and functions
   - Detects errors in expression evaluation

## How to Run the Program
1. Ensure you have a C++ compiler that supports C++11 or later.
2. Compile the program using the command:
   ```bash
   g++ -o math_evaluator stack.cpp -std=c++11
   ```
3. Run the compiled program:
   ```bash
   ./math_evaluator
   ```

## Implementation Details
- The program is implemented as a class `math_symboles` that encapsulates all functionality.
- It uses the C++ standard library components like `stack`, `string`, and `unordered_set`.
- Mathematical functions and constants from `cmath` are utilized.

## Usage
When you run the program, you'll be prompted to enter a mathematical expression.
The program will:
1. Convert it to postfix notation
2. Display the postfix expression
3. If the expression doesn't contain variables, evaluate and display the result
