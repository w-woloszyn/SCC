#include<iostream>
#include<string>
#include<sstream>
#include<list>
#include<vector>

using namespace std;

vector< list<int> > ReverseGraph(vector< list<int> >& G, int n)
{
	vector< list<int> > Gt(n);
	for (int i = 0; i < n; i++)
		for (list<int>::iterator it = G[i].begin(); it != G[i].end(); it++)
		{
			Gt[*it].push_back(i);
		}

	return Gt;
}

void FirstDFS(vector< list<int> >& G, vector<int>& F, vector<bool>& E, int start, int& nodes_processed)
{
	E[start] = true;
	for (list<int>::iterator it = G[start].begin(); it != G[start].end(); it++)
	{
		if (E[*it] == false)
		{
			FirstDFS(G, F, E, *it, nodes_processed);
		}
	}
	
	nodes_processed++;
	F[start] = nodes_processed;
}

void FirstDFSLoop(vector< list<int> >& G, vector<int>& F, vector<bool>& E, int n)
{
	int nodes_processed = 0;
	for (int start = n - 1; start >= 0; start--)
	{
		if (E[start] == false)
		{
			FirstDFS(G, F, E, start, nodes_processed);
		}
	}
}

void SCC(vector< list<int> >& G)
{
	int n = G.size();
	vector<int> Leaders(n);
	vector<int> Finish(n);
	vector<bool> Explored(n, false);
	vector< list<int> > Grev = ReverseGraph(G, n);
	
	FirstDFSLoop(Grev, Finish, Explored, n);
	int stop = 0;
}

int main()
{
	int n; // n is the number of vertices
	string line; // for buffering
	int tail; // for buffering
	int head;

	cin >> n;
	cin.ignore();

	vector< list<int> > graph(n);

	while (getline(cin, line))
	{
		stringstream stream;
		stream << line;
		stream >> tail;
		stream >> head;
		tail--; // becase C counts from 0
		head--; //beacause C countrs from 0
		graph[tail].push_back(head);
	}

	SCC(graph);

	return 0;
}