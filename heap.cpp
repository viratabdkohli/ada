#include <bits/stdc++.h>

using namespace std;

int cnt=0;

void heapify(int a[],int n,int i)
{
	cnt++;
	int larg = i;
	int l = 2*i+1;
	int r = 2*i+2;

	if(l<n && a[l] > a[larg])
		larg = l;
	if(r < n && a[r] > a[larg])
		larg = r;

	if(larg!=i)
	{
		swap(a[i],a[larg]);

		heapify(a,n,larg);
	}
}
void Heapsort(int a[],int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
	{
		cnt++;
		heapify(a,n,i);
	}
	for(i=n-1;i>=0;i--)
	{
		cnt++;
		swap(a[0],a[i]);
		heapify(a,i,0);
	}
}
int main()
{
	int n=0,i,t;
	cout << "Enter number of testcases\n";
	cin >> t;
	ofstream worst("worst.dat",ios::trunc);
	while(t--)
	{
		cnt=0;
		n+=10;
		int a[n];
		for(i=0;i<n;i++)
			a[i]=rand()%n;
		Heapsort(a,n);
		worst << n << " " << cnt << endl;
	}
	return 0;
}
