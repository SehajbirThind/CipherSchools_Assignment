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

long long merge(vector< int >& v, int l, int mid, int r)
{
	long long inv = 0;

	int n1 = mid - l + 1;
	int n2 = r - mid;

	vector< int > a(n1);
	vector < int > b(n2);

	for (int i = 0; i < n1; i++)
	{
		a[i] = v[l + i];
	}
	for (int i = 0; i < n2; i++)
	{
		b[i] = v[mid + i + 1];
	}

	int i = 0, j = 0, k = l;

	while (i < n1 and j < n2)
	{
		if (a[i] <= b[j])
		{
			v[k] = a[i];
			k++; i++;
		}
		else   // a[i] > b[j] (inversion case)
		{
			v[k] = b[j];
			inv += n1 - i;   // IMPORTANT STEP
			k++;
			j++;

		}

	}

	while (i < n1)
	{
		v[k] = a[i];
		k++; i++;
	}

	while (j < n2)
	{
		v[k] = b[j];
		k++; j++;
	}

	return inv;

}


long long mergeSort(vector< int >& v, int l, int r)
{
	long long inv = 0;

	if (l < r) {
		int mid = l + (r - l) / 2;
		inv += mergeSort(v, l, mid);
		inv += mergeSort(v, mid + 1, r);

		inv += merge(v, l, mid, r);
	}

	return inv;
}

int main()
{
	c_s_c();

	int n;
	cin >> n;

	vector< int >v(n);

	for (auto &x : v)
		cin >> x;

	cout << mergeSort(v, 0, n - 1);









	return 0;
}