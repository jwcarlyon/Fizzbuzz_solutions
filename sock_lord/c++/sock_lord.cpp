#include <c++/7.5.0/bits/stdc++.h>

using namespace std;
int sockMerchant(int n, vector<int> ar);

// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar) {
    //find the pairs in the list
    int pairs = 0;
    int count = 0;
    sort(ar.begin(), ar.end());
    vector<int>::iterator last = ar.begin();//-1;
    for(auto i = ar.begin(); i < ar.end(); ++i)
    {
        if(*last == *i){count++;}
        else
        {
            pairs += (count % 2) + (count / 2);
            last = i;
            count = 0;
        }
    }
    return pairs;
}
