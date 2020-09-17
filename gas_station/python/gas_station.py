'''
Given two integer arrays A and B of size N.
There are N gas stations along a circular route, where the amount of gas at station i is A[i].

You have a car with an unlimited gas tank and it costs B[i] of gas to travel from station i
to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the minimum starting gas station’s index if you can travel around the circuit once, otherwise return -1.

You can only travel in one direction. i to i+1, i+2, … n-1, 0, 1, 2.. Completing the circuit means starting at i and
ending up at i again.
'''
def begin_circuit(i, A, B):
    #begin at i
    tank = 0
    for x in range(len(A)):
        index = (i + x) % len(A)
        #a circular path requires the index to wrap around
        tank += A[index]
        if tank >= B[index]:
            tank -= B[index]
        else:
            #print("failed attempt at {}".format(i))
            return -1
    #the for loop ends at the last station
    return i

def gas_station(A, B):
    N = len(A)
    for i in range(N):
        if(begin_circuit(i, A, B) >= 0):
            return i
    return -1

if __name__ == "__main__":
    # execute only if run as a script
    #(A, B) = ([1, 2], [2, 1])
    (A, B) = ([1, 2, 3, 5], [2, 3, 4, 5])
    print(gas_station(A, B))
