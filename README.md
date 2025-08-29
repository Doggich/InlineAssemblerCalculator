# Inline Assembler Calculator
__*Inline Assembler Calculator*__ is a console-based integer calculator that supports basic math operations by using inline assembler in C++. The program reads mathematical expressions in infix notation, converts them to Reverse Polish Notation (RPN), and evaluates the result, using assembler code for the core arithmetic functions.

# Features
*  Supports operations: addition (+), subtraction (-), multiplication (*), division (/), and exponentiation (^)
*  Arithmetic operations are implemented with inline assembler
* Correct operator precedence and parentheses handling
* Converts infix expressions to RPN using the shunting yard algorithm
* Interactive mode: enter expressions and get instant results

# Usage
__run__
```bash
PracticeWork.exe
```

__Enter expressions__
Simply write an expression and press Enter, for example:
```bash
>> 2 + 3 * (4 - 1)
result: 11
>> 2 ^ 6
result: 64
```

# Project Structure
* `infixToRPN` — Converts regular expressions to RPN
* `evalRPN` — Evaluates the value of an RPN expression using a stack and arithmetic functions in assembler
* `_add`, `_sub`, `_mul`, `_div`, `_pow` — Arithmetic operations implemented in inline assembler
* `main` — Main interactive calculator loop

# Requirements
* Windows
* Visual Studio C++ (x86 build)
* MSVC compiler 

# Note
* Integer-only calculator; negative numbers and floating-point numbers are not supported.
* To exit, use Ctrl+C or close the terminal window.

__Feel free to ask for further customization or clarification!__


![image](https://media.tenor.com/-BjTGPdDJNAAAAAi/cpp-cplusplus.gif)
  
