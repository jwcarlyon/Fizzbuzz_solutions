#include <iostream>
struct cloud{int value; cloud *one; cloud *two;};//a binary-form node
cloud *build_binary_graph(int* ptr, int i, int size);
int greedy_search(cloud *n);
int main()
{
  cloud *head;//declaration. no construction, simply a link to our list/graph
  int clouds[] = {0, 1, 0, 0, 1, 0, 1, 0 ,1, 0, 0, 1, 0};//return 7
  //int clouds[] = {0, 1, 0, 0, 0, 1, 0, 1, 0};//return 4
  int size = sizeof(clouds) / sizeof(clouds[0]);

  head = build_binary_graph(clouds, 0, size);//i think i can just use clouds instead of the & operator
  printf("Minimum # of jumps: %i\n", greedy_search(head));

  return 0;
}
int greedy_search(cloud *n)
{
  cloud *one = (n -> one);
  cloud *two = (n -> two);
  if((two) && ((two -> value) != 1)){return 1 + greedy_search(two);}//the greedy choice is the longer jump - 2
  else if((one) && !(one -> value)){return 1 + greedy_search(one);}
  else{return 0;}//there is no dead end array possibility
}

cloud *build_binary_graph(int *ptr, int i, int size)
{
  //printf("debugging normal i: %i size: %i referenced: %i\n", i, size, ptr[i]);
  int index = i;
  cloud *n = new cloud;

  n -> value = ptr[i];

  if(size - 2 > i)
  {
    (n -> two) = build_binary_graph(ptr, i + 2, size);
    (n -> one) = build_binary_graph(ptr, i + 1, size);
  }else if(size - 1 > i)
  {
    (n -> one) = build_binary_graph(ptr, i + 1, size);
  }
  return n;
}
