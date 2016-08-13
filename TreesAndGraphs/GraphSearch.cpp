/**
 *  Task: Class for representing a graph and implementations of several 
 *  search algorithms (BFS, DFS)
 */ 

// -----------------------------------------------------------------------------

#include <iostream>

#include <vector>
#include <map>
#include <queue>

using namespace std;

// -----------------------------------------------------------------------------

class Graph
{
public:
	Graph();

	~Graph();

	void addEdge( int a, int b );

	map< int, bool > getVisitedNodes();

	void BFS( int start );

	void DFS( int start );

private:
	map< int, vector<int> > mNodes;
};

Graph::Graph()
{
}

Graph::~Graph()
{
}

void Graph::addEdge( int a, int b )
{
	mNodes[a].push_back(b);
}

map< int, bool > Graph::getVisitedNodes()
{
	map< int, vector<int> >::iterator it = mNodes.begin();
	map< int, bool > visited;
	while ( it!=mNodes.end() )
	{
		visited[it->first] = false;
		it++;
	}	

	return visited;
}

void Graph::BFS( int start )
{
	map< int, bool > visited = getVisitedNodes();

	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		if (!visited[current])
		{
			cout << current << " ";
			visited[current] = true;

			vector<int> adj = mNodes[current];
			for (unsigned int i=0; i<adj.size(); i++)
			{
				if (!visited[adj[i]])
				{
					q.push(adj[i]);
				}
			}
		}
	}
	cout << endl;
}

map< int, bool > visitedDFS;
void Graph::DFS( int start )
{
	if (!visitedDFS[start])
	{
		visitedDFS[start] = true;
		vector<int> adj = mNodes[start];
		cout << start << " ";

		for (unsigned int i=0; i<adj.size(); i++)
		{
			if (!visitedDFS[adj[i]]) DFS(adj[i]);
		}
	}
}

int main()
{
	Graph graph;
	graph.addEdge(0,1);
	graph.addEdge(0,4);
	graph.addEdge(0,5);
	graph.addEdge(1,4);
	graph.addEdge(1,3);
	graph.addEdge(2,1);
	graph.addEdge(3,2);
	graph.addEdge(3,4);

	graph.BFS(0);

	visitedDFS = graph.getVisitedNodes();
	graph.DFS(0);
	cout << endl;

	return 0;
}