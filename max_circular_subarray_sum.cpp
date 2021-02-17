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


/* NAIVE SOLN O(N^2)

int res = arr[0];

for(int i = 0; i < n; i++)
{
	int curr_max = arr[i];
	int curr_sum = arr[i];
	for(int j = 1; j < n; j++)
	{
		int index = (i + j) % n;
		curr_sum += arr[index];
		curr_max = max(curr_max, curr_sum);
	}
	res = max(res, curr_max);

}
return res;


EFFICIENT SOLN: O(N)

FIND MAX OF THE FOLLOWING TWO:
1) MAX SUM OF A NORMAL SUB-ARRAY (USING KADANE)
2) MAX SUM OF A CIRCULAR SUB-ARRAY (WILL BE DISCUSSED)

THE IDEA FOR 2) IS TO FIND OUT THE "MINIMUM" SUM SUB-ARRAY USING KADANE, AND THEN SUBTRACT IT FROM THE TOTAL ARRAY SUM TO GET THE REQUIRED MAX. CIRCULAR SUM SUBARRAY.

*/

int normalMaxSum(vector< int > &arr) // NORMAL, USING KADANE
{
	int n = arr.size();
	int res = arr[0], maxEnding = arr[0];
	for (int i = 1; i < n; i++)
	{
		maxEnding = max(arr[i], maxEnding + arr[i]);
		res = max(res, maxEnding);
	}
	return res;

}

int overallMaxSum(vector< int > &arr)
{
	int maxNormal = normalMaxSum(arr);


	// if maxNormal is already negative, it means all elements are negative in the array. this means this is our answer.
	if (maxNormal < 0)
		return maxNormal;

	int arrsum = 0;
	int n = arr.size();

	for (int i = 0; i < n; i++)
	{
		arrsum += arr[i];
		arr[i] = -arr[i];  // invert the array elements in order to find minimum sum sub-array using kadane, and then subtract that min sum from the sum of array elements in order to get the max circular sum.
	}

	int x = normalMaxSum(arr);
	x = -x;
	int maxCircular = arrsum - x;

	return max(maxNormal, maxCircular);
}

int main()
{
	c_s_c();

	vector< int >v = {8, -4, 3, -5, 4};

	cout << "Max Circular Subarray Sum is " << overallMaxSum(v) << endl;

	// IMPORTANT CORNER CASE:

	vector<int> v2 = { -5, -3};
	cout << "Max Circular Subarray Sum is " << overallMaxSum(v2) << endl;

	return 0;
}