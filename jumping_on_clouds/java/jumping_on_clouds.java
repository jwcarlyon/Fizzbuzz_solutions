public class jumping_on_clouds
{
  public static void main(String[] args)
  {
    int[] clouds = {0, 0, 1, 0, 0, 1, 0, 1, 0 ,1, 0, 0, 1, 0};
    //int[] clouds = {0, 1, 0, 0, 0, 1, 0, 1, 0};
    Cloud binary_graph = new Cloud(clouds, 0);
    //a greedy search, leveraging the structure of cloud

    System.out.println("Minimum # of jumps to win: " + binary_graph.greedy_search());
  }

}
