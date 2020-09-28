public class jumping_on_clouds
{
  public static void main(String[] args)
  {
    //int[] clouds = {0, 0, 1, 0, 0, 1, 0, 1, 0 ,1, 0, 0, 1, 0};
    int[] clouds = {0, 1, 0, 0, 0, 1, 0, 1, 0};
    Cloud head = new Cloud(build_binary_graph(clouds, 1));
    if((clouds.length > 2) && (clouds[2] == 0)){head.two = build_binary_graph(clouds, 2);}
    else if(clouds.length > 1){head.one = build_binary_graph(clouds, 1);}
    //a greedy search, leveraging the structure of cloud

    System.out.println("Minimum # of jumps to win: " +  head.greedy_search(head));
  }
  public static Cloud build_binary_graph(int[] clouds, int i)
  {
    Cloud n = new Cloud(clouds[i]);
    if(i < clouds.length - 2)
    {
      if(clouds[i + 2] == 0)
      {n.two = build_binary_graph(clouds, i + 2);}
      else {n.one = build_binary_graph(clouds, i + 1);}
      //this is an optimization step. Single jumps
      // are waste, unless needed
    }else if(i < clouds.length - 1){n.one = build_binary_graph(clouds, i + 1);}
    return n;
  }
}
