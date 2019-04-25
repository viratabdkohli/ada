#include <bits/stdc++.h>

using namespace std;

int cnt=0;

void Warshall(vector < vector <int> > &M,int n)
{
	int i,j,k;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
			if(M[i][k])
				for(j=0;j<n;j++)
				{
					cnt++;
					if(M[k][j])
						M[i][j]=1;
				}
	}
}

int main()
{
	int n=0,i,j,t;

	cout << "Enter the number of testcase\n";
	cin >> t;
	ofstream worst("worst.dat",ios::trunc);
	while(t--)
	{
		cnt=0;
		n+=2;
		vector < vector <int> > M(n,vector<int>(n,0));
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				M[i][j]=rand()%2;
		Warshall(M,n);
		worst << n << " " << cnt << endl;
	}
	return 0;
}
