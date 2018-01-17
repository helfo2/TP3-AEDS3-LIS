# TP3-AEDS3-LIS

It's a simple application for determining, given a list of pairs representing a street, how could we maximize the connections in the street
considering that the numbers in each pair are connected with one another. This comes down to a famous computing problem, LIS (Longest Increasing Subsequence),
which is to define what's the maximum amount of elements in an ascendind subsequence in an array.

As this can be done using brute force, greedy or dinamic programming strategies, it's asked to solve the problem using all three of 
them, also comparing the results in terms of time complexity.

All code is written in C and it's organized with headers for function declarations and .c files for functions implementations. The actual problem is solved in the tp3.c file as well as there're some test cases in folders "entrada" and "saida", respectively the input and output correspondent correct data.
Documentation is presented in Doc.pdf file in Portuguese.

Project was compiled using gcc 5.4.0 version and memory tested with Valgrind 3.11.0
