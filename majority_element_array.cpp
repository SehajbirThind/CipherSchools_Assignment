// majority element is element that appears more than n/2 times.
// the function returns index of any 1 occurence of majority element.

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

// naive O(N^2)
int majelem(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int count = 1;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] == arr[j])
				count++;

		}
		if (count > (n / 2))
			return i;
	}
	return -1;
}

// efficient: O(N)
int majelem2(int arr[], int n)
{

	// ALSO CALLED  BOYER MOORE'S VOTING ALGORITHM.
	// THIS ALGO MAY NOT ALWAYS GIVE INDEX OF 1ST OCCURENCE OF THE MAJORITY ELEMENT. IT MAY GIVE SOME OTHER INDEX OF OCCRENCE OF MAJORITY ELEMENT.

// FIND A CANDIDATE:
	int res = 0, count = 1;
	for (int i = 1; i < n; i++)
	{
		if (arr[res] == arr[i])
			count++;
		else
			count--;
		if (count == 0)
			res = i, count = 1;
	}

	// CHECK IF THE CANDIDATE IS ACTUALLY A MAJORITY:

	count = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[res] == arr[i])
			count++;

	}
	if (count <= (n / 2))
		res = -1;

	return res;
}



int main()
{
	c_s_c();
	int arr[] = {8, 7, 6, 8, 6, 6, 6, 6};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << majelem(arr, n);







	return 0;
}