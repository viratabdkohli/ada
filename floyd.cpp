#include <bits/stdc++.h>

using namespace std;

int cnt=0;
void Floyds(vector < vector <int> > &M,int n)
{
	
	int i,j,k;
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				cnt++;
				M[i][j]=min(M[i][j],M[i][k]+M[k][j]);
			}
}
int main()
{
	int n=0,i,j,t;
	cout << "Enter t\n";
	cin >> t;
	
	ofstream worst("worst.dat",ios::trunc);
	while(t--)
	{
		cnt=0;
		n+=5;
		vector < vector <int> > M(n,vector<int>(n,0));
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				M[i][j]=rand()%n;
			Floyds(M,n);
		worst << n << " " << cnt << endl;
	}
	return 0;
}
