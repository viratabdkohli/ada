#include <bits/stdc++.h>

using namespace std;

int cnt=0;

void Quick(int [],int,int,int);

int Partition(int a[],int l,int h)
{
	int i=l+1,j=h;
	int p=a[l];
	while(i<=j)
	{
		while(a[i]<=p)
		{
			cnt++;
			i++;
		}
		while(a[j]>p)
		{
			cnt++;
			j--;
		}
		swap(a[i],a[j]);
	}
	swap(a[i],a[j]);
	swap(a[l],a[j]);
	return j;
}
void Quick(int a[],int n,int l,int h)
{
	cnt++;
	int s;
	if(l<h)
	{
		s=Partition(a,l,h);
		Quick(a,n,l,s-1);
		Quick(a,n,s+1,h);
	}
}
int main()
{
	int n=0,i,t=0;
	cout << "Enter number of testcases\n";
	cin >> t;
	ofstream best("best.dat",ios::trunc);
	ofstream worst("worst.dat",ios::trunc);
	while(t--)
	{
		cnt=0;
		n+=10;
		int a[n];
		for(i=0;i<n;i++)
			 a[i]=rand()%n;
		Quick(a,n,0,n-1);
		best << n << " " << cnt << endl;
		for(i=0;i<n;i++)
			a[i]=i;
		Quick(a,n,0,n-1);
		worst << n << " " << cnt << endl;
	}
	return 0;
}
