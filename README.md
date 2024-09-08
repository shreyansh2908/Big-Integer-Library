# Big-Integer-Library

 Problem Statement: Create a big integer library, similar to the one
 available in Java. The library should provide functionalities to store
 arbitrarily large integers and perform basic math operations.
 Operations:
 1. Addition(+), subtraction(-), multiplication(x, lowercase “X”), division(/)
 E.g.
 Input: 32789123+99893271223x9203232392-4874223
 Output: 919340989462382970316
 Input: 3423542525+6773442x5345345-213213197786/45647
 Output: 36209803199102
 2. Exponentiation- Base will be a big int and exponent will be < 263
 3. GCDoftwonumbers
 4. Factorial
 Constraints: For all operations the number of digits in input,output and
 intermediate results won’t exceed 3000 digits.
 Expected Time Complexity:Let s1 and s2 be two big integers with n and m
 number of digits in them.Let x be an integer < 263
 1) Addition(s1+s2) : O(n+m)
 2) Subtraction(s1-s2) : O(n+m)
 3) Multiplication(s1*s2) : O(n*m)
 4) Division(s1/s2) : O(n*m)
 5) Exponentiation(s1^x) : O(n*n*log(x))
 6) GCD(s1,s2) : O(max(n,m))
 7) Factorial(s1) : O( n3)
Input Format: First line will contain an integer value which denotes the type of
 operation. The integer value and operation mapping is as follows:
 1. Addition, Subtraction, Multiplication & Division
 2. Exponentiation
 3. GCD
 4. Factorial
 The following line will contain input according to the type of operation. For
 1st and 4th type of operation, there will be one string and for the 2nd & 3rd type of
 operation, there will be 2 space separated Strings.
 Evaluation Parameters: Accuracy of operations and performance
 Sample Cases:
 ● Sample input:
 1
 1+2x6+13/5-2
 Sample output:
 13
 ● Sample input:
 2
 2 10
 Sample output:
 1024
 ● Sample input:
 3
 9 15
 Sample output: 3
 ● Sample input:
 4
 12
 Sample output: 479001600
Note :
 1. Negative numbers won’t be present in the intermediate or final output (i.e.
 No need to consider cases like 2-3).
 2. There are NO brackets in the input.
 3. Perform Integer division operation between two big integers, disregarding
 the remainder.
 4. Addition, Subtraction, Multiplication and Division follows the same
 precedence and associativity rules as in Java/cpp.
 5. Ignore Division by zero, gcd(0, x), gcd(x, 0).
 6. C++STLis not allowed (including vectors & stack, design your own if
 required).
 7. You are not allowed to use the regex library.
 8. string, to_string and string manipulation methods are allowed.
 9. Design your main function according to sample input/output given
