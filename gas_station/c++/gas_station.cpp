#include <iostream>
using namespace std;

int gas_station(int* A, int* B, int n);
bool begin_circuit(int* A, int* B, int n, int i);
int main()
{
  int A[4] = {5, 1, 2, 3};
  int B[4] = {0, 3, 0, 8};
  //int A[2] = {1, 2};
  //int B[2] = {2, 1};
  int size = sizeof(A) / sizeof(A[0]);
  //I chose arrays for this because resizing is not necessary
  cout << "Begin at station: " << gas_station(A, B, size) << "\n";
}
bool begin_circuit(int* A, int* B, int n, int i)
{
  int tank = 0;
  for(int j = 0; j < n; j++)
  {
    int index = (j + i) % n;
    tank += B[index];
    if(A[index] > tank){return false;}
    else{tank -=  A[index];}
  }
  return true;
}
int gas_station(int* A, int* B, int n)
{
  for(int i = 0; i < n; i++)
  {
    if(begin_circuit(A, B, n, i)){return i;}
  }
  return -1;
}
