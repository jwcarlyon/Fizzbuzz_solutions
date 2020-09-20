//#include <c++/7.5.0/bits/stdc++.h>
#include <c++/7.5.0/vector>
#include <c++/7.5.0/iostream>
#include <c++/7.5.0/algorithm>

using namespace std;
int sockMerchant(int n, vector<int> ar);
// Complete the sockMerchant function below.
int main()
{
  int sequence[] = {10, 28, 49, 10, 111, 101, 10, 28, 49, 101, 101};
  //int sequence[] = {1, 5, 8, 9, 9, 4, 8, 8, 1, 1, 1, 1, 1, 4};
  vector<int> ar(sequence, (sequence + sizeof(sequence) / sizeof(int)));
  cout << "number of pairs: " << sockMerchant(ar.size(), ar) << "\n";
  return 0;
}

int sockMerchant(int n, vector<int> ar)
{
    //find the pairs in the list
    int pairs = 0;
    int count = 0;
    sort(ar.begin(), ar.end());
    vector<int>::iterator last = ar.begin();//-1;
    for(auto i = ar.begin(); i < ar.end(); ++i)
    {
        if(*last == *i)
        {
          count++;
          //cout << "found match, last: " << *last << " iterator value: " << *i << "count: " << count << "\n";
        }
        else
        {
            pairs += (count / 2);
            //pairs += (count % 2) + (count / 2);
            //cout << "no match, last: " << *last << " iterator value: " << *i << " pairs: " << pairs << "\n";
            last = i;
            count = 1;
        }
    }
    pairs += (count / 2);
    return pairs;
}
