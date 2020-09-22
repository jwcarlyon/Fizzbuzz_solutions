/*
Given two integer arrays A and B of size N.
There are N gas stations along a circular route, where the amount of gas at station i is A[i].

You have a car with an unlimited gas tank and it costs B[i] of gas to travel from station i
to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the minimum starting gas station’s index if you can travel around the circuit once, otherwise return -1.

You can only travel in one direction. i to i+1, i+2, … n-1, 0, 1, 2.. Completing the circuit means starting at i and
*/
public class gas_station
{
  public static void main(String[] args)
  {
    //int[] A = new int[]{1, 2, 3, 5};
    //int[] B = new int[]{2, 3, 4, 5};
    int[] A = new int[]{1, 2};
    int[] B = new int[]{2, 1};
    //I chose arrays for this because resizing is not necessary
    System.out.println(gas_station(A, B));
  }
  public static int gas_station(int[] A, int[] B)
  {
    for(int i = 0; i < A.length; i++)
    {
      int tank = 0;
      for(int ii = 0; ii < A.length; ii++)
      {
        int index = (i + ii) % A.length;
        //this is less expensive than using a linked list - save memory and runtime
        tank += A[index];
        if(tank >= B[index])
        {
          tank -= B[index];
        }else
        {
          //System.out.println("failed attempt at: " + i);
          tank = -1;
          break;
        }
      }
      if(tank >= 0){return i;}//this is after the above loop finds a viable path
    }
    return -1;
  }
}
