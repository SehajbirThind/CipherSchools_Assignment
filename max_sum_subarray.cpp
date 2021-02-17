// NAIVE SOLN: O(N^2)
/*

int res = arr[0];
for(int i = 0; i < n; i++)
{
	int curr = 0;
	for(int j = i; j < n; j++)
	{
		curr = curr + arr[i];
		res = max(res, curr);
	}
}
return res;


// KADANE'S ALGORITHM: O(N)
// WE STORE ONLY THE MAXIMUM CUMULATIVE SUM.
// maxEnding[i] = max(maxEnding(i - 1) + arr[i], arr[i])
// this means, for any current element arr[i], you either consider (previous sum + arr[i]), or only arr[i], whichever is maximum. this result is then updated in previous sum, and then we move to next element of array.

*/




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

int maxSum(vector< int >&arr)
{
	int n = arr.size();
	int res = arr[0];
	int maxEnding = arr[0];
	for (int i = 1; i < n; i++)
	{
		maxEnding = max(maxEnding + arr[i], arr[i]);
		res = max(res, maxEnding);
	}
	return res;

}


int main()
{
	c_s_c();
	vector< int >v = { -2, -3, 4, -1, -2, 1, 5, -3};
	cout << "The maximum subarray sum is: " << maxSum(v) << endl;







	return 0;
}