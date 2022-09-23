#include <iostream>

struct cloud { bool thunderhead; cloud *single_jump; cloud *double_jump; };//a binary-form node
cloud *build_binary_graph(int* cloud_array, int i, int cloud_array_size);
int greedy_search(cloud *cloud_node);
int main()
{
  cloud *head;//simply a link to our graph
  int clouds[] = {0, 1, 0, 0, 1, 0, 1, 0 ,1, 0, 0, 1, 0};//return 7
  // int clouds[] = {0, 1, 0, 0, 0, 1, 0, 1, 0};//return 4
  int cloud_array_size = sizeof(clouds) / sizeof(clouds[0]);

  head = build_binary_graph(clouds, 0, cloud_array_size);//a graph of every possible path through clouds
  printf("Minimum # of jumps: %i\n", greedy_search(head));

  return 0;
}
int greedy_search(cloud *cloud_node)
{
  cloud *single_jump = cloud_node->single_jump;
  cloud *double_jump = cloud_node->double_jump;
  if((double_jump) && !double_jump->thunderhead){ return 1 + greedy_search(double_jump);}//the greedy choice is the longer jump
  if((single_jump) && !single_jump->thunderhead){ return 1 + greedy_search(single_jump);}
  return 0;//there is no dead end array possibility
}

cloud *build_binary_graph(int *cloud_array, int i, int cloud_array_size)
{
  //printf("debugging normal i: %i cloud_array_size: %i referenced: %i\n", i, cloud_array_size, cloud_array[i]);
  cloud *cloud_node = new cloud;

  cloud_node->thunderhead = cloud_array[i];

  if(cloud_array_size - 2 > i)
  {
    cloud_node->double_jump = build_binary_graph(cloud_array, i + 2, cloud_array_size);
    cloud_node->single_jump = build_binary_graph(cloud_array, i + 1, cloud_array_size);
  } else if(cloud_array_size - 1 > i) {
    cloud_node->single_jump = build_binary_graph(cloud_array, i + 1, cloud_array_size);
  }
  return cloud_node;//final node has nowhere to jump to
}
