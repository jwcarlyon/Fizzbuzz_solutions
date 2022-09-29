#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <string>
#include <tgmath.h>
#include <vector>
using namespace std;

class shopper
{
    public:
      class euclidean_distance
      {
          public:
            string shopper_name;
            double distance;
            euclidean_distance(string given_name = "", double given_distance = 100.0f)
            {
                shopper_name = given_name;
                distance = given_distance;
            }
      };
      vector<euclidean_distance> distances;
      string name;
      vector<string> shopping_list;
      static map<string, int> shopping_to_integer_map;

      shopper(string given_name, vector<string>& given_shopping_list)
      {
          name = given_name;
          set_shopping_list(given_shopping_list);
          all_shoppers.push_back(*this);
      }
      static void find_all_distances()
      {//O(n^2) this is not good on large scales...
          euclidean_distance temporary_euclidean_distance = euclidean_distance();
          euclidean_distance* closest_euclidean_distance = &temporary_euclidean_distance;
          for(vector<shopper>::iterator shopper_iterator = all_shoppers.begin();
            shopper_iterator < all_shoppers.end();
            shopper_iterator++
          ){
              for(vector<shopper>::iterator other_shopper_iterator = shopper_iterator;
                other_shopper_iterator < all_shoppers.end();
                other_shopper_iterator++
              ){
                  if(shopper_iterator == other_shopper_iterator){ continue; }
                  string name = other_shopper_iterator->name;
                  double distance = shopper_iterator->get_euclidean_distance(*other_shopper_iterator);
                  euclidean_distance distance_to_shopper = euclidean_distance(name, distance);
                  shopper_iterator->distances.push_back(distance_to_shopper);
                  if(closest_euclidean_distance && (closest_euclidean_distance->distance > distance))
                  {   closest_euclidean_distance = &distance_to_shopper; }
              }
              shopper_iterator->closest_euclidean_distance = *closest_euclidean_distance;
              closest_euclidean_distance = &temporary_euclidean_distance;
          }
      }
      static void print_closest_shoppers()
      {
          string name;
          double shortest_euclidean_distance;
          for(vector<shopper>::iterator shopper_iterator = all_shoppers.begin();
            shopper_iterator < all_shoppers.end();
            shopper_iterator++
          ){
              name = shopper_iterator->closest_euclidean_distance.shopper_name;
              shortest_euclidean_distance = shopper_iterator->closest_euclidean_distance.distance;
              cout << "Shopper name: " << shopper_iterator->name << ", closest neighbor: " << name << ", distance: " << shortest_euclidean_distance << endl;
          }
      }

    private:
      static vector<shopper> all_shoppers;
      string closest_shopper;
      euclidean_distance closest_euclidean_distance;

      double get_euclidean_distance(shopper &distant_shopper)
      {
          shopper other_shopper = distant_shopper;
          vector<string>& shorter_shopping_list =
              (other_shopper.shopping_list.size() >= shopping_list.size()) ?
              shopping_list :
              other_shopper.shopping_list;
          vector<string>& longer_shopping_list =
              (other_shopper.shopping_list.size() <= shopping_list.size()) ?
              other_shopper.shopping_list :
              shopping_list;
          double final_distance;
          int overrun_counter = 0;
          for(int item_iterator = 0; item_iterator < longer_shopping_list.size(); item_iterator++)
          {
              int shopper_item_value = shopping_to_integer_map[longer_shopping_list.at(item_iterator)];
              int other_shopper_item_value;
              try
              {
                  other_shopper_item_value = shopping_to_integer_map[shorter_shopping_list.at(item_iterator)];
              } catch (out_of_range const& exc) {
                  cout << exc.what() << "\n ignoring vector overrun\n";
                  other_shopper_item_value = shopping_to_integer_map[shorter_shopping_list[overrun_counter]];
                  overrun_counter = (overrun_counter + 1) % shorter_shopping_list.size();
              }
              final_distance += square(shopper_item_value - other_shopper_item_value);
          }
          return sqrt(final_distance);
      }
      void set_shopping_list(vector<string>& given_shopping_list)
      {
          vector<string> user_shopping_list = given_shopping_list;
          for(vector<string>::iterator shopping_iterator = user_shopping_list.begin();
            shopping_iterator < user_shopping_list.end();
            shopping_iterator++
          ) {
              shopping_list.push_back(*shopping_iterator);
              if(shopping_to_integer_map.empty() || !shopping_to_integer_map[*shopping_iterator])
              {
                  shopping_to_integer_map[*shopping_iterator] = shopping_to_integer_map.size();
              }
          }
          sort(shopping_list.begin(), shopping_list.end(), sort_shopping_list_by_map_value);
      }
      static bool sort_shopping_list_by_map_value(string item_one, string item_two)
      {
        return shopping_to_integer_map[item_one] < shopping_to_integer_map[item_two];
      }
      int square(int number)//this function was not written by me, I am using it and citing the source
      {//https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/
          // Base case
          if(number == 0)
          {   return 0; }
          // Handle negative number
          if (number < 0)
          {   number = -number; }
          // Get floor(n/2) using right shift
          int x = number >> 1;
          // If n is odd
          if (number & 1)
          {   return ((square(x) << 2) + (x << 2) + 1);  }
          else // If n is even
          {   return (square(x) << 2); }
      }
};

//static member must be initialized outside of the class, and only once (this could be in a separate cpp file)
map<string, int> shopper::shopping_to_integer_map = map<string, int>{};
vector<shopper> shopper::all_shoppers = vector<shopper>{};

int main(int argc, char const *argv[])
{
    vector<shopper> shoppers;
    {
        vector<string> shopping_list = { "Banana", "Coffee", "Coffee", "Energy Drink" };
        shoppers.push_back(shopper("__fred__", shopping_list));
    }
    {
        vector<string> shopping_list = { "Cup Cakes", "Cigarettes", "Wine", "Lighter" };
        shoppers.push_back(shopper("__ralph__", shopping_list));
    }
    {
        vector<string> shopping_list = { "Coffee", "Fountain Drink", "Gum", "Lighter", "Propane" };
        shoppers.push_back(shopper("__jeff__", shopping_list));
    }
    {
        vector<string> shopping_list = { "Candy Bar", "Energy Drink" };
        shoppers.push_back(shopper("__jake__", shopping_list));
    }
    {
        vector<string> shopping_list = { "Coffee", "Toy Robot" };
        shoppers.push_back(shopper("__brian__", shopping_list));
    }
    shopper::find_all_distances();
    shopper::print_closest_shoppers();
    return 0;
}
