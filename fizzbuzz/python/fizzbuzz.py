'''Write a short program that prints each number from 1 to 100 on a new line.

For each multiple of 3, print "Fizz" instead of the number.

For each multiple of 5, print "Buzz" instead of the number.

For numbers which are multiples of both 3 and 5, print "FizzBuzz" instead of the number.'''

def fizzbuzz():
    for x in range(1, 101):
        str = ""
        if x % 3 == 0:
            str += "Fizz"
            if x % 5 == 0:
                str += "Buzz"
        elif x % 5 == 0:
            str += "Buzz"
        if str:
            print(str)
        else:
            print(x)

if __name__ == "__main__":
    # execute only if run as a script
    fizzbuzz()
