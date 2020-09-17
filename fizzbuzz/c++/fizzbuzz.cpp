/*Write a short program that prints each number from 1 to 100 on a new line.

For each multiple of 3, print "Fizz" instead of the number.

For each multiple of 5, print "Buzz" instead of the number.

For numbers which are multiples of both 3 and 5, print "FizzBuzz" instead of the number.*/
#include <stdio.h>
int main()
{
  int num = 1;
  while(num < 101)
  {
    char str[9] = {'\0'};//this sets all values to a default - "null" like - value
    //the value is one greater than the length of FizzBuzz, the final char is always \0
    if(num % 3 == 0)
    {
      str[0] = 'F'; str[1] = 'i'; str[2] = 'z'; str[3] = 'z';
      //this format saves space when multiple similar operations
      // must be done. #include strings.c was too easy.
      if(num % 5 == 0)
      {
        str[4] = 'B'; str[5] = 'u'; str[6] = 'z'; str[7] = 'z';
      }
    }
    else if(num % 5 == 0)
    {
      str[0] = 'B'; str[1] = 'u'; str[2] = 'z'; str[3] = 'z';
    }
    if(str[0] != '\0')
    {//if the logic found num to be divisible by 3 or 5, this must be true
      int i = 0;
      while(str[i] != '\0')
      {
        printf("%c", str[i]);
        i++;
      }
    }
    else
    {
      printf("%i", num);
    }
    //finally, a new line and an increment for num at the last point in the while loop
    printf("\n");
    num++;
  }
  return 0;
}
