
/**
Given M busy-time slots of N people, You need to print all the available time slots when all the N people
can schedule a meeting for a duration of K minutes.

Event time will be of the form HH MM ( where 0 <= HH <= 23 and 0 <= MM <= 59 ), K will be in the form minutes

An event time slot is of form [Start Time, End Time).
Which means it inclusive at start time but doesn't include the end time.

@TODO: Complete the resulting Times printing
*/

#include <iostream>
#include <vector>
using namespace std;

int maxBusyPeriod = 24 * 60; // 24H

void print(int i) {
	if (i == 0 || i == maxBusyPeriod) {
		cout << "00 00";
		return;
	}

	int j = i / 60;
	int k = i % 60;

	if (j < 10)
		cout << "0" << j << " ";
	else
		cout << j << " ";

	if (k < 10)
		cout << "0" << k;
	else
		cout << k;
}


int main()
{
	int m = 0, k = 0;
	cin >> m >> k;

	int stH, stM, endH, endM;
	stH = stM = endH = endM = 0;
	int i = 0;
	vector<int> busyPeriods(maxBusyPeriod);

	while (m--) {
		cin >> stH >> stM >> endH >> endM;
		int start = (stH * 60) + stM;
		int end = (endH * 60) + endM;

		fprintf(stderr, "In: %0d:%0d %0d:%0d \n", stH, stM, endH, endM);

		for (i = start; i < end; i++)
			busyPeriods.push_back(1);
	}

	i = 0;
	int j = 0;
	while (i < maxBusyPeriod) {
		j = i;
		if (busyPeriods[j] == 1) {
			i++;
			continue;
		}

		while ((j < maxBusyPeriod) && (busyPeriods[++j] != 1))
			continue;

		// Available time shall be at least the Kmns necessary for the meeting
		// Print time in hours form
		if ((j - i) >= k) {
			print(i);
			cout << " ";
			print(j);
			cout << endl;
			/*
			if (i == 0 || i == maxBusyPeriod)
				printf("00 00");
			else
				printf("%0d %0d  ", i / 60, i % 60);
				*/
		}
		i = j;
	}

}
