#include <bits/stdc++.h>

using namespace std;

int cnt=0;

class Graph
{
	int V;
	list<int> *adj;
	void DFSutil(int,bool[],int);
   public:
   	Graph(int V)
   	{
   		this->V=V;
   		adj = new list<int>[V];
   		cycle = false;
   	}
   	bool cycle;
   	void DFS(int);
   	void AddEdge(int v,int w);
};

void Graph :: AddEdge(int v,int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph :: DFSutil(int v,bool visited[],int parent)
{
	visited[v] = true;

	cout << v << " ";
	list<int> :: iterator it;

	for(it=adj[v].begin();it!=adj[v].end();it++)
	{
		if(!visited[*it])
		{
			DFSutil(*it,visited,v);
		}
		else if(*it!=parent)
			cycle = true;
	}
}
void Graph :: DFS(int v)
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i] = false;

	for(int i=0;i<V;i++)
		if(!visited[i])
		{
			cnt++;
			DFSutil(i,visited,-1);
		}

}
int main()
{
	Graph g(5);

	g.AddEdge(0,1);
	g.AddEdge(0,2);
	//g.AddEdge(1,2);
	g.AddEdge(3,4);
	cout << endl;
	g.DFS(0);
	if(g.cycle)
		cout << "Cycle\n";
	else
		cout << "No Cycle\n";

	if(cnt==1)
		cout << "Connected\n";
	else
		cout << "Disconnected\n";
	return 0;
} 
