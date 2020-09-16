public class fizzbuzz {
  public static void main(String[] args) {
    int num = 1;
    String str = "";
    while(num < 101)
    {
      str = "";
      if(num % 3 == 0)
      {//modulo operator returns 0 if num is divisible by 3
        str += "Fizz";
      }
      if(num % 5 == 0){str += "Buzz";}
      if(str.length() > 0)
      {//length is the only built in function besides println and some basic logic and increments
        System.out.println(str);
      }
      else{System.out.println(num);}
      num++;
    }
  }
}
