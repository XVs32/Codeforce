# 4C Registration system
##Input
The first line contains number n (1 ≤ n ≤ 105). Follow with n lines, each line has a name. Which is not more than 32 characters, with all lowercase letters.

##Output
Printf n lines, Prompt a new name if the requested name is already taken, print "OK" if successful, 

##Example
| input |
| :--- |
| 6 |
| first |
| first |
| second |
| second |
| third |
| third |

<br />

| output |
| :--- |
| OK |
| first1 |
| OK |
| second1 |
| OK |
| third1 |

##Key point
Use a array to mark down every name that regist already. And another array to count the number of name.
