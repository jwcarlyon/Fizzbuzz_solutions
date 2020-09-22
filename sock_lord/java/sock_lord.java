import java.util.Vector;
public class sock_lord
{
  public static void main(String[] args)
  {
    int sequence[] = {5, 5, 5, 9, 8, 7, 6, 5};
    ArrayList<int> ar = new ArrayList<int>();
    for(int i : sequence){ar.add(i);}
    Collections.sort(ar);
    int pairs = 0;
    int count = 0;
    int last = ar.get(0);
    for(int i : ar)
    {
      str = "";
      if(i == last){count++;}
      else{pairs += count / 2;}
    }
    pairs += count / 2;
    String str = "Number of pairs: " + pairs;
    System.out.println(str);
  }
}
