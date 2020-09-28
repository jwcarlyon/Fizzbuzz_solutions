public class Cloud
{
  public int value;
  public int get_value(){return value;}
  public Cloud one = null;
  public Cloud two = null;
  //Cloud constructor
  public Cloud(int i){value = i;}
  public Cloud(Cloud c){value = c.get_value(); one = c.one; two = c.two;}
  //search method
  public int greedy_search(Cloud n)
  {
    if((n.one == null)&& !(n.two == null)){return 1 + greedy_search(n.two);}
    else if(!(n.one == null)){return 1 + greedy_search(n.one);}
    else{return 0;}
  }
}
