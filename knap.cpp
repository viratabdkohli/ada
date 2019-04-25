#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

int Knapsack(int n,int weight[],int val[],int cap,vector <vector<int> > &M)
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=cap;j++)
		{
			cnt++;
			if(i==0 || j==0)
				M[i][j] = 0;
			else if(weight[i] <= j)
				M[i][j] = max(val[i]+M[i-1][j-weight[i]],M[i-1][j]);
			else
				M[i][j]=M[i-1][j];
		}
	}
	return M[n][cap];
}
int main()
{
	int n=0,t,i;
	cout << "Enter the number of testcases\n";
	cin >> t;
	ofstream worst("worst.dat",ios::trunc);
	while(t--)
	{
		n+=1;
		int weight[n+1];
		for(int i=1;i<=n;i++)
			weight[i] =rand()%n;	
		int val[n+1];
		for(int i=1;i<=n;i++)
			val[i]=rand()%n;
		int cap =rand()%n;
		vector <vector<int> > M(n+1,vector<int>(cap+1,0));
		cout << Knapsack(n,weight,val,cap,M);
		worst << n << " " << cnt << endl;

	}
	return 0;
}
