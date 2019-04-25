#include <bits/stdc++.h>

using namespace std;

int minkey(int key[],bool set[],int n)
{
	int i,min=INT_MAX,index;
	for(i=0;i<n;i++)
	{
		if(set[i]==false && key[i]<min)
		{
			min=key[i];
			index=i;
		}
	}
	return index;
}

void print(vector < vector <int> > &V,int n,int parent[])
{
	cout << "Edges\tWeights\n";
	for(int i=1;i<n;i++)
		cout << parent[i] << "->" << i << "\t" << V[i][parent[i]] << endl;
}
void Prims(vector < vector <int> > &V,int n)
{
	int parent[n],key[n];
	bool set[n];

	int i,j;
	for(i=0;i<n;i++)
	{
		set[i]=false;
		key[i]=INT_MAX;
	}

	key[0]=0;
	parent[0]=-1;

	for(i=0;i<n-1;i++)
	{
		int u =minkey(key,set,n);

		set[u] = true;

		for(j=0;j<n;j++)
		{
			if(V[u][j] && set[j]==false && V[u][j] < key[j])
			{
				parent[j]=u;
				key[j]=V[u][j];
			}
		}
	}
	print(V,n,parent);
}
int main()
{
	int n,i,j;
	cout << "Enter n\n";
	cin >> n;
	cout << "Enter weights\n";
	vector < vector <int> > V(n,vector<int>(n,0));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin >> V[i][j];
	Prims(V,n);

	return 0;
}
