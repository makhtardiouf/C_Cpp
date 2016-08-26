
/*
  Fibonacci Factor common divisors

*/

#include<iostream>
#include<algorithm>

using namespace std;
typedef unsigned long long ul;

inline ul calcFibo(ul a, ul b) {
	if (a % 2 == 0 && b % 2 == 0) return 2;

	for (ul i = 3; i <= b; i += 2)
		if (a%i == 0 && b%i == 0) return i;
	return 1;
}


int main()
{
	uint32_t k = 0, t = 0;
	cin >> t;

	while (t--)
	{
		cin >> k;
		ul f = 2, prev = 1, temp, d = 1;

		while (f <= k) {
			d = calcFibo(k, f);
			if (d > 1) break;
			temp = prev;
			prev = f;
			f += temp;
		}

		if (d > 1)
			cout << f << " " << d << endl;
		else {

			while ((f % k) != 0) {
				temp = prev;
				prev = f;
				f += temp;
			}
			printf("%ul %ul\n", f, k);
		}
	}
}
