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

void merge(vector< int >& v, int l, int mid, int r)
{
	int n1 = mid - l + 1;
	int n2 = r - mid;
	vector< int >a(n1);
	vector< int >b(n2);

	// SETTING-UP AUXILIARY ARRAYS:
	for (int i = 0; i < n1; i++)
	{
		a[i] = v[l + i];
	}
	for (int i = 0; i < n2; i++)
	{
		b[i] = v[mid + i + 1];
	}

	int i = 0, j = 0, k = l;

	while (i < n1 && j < n2)
	{
		if (a[i] <= b[j])
		{
			v[k] = a[i];
			i++; k++;
		}
		else
		{
			v[k] = b[j];
			j++; k++;
		}
	}

	while (i < n1)
	{
		v[k] = a[i];
		i++; k++;
	}
	while (j < n2)
	{
		v[k] = b[j];
		j++; k++;
	}

}

void mergeSort(vector< int >& v, int l, int r)
{
	if (l < r)
	{
		int mid = l + (r - l) / 2;
		mergeSort(v, l, mid);
		mergeSort(v, mid + 1, r);
		merge(v, l, mid, r);

	}
}

int main()
{
	c_s_c();

	int n;
	cin >> n;

	vector< int >v(n);

	for (auto &x : v)
		cin >> x;

	mergeSort(v, 0, n - 1);

	for (auto x : v)
		cout << x << " ";

	return 0;
}