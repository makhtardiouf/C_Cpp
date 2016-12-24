/**
Select nearest elevator to user's floor

Makhtar Diouf
*/
#include <bits/stdc++.h>
#include <functional>
using namespace std;

char elevIdx = 'A';
int numFloors = 13;

class Elevator {
private:
  int floor = 1;
  string id = "Elevator";
  std::hash<string> hashFunc;

public:
  Elevator() {
    floor = rand() % numFloors;
    id = id + " " + elevIdx;
    elevIdx++;
    printf("\tSet %s @%dF\n", id.c_str(), floor);
  }

  int getFloor() { return floor; }

  string getId() { return id; }

  // Move the elevator to the indicated floor
  bool moveTo(int _floor = 1) {
    int idx = floor - _floor;
    if (idx == 0)
      return true;

    else if (idx > 0) {
      while (floor != _floor) {
        floor--;
        printf("\t\t...%s moved to %dF\n", id.c_str(), floor);
      }
    } else {
      while (floor != _floor) {
        floor++;
        printf("\t\t...%s moved to %dF\n", id.c_str(), floor);
      }
    }
    printf("\t\t...arrived\n");
    return true;
  }
};

class Building {
private:
  int numElevators = 5;
  // Multimap in case several elevators are at the same floor
  multimap<int, Elevator> elMap;

public:
  Building() {
    for (int i = 0; i < numElevators; i++) {
      Elevator el;
      elMap.insert(std::make_pair(el.getFloor(), el));
    }
    printf("\nCreated Building\n");
  };

  // Call nearest elevator
  bool sendElevatorTo(int floor = 1) {
    try {
      auto el = elMap.find(floor);
      if (el != elMap.end()) {
        printf("Selecting %s already @ %dF\n", el->second.getId().c_str(),
               floor);
        return true;
      }

      // Find the first element that is not less(?) than key (lower_bound)
      auto nearest = elMap.lower_bound(floor);
      Elevator elv;
      if ((nearest != elMap.end()) &&
          (abs(nearest->second.getFloor() - floor) <= 1))
        elv = nearest->second;
      else
        elv = (--nearest)->second;

      printf("\tSending %s from %dF -> to %dF\n", elv.getId().c_str(),
             elv.getFloor(), floor);

      // Move and update the key to the new location
      elv.moveTo(floor);
      if (nearest != elMap.end())
        elMap.erase(nearest);
      elMap.insert(std::make_pair(floor, elv));
      return true;

    } catch (exception e) {
      fprintf(stderr, "Error while calling elevator to %dF\n", floor);
      return false;
    }
  }
};

int main() {
  Building b;
  for (int i = 0; i < 4; i++) {
    printf("\n*** Test No. %d\n", i);
    b.sendElevatorTo(rand() % numFloors + i);
  }
  return 0;
}