#include <bits/stdc++.h>

using namespace std;

int res=0;

void Merge_Sort(int [],int);

void Merge(int a[],int b[],int c[],int n,int l1,int l2)
{
	int i=0,j=0,k=0;
	while(i<l1 && j<l2)
	{
		res++;
		if(b[i]<=c[j])
			a[k]=b[i++];
		else
			a[k]=c[j++];
		k++;
	}
	if(i==l1)
		while(j<l2)
			a[k++]=c[j++];
	else
		while(i<l1)
			a[k++]=b[i++];
}

void Merge_Sort(int a[],int n)
{
	res++;
	int cnt=0,l1=n/2,i;
	int l2=n-l1;
	int b[l1],c[l2];
	if(n>1)
	{
		for(i=0;i<l1;i++)
			b[i]=a[i];
		while(cnt < l2)
			c[cnt++]=a[i++];
		Merge_Sort(b,l1);
		Merge_Sort(c,l2);
		Merge(a,b,c,n,l1,l2);
	}
}
int main()
{
	int n=0,i,t;
	cout << "Enter the number of testcases\n";
	cin >> t;
	ofstream worst("worst.dat",ios::trunc);
	while(t--)
	{
		res=0;
		n+=10;
		int a[n];
		for(i=0;i<n;i++)
			a[i]=rand()%n;
		Merge_Sort(a,n);
		worst << n << " " << res << endl;
	}
	return 0;
}
