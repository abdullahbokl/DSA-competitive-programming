# Data Structures and Algorithms Helper Methods

A comprehensive collection of optimized algorithms and data structure implementations for competitive programming and technical interviews.

## 👨‍💻 Authors

- **Abdullah Khaled ElBokl**
  - LinkedIn: [Abdullah ElBokl](https://www.linkedin.com/in/abdullahbokl/)

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
- [`gcd(a, b)`](helper_methods.cpp#L37) - Greatest Common Divisor (recursive)
- [`gcdIterative(a, b)`](helper_methods.cpp#L42) - Greatest Common Divisor (iterative)
- [`lcm(a, b)`](helper_methods.cpp#L51) - Least Common Multiple
- [`lcmIterative(a, b)`](helper_methods.cpp#L56) - Least Common Multiple (iterative)
- [`fastPowerRecursive(a, b)`](helper_methods.cpp#L62) - Fast Power (recursive)
- [`fastPowerIterative(a, b)`](helper_methods.cpp#L72) - Fast Power (iterative)
- [`modAdd(a, b, m)`](helper_methods.cpp#L82) - Modular Addition
- [`modSub(a, b, m)`](helper_methods.cpp#L83) - Modular Subtraction
- [`modMul(a, b, m)`](helper_methods.cpp#L84) - Modular Multiplication
- [`modPow(base, exp, mod)`](helper_methods.cpp#L92) - Modular Exponentiation

### Combinatorics
- [`factorial(n)`](helper_methods.cpp#L116) - Factorial Calculation
- [`factorialIterative(n)`](helper_methods.cpp#L122) - Factorial (iterative)
- [`fibonacci(n)`](helper_methods.cpp#L128) - Fibonacci Number
- [`fibonacciIterative(n)`](helper_methods.cpp#L135) - Fibonacci (iterative)

### Prime Numbers
- [`isPrime(n)`](helper_methods.cpp#L152) - Prime Number Testing
- [`primeFactors(n)`](helper_methods.cpp#L162) - Prime Factorization
- [`sieveOfEratosthenes(n)`](helper_methods.cpp#L178) - Generate Prime Numbers

### String Operations
- [`isPalindrome(string)`](helper_methods.cpp#L202) - Check String Palindrome
- [`isPalindrome(number)`](helper_methods.cpp#L210) - Check Number Palindrome
- [`findPalindromicSubstrings()`](helper_methods.cpp#L214) - Find Palindromic Substrings
- [`reverseString(s)`](helper_methods.cpp#L223) - String Reversal
- [`toLower(s)`](helper_methods.cpp#L228) - Convert to Lowercase
- [`toUpper(s)`](helper_methods.cpp#L233) - Convert to Uppercase

### Tree Operations
- [`TreeNode`](helper_methods.cpp#L243) - Tree Node Structure
- [`inorderTraversal(root)`](helper_methods.cpp#L249) - Inorder Traversal
- [`preorderTraversal(root)`](helper_methods.cpp#L256) - Preorder Traversal
- [`postorderTraversal(root)`](helper_methods.cpp#L263) - Postorder Traversal
- [`treeHeight(root)`](helper_methods.cpp#L270) - Tree Height
- [`isBalanced(root)`](helper_methods.cpp#L275) - Check Balance
- [`isBST(root)`](helper_methods.cpp#L295) - Validate BST

### Matrix Operations
- [`matrixMultiply(A, B)`](helper_methods.cpp#L304) - Matrix Multiplication
- [`matrixPower(A, n)`](helper_methods.cpp#L318) - Matrix Power
- [`rotateMatrix90Degrees()`](helper_methods.cpp#L337) - Matrix Rotation
- [`transposeMatrix()`](helper_methods.cpp#L353) - Matrix Transposition

### Search Algorithms
- [`linearSearch(arr, target)`](helper_methods.cpp#L370) - Linear Search
- [`binarySearch(arr, target)`](helper_methods.cpp#L379) - Binary Search
- [`ternarySearch(arr, target)`](helper_methods.cpp#L392) - Ternary Search

### Sorting Algorithms
- [`bubbleSort(arr)`](helper_methods.cpp#L418) - Bubble Sort
- [`insertionSort(arr)`](helper_methods.cpp#L430) - Insertion Sort
- [`merge(arr, left, mid, right)`](helper_methods.cpp#L444) - Merge Function
- [`mergeSort(arr, left, right)`](helper_methods.cpp#L463) - Merge Sort

### Graph Algorithms
- [`dfs(adj, visited, start)`](helper_methods.cpp#L478) - Depth First Search
- [`bfs(adj, visited, start)`](helper_methods.cpp#L487) - Breadth First Search
- [`dijkstra(adj, dist, start)`](helper_methods.cpp#L504) - Dijkstra's Algorithm
- [`hasCycle(adj)`](helper_methods.cpp#L525) - Cycle Detection

### Bit Manipulation
- [`printBits(n)`](helper_methods.cpp#L588) - Print Binary
- [`decimalToBinary(n)`](helper_methods.cpp#L595) - Decimal to Binary
- [`binaryToDecimal(s)`](helper_methods.cpp#L604) - Binary to Decimal
- [`isPowerOf2(n)`](helper_methods.cpp#L612) - Check Power of 2
- [`isOdd(n)`](helper_methods.cpp#L613) - Check Odd
- [`isEven(n)`](helper_methods.cpp#L614) - Check Even
- [`getBit(n, i)`](helper_methods.cpp#L615) - Get Bit Value
- [`setBit1(n, i)`](helper_methods.cpp#L616) - Set Bit to 1
- [`setBit0(n, i)`](helper_methods.cpp#L617) - Set Bit to 0
- [`toggleBit(n, i)`](helper_methods.cpp#L618) - Toggle Bit

## 💻 Usage

### 1. Include the Required Headers
```cpp
#include <bits/stdc++.h>
using namespace std;
```

### 2. Direct Usage with Namespaces
You can use any function directly with its namespace:

```cpp
// Number Theory examples
cout << NumberTheory::gcd(12, 18) << endl;  // 6
cout << NumberTheory::lcm(12, 18) << endl;  // 36

// Bit manipulation examples
cout << BitOps::isPowerOf2(16) << endl;     // true
cout << BitOps::isOdd(15) << endl;          // true

// String operations
string s = "Hello";
cout << StringOps::isPalindrome(s) << endl;  // false
s = StringOps::reverseString(s);             // "olleH"

// Prime number operations
cout << Primes::isPrime(17) << endl;         // true
vector<ll> factors = Primes::primeFactors(12);  // [2, 2, 3]
```

### 3. Using Multiple Namespaces
Each category of functions is in its own namespace for organization:
```cpp
// Using multiple namespaces
ll n = 5;
cout << Combinatorics::factorial(n) << endl;     // 120
cout << BitOps::decimalToBinary(n) << endl;      // "101"
cout << NumberTheory::isPowerOf2(n) << endl;     // false
```

### 4. Available Namespaces
- `NumberTheory::` - GCD, LCM, modular arithmetic
- `Combinatorics::` - Factorial, Fibonacci
- `Primes::` - Prime testing, factorization
- `StringOps::` - String manipulation
- `Tree::` - Binary tree operations
- `Matrix::` - Matrix operations
- `Search::` - Search algorithms
- `Sort::` - Sorting algorithms
- `Graph::` - Graph algorithms
- `BitOps::` - Bit manipulation

### 5. Type Definitions
The library uses these type definitions:
```cpp
typedef long long ll;
typedef unsigned long long ull;
```

### 6. Error Handling
Functions include basic error checking, but add your own as needed:
```cpp
// Example with error checking
ll factorial(ll n) {
    if (n < 0) throw invalid_argument("Factorial not defined for negative numbers");
    if (n > 20) throw overflow_error("Result will overflow long long");
    return Combinatorics::factorial(n);
}
```

### 7. Performance Tips
- Use iterative versions for better performance with large inputs
- Choose appropriate data structures (vector vs array)
- Consider time/space tradeoffs for your use case

## 🤝 Contributing

Feel free to contribute by:
1. Forking the repository
2. Creating a new branch
3. Making your changes
4. Opening a pull request

## 📝 License

This project is open source and available under the [MIT License](LICENSE).
