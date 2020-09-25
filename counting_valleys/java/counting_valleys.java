public class counting_valleys
{
  public static void main(String[] args)
  {
    String case0 = "UUDUDDDDUUUDDDDUUU";
    System.out.println(count_valleys(case0.length(), case0));
  }
  public static int count_valleys(int steps, String path)
  {
      boolean above = true;
      int pos = 0;
      int valleys = 0;
      for(int i = 0; i < path.length(); i++)
      {
        if(path.charAt(i) == 'U'){pos++;}
        if(path.charAt(i) == 'D'){pos--;}
        if((pos < 0) && above){above = false;}
        else if((pos >= 0) && !above){above = true; valleys++;}
      }
      return valleys;
  }
}
