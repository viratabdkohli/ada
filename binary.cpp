#include <bits/stdc++.h>
using namespace std;

void sort_arrary(int arr[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
		for(j=i+1;i<n;i++)
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
}

int binary_search(int arr[],int n,int key)
{
	int low=0,high=n-1,mid,count;

	while(low<=high)
	{
		count++;
		mid=(high+low)/2;

		if(arr[mid]==key)
			break;
		else if(arr[mid]<key)
			low=mid+1;
		else
			high=mid-1;
	}
	return count;
}

int main()
{
	int t,n=0;
	cout<<"Enter the num of testcases\n";
	cin>>t;

	ofstream worst("worst.dat",ios::trunc);
	ofstream avg("avg.dat",ios::trunc);
	ofstream best("best.dat",ios::trunc);

	while(t--)
	{
		n+=10;
		int arr[n];

		srand(time(0));

		for(int i=0;i<n;i++)
			arr[i]=rand()%n;
		sort_arrary(arr,n);
		int key = rand()%(n/2);

		avg<<n<<" "<<binary_search(arr,n,key);
		worst<<n<<" "<<binary_search(arr,n,n);
		best<<n<<" "<<binary_search(arr,n,arr[(n-1)/2]);
	}	
	return 0;
}
