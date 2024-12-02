# Data Structures and Algorithms Helper Methods

A comprehensive collection of optimized algorithms and data structure implementations for competitive programming and technical interviews.

## 👨‍💻 Authors

- **Names**
  - **Abdullah Khaled Elbokl**
- **LinkedIn**
  - [Abdullah ElBokl](https://www.linkedin.com/in/abdullahbokl/)

## 📝 Description

This repository serves as a one-stop solution for common algorithmic problems and data structure implementations in C++. It's designed to be:
- **Efficient**: Optimized implementations for competitive programming
- **Readable**: Clean code with clear naming conventions
- **Well-documented**: Detailed comments and usage examples
- **Easy to use**: Just copy and paste the methods you need

## 📁 File Structure

- [`helper_methods.cpp`](helper_methods.cpp) - Main file containing all helper methods and implementations

## 🛠️ Helper Methods Overview

### Number Theory Operations
- [`gcd(a, b)`](helper_methods.cpp#L38-L40) - Greatest Common Divisor (recursive)
- [`gcdIterative(a, b)`](helper_methods.cpp#L42-L49) - Greatest Common Divisor (iterative)
- [`lcm(a, b)`](helper_methods.cpp#L51-L54) - Least Common Multiple
- [`lcmIterative(a, b)`](helper_methods.cpp#L56-L60) - Least Common Multiple (iterative)
- [`fastPowerRecursive(a, b)`](helper_methods.cpp#L62-L70) - Fast Power (recursive)
- [`fastPowerIterative(a, b)`](helper_methods.cpp#L72-L80) - Fast Power (iterative)
- [`modAdd(a, b, m)`](helper_methods.cpp#L83) - Modular Addition
- [`modSub(a, b, m)`](helper_methods.cpp#L84) - Modular Subtraction
- [`modMul(a, b, m)`](helper_methods.cpp#L85) - Modular Multiplication
- [`modPow(base, exp, mod)`](helper_methods.cpp#L91-L98) - Modular Exponentiation

### Combinatorics
- [`factorial(n)`](helper_methods.cpp#L117-L120) - Factorial Calculation
- [`factorialIterative(n)`](helper_methods.cpp#L122-L126) - Factorial (iterative)
- [`fibonacci(n)`](helper_methods.cpp#L129-L133) - Fibonacci Number
- [`fibonacciIterative(n)`](helper_methods.cpp#L135-L145) - Fibonacci (iterative)

### Prime Numbers
- [`isPrime(n)`](helper_methods.cpp#L152-L160) - Prime Number Testing
- [`primeFactors(n)`](helper_methods.cpp#L162-L176) - Prime Factorization
- [`sieveOfEratosthenes(n)`](helper_methods.cpp#L178-L195) - Generate Prime Numbers

### String Operations
- [`isPalindrome(string)`](helper_methods.cpp#L202-L208) - Check String Palindrome
- [`isPalindrome(number)`](helper_methods.cpp#L210-L212) - Check Number Palindrome
- [`findPalindromicSubstrings()`](helper_methods.cpp#L214-L221) - Find Palindromic Substrings
- [`reverseString(s)`](helper_methods.cpp#L223-L226) - String Reversal
- [`toLower(s)`](helper_methods.cpp#L228-L231) - Convert to Lowercase
- [`toUpper(s)`](helper_methods.cpp#L233-L236) - Convert to Uppercase

### Tree Operations
- [`TreeNode`](helper_methods.cpp#L243-L247) - Tree Node Structure
- [`inorderTraversal(root)`](helper_methods.cpp#L249-L254) - Inorder Traversal
- [`preorderTraversal(root)`](helper_methods.cpp#L256-L261) - Preorder Traversal
- [`postorderTraversal(root)`](helper_methods.cpp#L263-L268) - Postorder Traversal
- [`treeHeight(root)`](helper_methods.cpp#L270-L273) - Tree Height
- [`isBalanced(root)`](helper_methods.cpp#L275-L284) - Check Balance
- [`isBST(root)`](helper_methods.cpp#L295-L297) - Validate BST

### Matrix Operations
- [`matrixMultiply(A, B)`](helper_methods.cpp#L304-L316) - Matrix Multiplication
- [`matrixPower(A, n)`](helper_methods.cpp#L318-L335) - Matrix Power
- [`rotateMatrix90Degrees()`](helper_methods.cpp#L337-L351) - Matrix Rotation
- [`transposeMatrix()`](helper_methods.cpp#L353-L363) - Matrix Transposition

### Search Algorithms
- [`linearSearch(arr, target)`](helper_methods.cpp#L370-L377) - Linear Search
- [`binarySearch(arr, target)`](helper_methods.cpp#L379-L390) - Binary Search
- [`ternarySearch(arr, target)`](helper_methods.cpp#L392-L411) - Ternary Search

### Sorting Algorithms
- [`bubbleSort(arr)`](helper_methods.cpp#L418-L428) - Bubble Sort
- [`insertionSort(arr)`](helper_methods.cpp#L430-L442) - Insertion Sort
- [`merge(arr, left, mid, right)`](helper_methods.cpp#L444-L461) - Merge Function
- [`mergeSort(arr, left, right)`](helper_methods.cpp#L463-L471) - Merge Sort

### Graph Algorithms
- [`dfs(adj, visited, start)`](helper_methods.cpp#L478-L485) - Depth First Search
- [`bfs(adj, visited, start)`](helper_methods.cpp#L487-L502) - Breadth First Search
- [`dijkstra(adj, dist, start)`](helper_methods.cpp#L504-L523) - Dijkstra's Algorithm
- [`hasCycle(adj)`](helper_methods.cpp#L525-L547) - Cycle Detection

### Bit Manipulation
- [`printBits(n)`](helper_methods.cpp#L588-L593) - Print Binary
- [`decimalToBinary(n)`](helper_methods.cpp#L595-L602) - Decimal to Binary
- [`binaryToDecimal(s)`](helper_methods.cpp#L604-L610) - Binary to Decimal
- [`isPowerOf2(n)`](helper_methods.cpp#L612) - Check Power of 2
- [`isOdd(n)`](helper_methods.cpp#L613) - Check Odd
- [`isEven(n)`](helper_methods.cpp#L614) - Check Even
- [`getBit(n, i)`](helper_methods.cpp#L615) - Get Bit
- [`setBit1(n, i)`](helper_methods.cpp#L616) - Set Bit to 1
- [`setBit0(n, i)`](helper_methods.cpp#L617) - Set Bit to 0
- [`toggleBit(n, i)`](helper_methods.cpp#L618) - Toggle Bit

## 💻 Usage

Include the helper methods in your project:
```cpp
#include <bits/stdc++.h>
using namespace std;

// Copy the required methods from helper_methods.cpp
```

## 🤝 Contributing

Feel free to contribute by:
1. Forking the repository
2. Creating a new branch
3. Making your changes
4. Opening a pull request

## 📝 License

This project is open source and available under the [MIT License](LICENSE).
