public class repeated_string
{
  public static void main(String[] args)
  {
    String s = "ada";
    long n = 10;//length of potential substring
    System.out.println("Number of occurrences: " + String.valueOf(repeated_string(s, n)));
  }
  public static long repeated_string(String s, long n)
  {
    long count = 0, remainder = 0;
    if(s.length() > n)
    {
      char[] s_ = s.toCharArray();
      for(long i = 0; i < n; i++)//iterate through the CharArray and count 'a' occurrences. stop at n
      {if(s_[(int)i] == 'a'){count += 1;}}
      return count;
    }else{
      char[] ar = String.valueOf(s.subSequence(0, ((int)n % s.length()))).toCharArray();//for determining any overlap
      for(long i = 0; i < s.length(); i++)//iterate though String and count as above
      {
        if(s.charAt((int)i) == 'a')
        {
          count ++;//we now have the count of 'a's in the string s
          if(i <  ar.length){remainder ++;}//ar is the length of the cutoff string - 0 if no cutoff
        }
      }
      count = count * (n / (long)s.length()) + remainder;
      return count;
    }

  }
}
