#include <iostream>
#include <string>
using namespace std;
int countingValleys(int steps, string path);
int main()
{
  string case0 = "UUDUDDDDUUUDDDDUUU";
  cout << "Number of valleys traversed: " << countingValleys(case0.length(), case0) << "\n";
  return 0;
}

int countingValleys(int steps, string path)
{
  bool above = true;
  int pos = 0;
  int valleys = 0;
  for(int i = 0; i < steps; i++)
  {
    if(path[i] == 'U'){pos++;}
    if(path[i] == 'D'){pos--;}
    if((pos < 0) && above){above = false;}
    else if((pos >= 0) && !above){above = true; valleys++;}
  }
  return valleys;
}
