#include <string>
#include <stdio.h>
using namespace std;
long int repeated_string(string substring, long int total_string_length);

int main(){
  // string s = "adagAOdnasspesaosmfsguioaaanoadlkaaapn";
  // long int n = 100000000;//length of string to be searched
  string substring = "ada";
  // long n = (long)s.length();//length of string to be searched
  long total_string_length = 10;//length of string to be searched
  printf("Number of occurrences: %ld\n", repeated_string(substring, total_string_length));
  return 0;
}

long int repeated_string(string substring, long int total_string_length)
{
  long int count = 0, remainder = 0;

  if(substring.length() > total_string_length)
  {
      for(int i = 0; i < total_string_length; i++)
      {
        if(substring[i] == 'a'){ count++; }
      }
      return count;
  } else {
      int last = (int)(total_string_length - ((long int)substring.length() * (long int)(total_string_length / (long int)substring.length())));//for determining any overlap
      for(int i = 0; i < substring.length(); i++)
      {
          if(substring[i] == 'a')
          {
              count ++;
              if(i <  last){ remainder ++; }
          }
      }
      count = count * (total_string_length / (long int)substring.length()) + remainder;
      return count;
  }
}
