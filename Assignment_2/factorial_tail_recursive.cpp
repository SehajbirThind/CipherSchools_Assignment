#include<iostream>
using namespace std;

unsigned factorial_tail(unsigned int n, unsigned int a)
{
	if (n == 0)  return a;

	return factorial_tail(n - 1, n * a);
}

unsigned int fact(unsigned int n)
{
	return factorial_tail(n, 1);
}

int main()
{
	cout << fact(8);
	return 0;
}