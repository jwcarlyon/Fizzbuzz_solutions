import java.util.ArrayList;
// import java.util.Arrays;
// import java.util.List;

public class counting_valleys
{
  public static void main(String[] args)
  {
    // ArrayList<String> case_list = new ArrayList<String>(Arrays.asList("UUDUDDDDUUUDDDDUUU", "DDDUUUDDDUUUUDDDUUU"));
    // String case0 = "UUDUDDDDUUUDDDDUUU";
    // String case1 = "DDDUUUDDDUUUUDDDUUU";
    ArrayList<String> case_list = new ArrayList<String>();
    case_list.add("UUDUDDDDUUUDDDDUUU");
    case_list.add("DDDUUUDDDUUUUDDDUUU");

    case_list.forEach((case) ->
        System.out.println(
            String.format("Number of valleys traversed: %s", count_valleys(case))
        );
    );
  }
  public static int count_valleys(String path)
  {
      boolean above = true;
      int altitude = 0;
      int valleys = 0;
      for(int i = 0; i < path.length(); i++)
      {
        if(path.charAt(i) == 'U'){altitude++;}
        else if(path.charAt(i) == 'D'){altitude--;}
        if((altitude < 0) && above){above = false;}
        else if((altitude >= 0) && !above){above = true; valleys++;}
      }
      return valleys;
  }
}
