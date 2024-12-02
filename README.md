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
10. [Tree Operations](#tree-operations)
11. [Matrix Operations](#matrix-operations)
12. [Permutation Operations](#permutation-operations)

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
- [`factorial(n)`](./helper_methods.cpp#L115-L119) - Recursive factorial calculation
- [`factorialIterative(n)`](./helper_methods.cpp#L121-L125) - Iterative factorial calculation
- [`fibonacci(n)`](./helper_methods.cpp#L127-L131) - Recursive Fibonacci number
- [`fibonacciIterative(n)`](./helper_methods.cpp#L133-L142) - Iterative Fibonacci number

### Prime Numbers
- [`isPrime(n)`](./helper_methods.cpp#L149-L157) - Check if number is prime
- [`primeFactors(n)`](./helper_methods.cpp#L159-L173) - Get prime factors of a number
- [`sieveOfEratosthenes(n)`](./helper_methods.cpp#L175-L192) - Generate prime numbers up to n

### String Operations
- [`isPalindrome(string)`](./helper_methods.cpp#L199-L205) - Check if string is palindrome
- [`isPalindrome(number)`](./helper_methods.cpp#L207-L209) - Check if number is palindrome
- [`findPalindromicSubstrings(s, start, size, result)`](./helper_methods.cpp#L211-L218) - Find all palindromic substrings
- [`reverseString(s)`](./helper_methods.cpp#L220-L223) - Reverse a string
- [`toLower(s)`](./helper_methods.cpp#L225-L228) - Convert string to lowercase
- [`toUpper(s)`](./helper_methods.cpp#L230-L233) - Convert string to uppercase

### Tree Operations
- [`TreeNode`](./helper_methods.cpp#L239-L243) - Tree node structure
- [`inorderTraversal(root)`](./helper_methods.cpp#L245-L250) - Inorder tree traversal
- [`preorderTraversal(root)`](./helper_methods.cpp#L252-L257) - Preorder tree traversal
- [`postorderTraversal(root)`](./helper_methods.cpp#L259-L264) - Postorder tree traversal
- [`treeHeight(root)`](./helper_methods.cpp#L266-L269) - Calculate height of tree
- [`isBalanced(root)`](./helper_methods.cpp#L271-L280) - Check if tree is height-balanced
- [`isBST(root)`](./helper_methods.cpp#L291-L293) - Check if tree is a binary search tree

### Matrix Operations
- [`matrixMultiply(A, B)`](./helper_methods.cpp#L300-L312) - Multiply two matrices
- [`matrixPower(A, n)`](./helper_methods.cpp#L314-L331) - Calculate matrix power
- [`rotateMatrix90Degrees(matrix)`](./helper_methods.cpp#L333-L347) - Rotate matrix 90 degrees clockwise
- [`transposeMatrix(matrix)`](./helper_methods.cpp#L349-L359) - Transpose a matrix

### Search Algorithms
Template-based implementations for different data types:
- [`linearSearch(arr, target)`](./helper_methods.cpp#L366-L373) - Linear search
- [`binarySearch(arr, target)`](./helper_methods.cpp#L375-L386) - Binary search
- [`ternarySearch(arr, target)`](./helper_methods.cpp#L388-L407) - Ternary search

### Sorting Algorithms
Template-based implementations for different data types:
- [`bubbleSort(arr)`](./helper_methods.cpp#L414-L424) - Bubble sort
- [`insertionSort(arr)`](./helper_methods.cpp#L426-L438) - Insertion sort
- [`mergeSort(arr, left, right)`](./helper_methods.cpp#L459-L467) - Merge sort
  - [`merge(arr, left, mid, right)`](./helper_methods.cpp#L440-L457) - Helper function for merge sort

### Graph Algorithms
- [`dfs(adj, visited, start)`](./helper_methods.cpp#L474-L481) - Depth-First Search
- [`bfs(adj, visited, start)`](./helper_methods.cpp#L483-L498) - Breadth-First Search
- [`dijkstra(adj, dist, start)`](./helper_methods.cpp#L500-L519) - Dijkstra's shortest path
- [`hasCycle(adj)`](./helper_methods.cpp#L521-L543) - Check if directed graph has a cycle

### Permutation Operations
- [`isPermutation(arr)`](./helper_methods.cpp#L547-L558) - Check if array is a valid permutation
- [`nextPermutation(arr)`](./helper_methods.cpp#L560-L577) - Get next lexicographically greater permutation

### Bit Manipulation
- [`printBits(n)`](./helper_methods.cpp#L584-L589) - Print binary representation
- [`decimalToBinary(n)`](./helper_methods.cpp#L591-L598) - Convert decimal to binary string
- [`binaryToDecimal(s)`](./helper_methods.cpp#L600-L606) - Convert binary string to decimal
- [`isPowerOf2(n)`](./helper_methods.cpp#L608) - Check if number is power of 2
- [`isOdd(n)`](./helper_methods.cpp#L609) - Check if number is odd
- [`isEven(n)`](./helper_methods.cpp#L610) - Check if number is even
- [`getBit(n, i)`](./helper_methods.cpp#L611) - Get bit at position i
- [`setBit1(n, i)`](./helper_methods.cpp#L612) - Set bit to 1 at position i
- [`setBit0(n, i)`](./helper_methods.cpp#L613) - Set bit to 0 at position i
- [`toggleBit(n, i)`](./helper_methods.cpp#L614) - Toggle bit at position i

## Usage

1. Include the header file in your C++ program:
```cpp
#include "helper_methods.cpp"
```

2. Call any function from the appropriate namespace:
```cpp
// Example usage
NumberTheory::gcd(12, 18);
StringOps::isPalindrome("racecar");
Search::binarySearch(arr, target);
```
