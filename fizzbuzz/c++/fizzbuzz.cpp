#include <stdio.h>

int main()
{
    int current_number = 1;
    bool divisible_by_three, divisible_by_five, divisible_by_both;
    while(current_number < 101)
    {
        divisible_by_three = (current_number % 3) == 0;
        divisible_by_five = (current_number % 5) == 0;
        divisible_by_both = divisible_by_three && divisible_by_five;
        if(divisible_by_both)
        {
            printf("FizzBuzz\n");
            current_number++;
            continue;
        }
        if(divisible_by_three)
        {
            printf("Fizz\n");
            current_number++;
            continue;
        }
        if(divisible_by_five)
        {
            printf("Buzz\n");
            current_number++;
            continue;
        }
        printf("%i\n", current_number++);
    }
    return 0;
}
