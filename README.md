# Fizzbuzz_solutions
multi language solutions for toy problems
## fizzbuzz
Write a short program that prints each number from 1 to 100 on a new line.  
For each multiple of 3, print "Fizz" instead of the number.  
For each multiple of 5, print "Buzz" instead of the number.  
For numbers which are multiples of both 3 and 5, print "FizzBuzz" instead of the number.  
## gas_station
Given two integer arrays A and B of size N.  
There are N gas stations along a circular route, where the amount of gas at station i is A[i].  
You have a car with an unlimited gas tank and it costs B[i] of gas to travel from station i
to its next station (i+1).  
You begin the journey with an empty tank at one of the gas stations.  
Return the minimum starting gas station’s index if you can travel around the circuit once, otherwise return -1.  
You can only travel in one direction. i to i+1, i+2, … n-1, 0, 1, 2..  
Completing the circuit means starting at i and ending up at i again.  <br>
## sock_lord
This is a problem which supplies a list of integers and a single integer the
length of the list.  
The list is an unsorted collection of numbers, with some possible double values.  
The function sockMerchant(<strong>int</strong> n, <strong>dynamic array</strong> ar)
must return the number of matching pairs in ar.  <br>
## counting_valleys
An avid hiker keeps meticulous records of their hikes. During the last hike that took exactly steps, for every step it was noted if it was an uphill, , or a downhill, step. Hikes always start and end at sea level, and each step up or down represents a unit change in altitude.  
A valley is a sequence of consecutive steps below sea level, starting with a step down from sea level and ending with a step up to sea level. Given the sequence of up and down steps during a hike, find and print the number of valleys walked through.  
  The function count_valleys(<strong>int</strong> steps, <strong>string</strong> path) must return an integer value of times the hiker decended below then returned to sea-level.
## jumping_on_clouds
Emma is playing a new mobile game that starts with consecutively numbered clouds. Some of the clouds are thunderheads and others are cumulus. She can jump on any cumulus cloud having a number that is equal to the number of the current cloud plus <strong>1</strong> or <strong>2</strong>.  
She must avoid the thunderheads. Determine the minimum number of jumps it will take Emma to jump from her starting postion to the last cloud. It is always possible to win the game.  
__Output Format__  
Print the minimum number of jumps needed to win the game.  

__Sample Input 0__  
7<br>
0 0 1 0 0 1 0  

__Sample Output 0__   
4
## repeated_string
The repeatedString function should return an integer representing the number of occurrences of __a__ in the prefix of length __n__ in the infinitely repeating string.  
Print a single integer denoting the number of letter a's in the first __n__ letters of the infinite string created by repeating infinitely many times.  
Constraints: __1__ <= s.length <= __100__ and __1__ <= n <=__10<sup>12</sup>__
__Sample Input 0__  

(string __s__, long __n__)  
(string __'aba'__, long __10__)  
__Sample Output 0__  

__7__  <br>
##nearest_neighbor
Given 5 shoppers with the following baskets, please code up a nearest-neighbor function to calculate the euclidean distance between each of these shoppers. Which shoppers are more alike? By what percentage? Which shoppers are least alike? Please provide code.   __fred__ = ['Banana', 'Coffee', 'Coffee', 'Energy Drink']   __ralph__ = ['Cup Cakes', 'Cigarettes', 'Wine', 'Lighter']   __jeff__ = ['Coffee', 'Fountain Drink', 'Gum', 'Lighter', 'Propane']   __jake__ = ['Candy Bar', 'Energy Drink']   __brian__ = ['Coffee', 'Toy Robot']
