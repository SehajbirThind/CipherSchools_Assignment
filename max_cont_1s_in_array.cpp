#include<bits/stdc++.h>
using namespace std;

void c_s_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

// NAIVE: O(N^2)
int max1s(int arr[], int n)
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int curr = 0;
		for (int j = i; j < n; j++)
		{
			if (arr[j] == 1)
				curr++;
			else
				break;
		}
		res = max(res, curr);
	}
	return res;
}


// optimal, O(N)
int max1s2(int arr[], int n)
{
	int res = 0, curr = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != 1)
			curr = 0;
		else
		{
			curr++;
			res = max(res, curr);

		}


	}
	return res;
}






int main()
{
	c_s_c();

	int arr[] = {1, 0, 1, 1, 1, 1, 0, 1, 1};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << max1s(arr, n) << endl;
	cout << max1s2(arr, n) << endl;













	return 0;
}