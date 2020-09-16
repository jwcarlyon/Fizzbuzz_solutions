/*Write a short program that prints each number from 1 to 100 on a new line.

For each multiple of 3, print "Fizz" instead of the number.

For each multiple of 5, print "Buzz" instead of the number.

For numbers which are multiples of both 3 and 5, print "FizzBuzz" instead of the number.*/

int main()
{
  int num = 1;
  while(num < 100)
  {
    char str[8];
    if(num % 3)
    {
      str[0] = 'F'; str[1] = 'i'; str[2] = 'z'; str[3] = 'z';
      if(num % 5)
      {
        str[4] = 'B'; str[5] = 'u'; str[6] = 'z'; str[7] = 'z';
      }
    }
    else if(num % 5)
    {
      str[0] = 'B'; str[1] = 'u'; str[2] = 'z'; str[3] = 'z';
    }
    if(str[0]):
    {
      printf(str);
    }
    else
    {
      printf(num);
    }
  }
  return 0;
}
