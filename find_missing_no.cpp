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

int getMissingNo(int a[], int n)
{
	int n1 = a[0];

	int n2 = 1;

	for (int i = 1; i < n; i++)
		n1 = n1 ^ a[i];

	for (int i = 2; i <= n + 1; i++)
		n2 = n2 ^ i;

	return (n1 ^ n2);
}

int main()
{
	c_s_c();

	int arr[] = { 1, 2, 3, 4, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int mn = findMissingNo(arr, n);
	cout << mn;
}






