#include <string>
#include <stdio.h>
using namespace std;
long int repeated_string(string s, long int n);
int main(){
  string s = "adagAOdnasspesaosmfsguioaaanoadlkaaapn";
  //String s = "ada";
  long int n = 100000000;//length of potential substring
  //long n = (long)s.length();//length of potential substring
  printf("Number of occurrences: %ld\n", repeated_string(s, n));
}
long int repeated_string(string s, long int n)
{
  long int count = 0, remainder = 0;

  if(s.length() > n)
  {
    //char[] s_ = s.toCharArray();
    for(int i = 0; i < n; i++)//iterate through the CharArray and count 'a' occurrences. stop at n
    {
      if(s[i] == 'a'){count++;}
    }
    return count;
  }else{
    int last = (int)(n - ((long int)s.length() * (long int)(n / (long int)s.length())));//for determining any overlap
    //int last = ((int)n % s.length());//for determining any overlap
    for(int i = 0; i < s.length(); i++)//iterate though String and count as above
    {
      if(s[i] == 'a')
      {
        count ++;//we now have the count of 'a's in the string s
        if(i <  last){remainder ++;}//last is the length of the cutoff string - 0 if no cutoff
      }
    }
    count = count * (n / (long int)s.length()) + remainder;
    return count;
  }
}
