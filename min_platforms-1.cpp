#include<bits/stdc++.h>
using namespace std;

#define ll long long

void c_s_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main()
{
	c_s_c();


	// METHOD 1: TC: O(N LOG N), SC: O(1)

	// sort the arrival and departure times individually, and then maintain a platform counter and res counter for the final answer. The technique involved tracing the numebr of trains at any time, keeping track of trains that have arrived, but not departed.

	// use pointer i for arrival, and j for departure
	// start with platform counter and res counter initialized to 1.
	// if arr[i] <= dep[j], i++, plat++, res = max(res, plat);
	// if arr[i] > dep[j], j++, plat--, res = max(res, plat);



	vector< int > arr(6);
	vector< int > dep(6);
	int n = 6;
	for (auto &x : arr)
		cin >> x;

	for (auto &x : dep)
		cin >> x;

	sort(arr.begin(), arr.end());
	sort(dep.begin(), dep.end());

	int plat = 1, res = 1;

	for (int i = 1, j = 0; i < n && j < n;)
	{
		if (arr[i] <= dep[j])
		{
			plat++;
			i++;
		}
		else if (arr[i] > dep[j])
		{
			plat--;
			j++;
		}

		res = max(res, plat);
	}

	cout << "The minimum platforms needed are: " << res << endl;

	return 0;
}