#include <iostream>
using namespace std;

int gas_station(
  int* gas_station_capacity_array,
  int* travel_cost_to_next_array,
  int circuit_size);
bool begin_circuit(
  int* gas_station_capacity_array,
  int* travel_cost_to_next_array,
  int circuit_size,
  int beginning_station
);

int main()
{
    int gas_station_capacity_array[] = { 1, 2, 3, 4, 5 };
    int travel_cost_to_next_array[] = { 3, 4, 5, 1, 2 };
    // int gas_station_capacity_array[] = { 2,3,4 };
    // int travel_cost_to_next_array[] = { 3,4,3 };
    //int gas_station_capacity_array[2] = {1, 2};
    //int travel_cost_to_next_array[2] = {2, 1};
    int size = sizeof(gas_station_capacity_array) / sizeof(gas_station_capacity_array[0]);
    std::cout << "Begin at station: "
        << gas_station(&gas_station_capacity_array[0], &travel_cost_to_next_array[0], size)
        << std::endl;
    return 0;
}

bool begin_circuit(
  int* gas_station_capacity_array,
  int* travel_cost_to_next_array,
  int circuit_size,
  int beginning_station
) {
    int tank = 0;
    int current_station = beginning_station;
    for(int stations_visited = 0; stations_visited < circuit_size; stations_visited++)
    {
        tank += gas_station_capacity_array[current_station];
        if(travel_cost_to_next_array[current_station] > tank)
        { return false; }
        tank -=  travel_cost_to_next_array[current_station];
        int next_station = (current_station + 1) % circuit_size;
        current_station = next_station; //let's go
    }
    return true;
}

int gas_station(
  int* gas_station_capacity_array,
  int* travel_cost_to_next_array,
  int circuit_size
) {
    for(int beginning_station = 0; beginning_station < circuit_size; beginning_station++)
    {
        if(begin_circuit(
          gas_station_capacity_array,
          travel_cost_to_next_array,
          circuit_size,
          beginning_station
        )) { return beginning_station;}
    }
    return -1;
}
