There are three popular pattern matching algorithm in strings that uses liner time to match pattern 

1. Z - function 
2. Rabin Karp Algorithm - uses hash code for pattern matching 
3. KMP Algorithm 


Difference between all these three algorithm 

1. Z - function 

for each z[i] it will tell you tell you that from the prefix how may elements or chars are matched from i index

Example: 

a b c e a b d 
0 0 0 0 2 0 0 

2. Rabin Karp Algoritm 

It is major focused on weather a pattern in inside the text or not and it will return the idx of the specific position where it is.

3. KMP Algorithm 

It is more sequential. It focuses on sequence. Like prefix starts from j and goes till some j + k. so kmp[j] = 1 and so on it will increase, where the length of the string is k. 

Example: 

a b d e f a b c f 
0 0 0 0 0 1 2 0 0 