# Fizzbuzz_solutions
multi language solutions for toy problems
## gas_station
Given two integer arrays A and B of size N.
There are N gas stations along a circular route, where the amount of gas at station i is A[i].<br>
You have a car with an unlimited gas tank and it costs B[i] of gas to travel from station i
to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.<br>
Return the minimum starting gas station’s index if you can travel around the circuit once, otherwise return -1.<br>
You can only travel in one direction. i to i+1, i+2, … n-1, 0, 1, 2.. <br>
Completing the circuit means starting at i and ending up at i again.<br><br>
## sock_lord
This is a problem which supplies a list of integers and a single integer the
length of the list.
The list is an unsorted collection of numbers, with some possible double values.<br>
The function sockMerchant(<strong>int</strong> n, <strong>dynamic array</strong> ar)
must return the number of matching pairs in ar.<br><br>
## counting_valleys
An avid hiker keeps meticulous records of their hikes. During the last hike that took exactly steps, for every step it was noted if it was an uphill, , or a downhill, step. Hikes always start and end at sea level, and each step up or down represents a unit change in altitude.<br>
A valley is a sequence of consecutive steps below sea level, starting with a step down from sea level and ending with a step up to sea level. Given the sequence of up and down steps during a hike, find and print the number of valleys walked through.<Br>
  The function count_valleys(<strong>int</strong> steps, <strong>string</strong> path) must return an integer value of times the hiker decended below then returned to sea-level.
## jumping_on_clouds
Emma is playing a new mobile game that starts with consecutively numbered clouds. Some of the clouds are thunderheads and others are cumulus. She can jump on any cumulus cloud having a number that is equal to the number of the current cloud plus <strong>1</strong> or <strong>2</strong>.<br>
She must avoid the thunderheads. Determine the minimum number of jumps it will take Emma to jump from her starting postion to the last cloud. It is always possible to win the game.<br>
__Output Format__<br>

Print the minimum number of jumps needed to win the game.<br>

__Sample Input 0__<br>

7<br>
0 0 1 0 0 1 0<br>

<br>Sample Output 0__<br>

4<br>
