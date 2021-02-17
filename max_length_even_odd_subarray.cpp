// find the length of the longest subarray that has alternating even odd elements.

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

// naive soln: O(N^2)
int maxevenodd(int arr[], int n)
{
	int res = 1;
	for (int i = 0; i < n; i++)
	{
		int curr = 1;
		for (int j = i + 1; j < n; j++)
		{
			if ((arr[j] % 2 == 0 && arr[j - 1] % 2 != 0) || (arr[j] % 2 != 0 && arr[j - 1] % 2 == 0))
				curr++;
			else
				break;


		}
		res = max(res, curr);

	}
	return res;
}

// OPTIMAL SOLN: O(N), BASED ON KADANE'S
int maxevenodd2(int arr[], int n)
{
	int res = 1;
	int curr = 1;
	for (int i = 1; i < n; i++)
	{
		if ((arr[i] % 2 == 0 && arr[i - 1] % 2 != 0) || arr[i] % 2 != 0 && arr[i - 1] % 2 == 0)
		{
			curr++;
			res = max(res, curr);
		}
		else
			curr = 1;


	}

	return res;
}


int main()
{
	c_s_c();

	int arr[] = {5, 10, 20, 6, 3, 8};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "longest even odd subarray length: " << maxevenodd(arr, n) << endl;

	cout << "longest even odd subarray length: " << maxevenodd2(arr, n) << endl;









	return 0;
}