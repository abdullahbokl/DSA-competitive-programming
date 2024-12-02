# C++ Helper Methods Index

A comprehensive collection of optimized C++ helper functions for competitive programming and general use.

## Table of Contents

1. [I/O Optimization](#io-optimization)
2. [Number Theory](#number-theory)
3. [Combinatorics](#combinatorics)
4. [Prime Numbers](#prime-numbers)
5. [String Operations](#string-operations)
6. [Search Algorithms](#search-algorithms)
7. [Sorting Algorithms](#sorting-algorithms)
8. [Graph Algorithms](#graph-algorithms)
9. [Bit Manipulation](#bit-manipulation)

## Function Index

### I/O Optimization
- [`optimizeIO()`](./helper_methods.cpp#L27-L30) - Optimizes input/output operations

### Number Theory
- [`gcd(a, b)`](./helper_methods.cpp#L37-L40) - Recursive Greatest Common Divisor
- [`gcdIterative(a, b)`](./helper_methods.cpp#L41-L49) - Iterative Greatest Common Divisor
- [`lcm(a, b)`](./helper_methods.cpp#L51-L54) - Recursive Least Common Multiple
- [`lcmIterative(a, b)`](./helper_methods.cpp#L55-L60) - Iterative Least Common Multiple
- [`fastPowerRecursive(a, b)`](./helper_methods.cpp#L62-L69) - Recursive fast power calculation
- [`fastPowerIterative(a, b)`](./helper_methods.cpp#L70-L80) - Iterative fast power calculation

#### Modular Arithmetic
- [`modAdd(a, b, m)`](./helper_methods.cpp#L81) - Modular addition
- [`modSub(a, b, m)`](./helper_methods.cpp#L82) - Modular subtraction
- [`modMul(a, b, m)`](./helper_methods.cpp#L83) - Modular multiplication
- [`modNegative(a, m)`](./helper_methods.cpp#L84-L88) - Modular negative
- [`modPow(base, exp, mod)`](./helper_methods.cpp#L89-L96) - Recursive modular exponentiation
- [`modPowIterative(base, exp, mod)`](./helper_methods.cpp#L97-L107) - Iterative modular exponentiation

### Combinatorics
- [`factorial(n)`](./helper_methods.cpp#L114-L118) - Recursive factorial calculation
- [`factorialIterative(n)`](./helper_methods.cpp#L119-L124) - Iterative factorial calculation
- [`fibonacci(n)`](./helper_methods.cpp#L126-L130) - Recursive Fibonacci number
- [`fibonacciIterative(n)`](./helper_methods.cpp#L131-L142) - Iterative Fibonacci number

### Prime Numbers
- [`isPrime(n)`](./helper_methods.cpp#L146-L154) - Check if number is prime
- [`primeFactors(n)`](./helper_methods.cpp#L155-L170) - Get prime factors of a number
- [`sieveOfEratosthenes(n)`](./helper_methods.cpp#L171-L189) - Generate prime numbers up to n

### String Operations
- [`isPalindrome(string)`](./helper_methods.cpp#L195-L202) - Check if string is palindrome
- [`isPalindrome(number)`](./helper_methods.cpp#L203-L206) - Check if number is palindrome
- [`findPalindromicSubstrings(s, start, size, result)`](./helper_methods.cpp#L207-L215) - Find all palindromic substrings

### Search Algorithms
Template-based implementations for different data types:
- [`linearSearch(arr, target)`](./helper_methods.cpp#L222-L229) - Linear search
- [`binarySearch(arr, target)`](./helper_methods.cpp#L231-L242) - Binary search
- [`ternarySearch(arr, target)`](./helper_methods.cpp#L244-L264) - Ternary search

### Sorting Algorithms
Template-based implementations for different data types:
- [`bubbleSort(arr)`](./helper_methods.cpp#L267-L278) - Bubble sort
- [`insertionSort(arr)`](./helper_methods.cpp#L280-L291) - Insertion sort
- [`mergeSort(arr, left, right)`](./helper_methods.cpp#L311-L319) - Merge sort
  - [`merge(arr, left, mid, right)`](./helper_methods.cpp#L293-L309) - Helper function for merge sort

### Graph Algorithms
- [`dfs(adj, visited, start)`](./helper_methods.cpp#L324-L332) - Depth-First Search
- [`bfs(adj, visited, start)`](./helper_methods.cpp#L334-L350) - Breadth-First Search
- [`dijkstra(adj, dist, start)`](./helper_methods.cpp#L352-L373) - Dijkstra's shortest path

### Bit Manipulation
- [`printBits(n)`](./helper_methods.cpp#L376-L381) - Print binary representation
- [`decimalToBinary(n)`](./helper_methods.cpp#L383-L390) - Convert decimal to binary string
- [`binaryToDecimal(s)`](./helper_methods.cpp#L392-L398) - Convert binary string to decimal
- [`isPowerOf2(n)`](./helper_methods.cpp#L400) - Check if number is power of 2
- [`isOdd(n)`](./helper_methods.cpp#L401) - Check if number is odd
- [`isEven(n)`](./helper_methods.cpp#L402) - Check if number is even
- [`getBit(n, i)`](./helper_methods.cpp#L403) - Get bit at position i
- [`setBit1(n, i)`](./helper_methods.cpp#L404) - Set bit to 1 at position i
- [`setBit0(n, i)`](./helper_methods.cpp#L405) - Set bit to 0 at position i
- [`toggleBit(n, i)`](./helper_methods.cpp#L406) - Toggle bit at position i

## Usage

1. Include the header file in your C++ program:
```cpp
#include "helper_methods.cpp"
```

2. Functions are organized in namespaces. Use them with namespace prefix:
```cpp
// Example usage
NumberTheory::gcd(12, 18);
StringOps::isPalindrome("radar");
BitOps::isPowerOf2(16);
```

## Notes
- All integer operations use `long long` for maximum range
- Template functions support different data types
- Functions are optimized for competitive programming use
- Most functions have both recursive and iterative implementations where applicable
