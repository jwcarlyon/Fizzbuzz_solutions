public class Cloud
{
  public int value;
  public int get_value(){return value;}//values can be easily referenced - while iterating for example
  public Cloud[] adjacent;
  //Cloud constructor
  public Cloud(int[] clouds, int i)
  {
    value = clouds[i];
    if(i < clouds.length - 2)
    {
      adjacent = new Cloud[] {new Cloud(clouds, i + 2), new Cloud(clouds, i + 1)};
    }else if(i < clouds.length - 1)
    {
      adjacent = new Cloud[] {new Cloud(clouds, i + 1)};
    }
    //these
  }
  public int greedy_search()//The "public static" allows this function
  // to act like a global function would in C++.
  {
    //Search the binary list with recursion, taking the first available path
    // the structure of Cloud is that first elements of adjacent are the longest jump
    //System.out.println("Debug search, adjacent: " + (adjacent));
    if(adjacent == null){return 0;}
    for(Cloud x : adjacent)
    {
      if(x.get_value() == 0){return 1 + x.greedy_search();}
    }
    return 0;
  }
}
