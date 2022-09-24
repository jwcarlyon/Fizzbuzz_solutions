#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int sock_merchant(vector<int>& sock_pile_vector_reference);

int main()
{
    vector<int> sock_pile_vector0 = { 10, 28, 49, 10, 111, 101, 10, 28, 49, 101, 101 };//4 pairs
    vector<int> sock_pile_vector1 = { 1, 5, 8, 9, 9, 4, 8, 8, 1, 1, 1, 1, 1, 4 };//6 pairs
    cout << "Case 0, number of pairs: " << sock_merchant(sock_pile_vector0) << "\n";
    cout << "Case 1, number of pairs: " << sock_merchant(sock_pile_vector1) << "\n";
    return 0;
}

int sock_merchant(vector<int>& sock_pile_vector_reference)
{
    vector<int> sock_pile_vector = sock_pile_vector_reference;
    int pairs = 0;
    int count = 0;
    /*sort is implemented with a hybid of insertionsort and introsort
    the worst case runtime is O(n*log2(n)), where n is the vector length*/
    vector<int>::iterator last_observed_sock_pointer = sock_pile_vector.begin();
    vector<int>::iterator final_sock_pointer = sock_pile_vector.end();
    sort(last_observed_sock_pointer, final_sock_pointer);
    for(auto current_sock_pointer = last_observed_sock_pointer;
      current_sock_pointer < final_sock_pointer;
      current_sock_pointer++
    ) {
        if(*last_observed_sock_pointer == *current_sock_pointer)
        {
          count++;
          continue;
        }
        pairs += (count / 2);
        last_observed_sock_pointer = current_sock_pointer;
        count = 1;
    }
    pairs += (count / 2);//this is ok because integer division always rounds down
    return pairs;
}
