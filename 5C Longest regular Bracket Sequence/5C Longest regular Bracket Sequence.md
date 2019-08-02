# 5C Longest regular Bracket Sequence
##Input
Given a string of "(" and ")", find the longest regular bracket sequence. <br />
Note that "(())", "()()()()", "(())(())" are all regular, while ")(", "(()))", "(()" are not.
##Output
Two int a and b. while a is the length of the longest sequence, b is the number of such sequence.

##Example
| input |
| :-------|
| )((())))(()())    |

| output |
| :-------|
| 6 2  |

##Key point
Remember that "()()()" is count as 6, not 2.