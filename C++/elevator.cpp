/**
Select nearest elevator to user's floor

Makhtar Diouf
*/
#include <bits/stdc++.h>
using namespace std;

class Elevator {
private:
  int floor = 1;
  int numFloors = 10;
  string id = "Elevator";

public:
  Elevator() {
    static char  elevIdx = 'A';
    floor = rand() % numFloors;
    id = id + " " + elevIdx;
    elevIdx++;
    printf("Set %s @floor %d\n", id.c_str(), floor);
  }

  int getFloor() { return floor; }

  string getId() { return id; }

  bool moveTo(int _floor = 1) {
    int idx = floor - _floor;
    if (idx == 0)
      return true;
    else if (idx > 0) {
      while (floor != _floor)
        floor--;
      printf("%s moved to floor %d\n", id.c_str(), floor);
      return true;
    }

    while (floor != _floor) {
      floor++;
      printf("%s moved to floor %d\n", id.c_str(), floor);
    }
    return true;
  }
};

class Building {
private:
  int numElevators = 5;
  // Multimap in case several elevators are at the same floor
  map<int, Elevator> elMap;

public:
  Building() {
    for (int i = 0; i < numElevators; i++) {
      Elevator el;
      elMap[el.getFloor()] = el;
    }
    printf("Created Building\n");
  };

  // Call nearest elevator
  bool callElevatorTo(int floor = 1) {
    try {
      auto el = elMap.find(floor);
      if (el != elMap.end()) {
        printf("Selecting %s already @floor %d\n", el->second.getId().c_str(), floor);
        return true;
      }

      /**
      equal_range returns a pair of iterators defining the wanted range: the
      first
      pointing to the first element that is not less(?) than key (lower_bound) and the second
      pointing to the first element greater than key (upper_bound).
      */
      auto nearest = elMap.equal_range(floor);
      auto it = nearest.first;
      Elevator elv;
      if ((it!= elMap.end()) && (abs(it->second.getFloor() - floor) <= 1))
        elv = it->second;
      else if (nearest.second != elMap.end())
        elv = nearest.second->second;
      else {
        printf("Critical error: No matching elevator found near floor %d!\n",
               floor);
        return false;
      }
      printf("Sending %s from floor %d -> to floor %d\n", elv.getId().c_str(), elv.getFloor(), floor);
      elv.moveTo(floor);
      return true;

    } catch (exception e) {
      fprintf(stderr, "Error while calling elevator to floor %d\n", floor);
      return false;
    }
  }
};

int main() {
    Building b;
    b.callElevatorTo(3);
    return 0;

    }