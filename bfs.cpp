#include <bits/stdc++.h>

using namespace std;

int res=0;
class Graph
{
	int V;
	list <int> *adj;
public:
	bool cycle;
	Graph(int V)
	{
		this->V=V;
		adj = new list<int>[V];
		cycle = false;
	} 
	void AddEdge(int,int);
	void BFS(int);
};

void Graph :: AddEdge(int v,int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph :: BFS(int v)
{
	bool *visited = new bool[V];
	int i;
	for(i=0;i<V;i++)
		visited[i] = false;

	list<int> queue;
	vector<int> parent(V,-1);

	for(i=0;i<V;i++)
	{
		if(!visited[i])
		{
			visited[i] = true;
			queue.push_back(i);
			res++;

			list<int> :: iterator it;

			while(!queue.empty())
			{
				v = queue.front();
				queue.pop_front();

				cout << v << " ";

				for(it=adj[v].begin();it!=adj[v].end();it++)
				{
					if(!visited[*it])
					{
						visited[*it] = true;
						queue.push_back(*it);
						parent[*it]=v;
					}
					else if(parent[*it]!=v)
						cycle=true;
				}
			}
		}
	}

	if(res==1)
		cout << "Connected Graph\n";
	else
		cout << "Disconnected Graph\n";

}

int main()
{
	Graph g(6);
	g.AddEdge(0,1);
	g.AddEdge(0,2);
	g.AddEdge(1,2);
	g.AddEdge(3,4);
	g.AddEdge(3,5);

	g.BFS(1);
	if(g.cycle)
		cout << "Cycle\n";
	else
		cout << "No cycle\n";
	return 0;
}

