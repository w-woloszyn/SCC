#include<iostream>
#include<string>
#include<sstream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

vector< list<int> > ReverseGraph(vector< list<int> >& G, int n)
{
	vector< list<int> > Grev(n);
	for (int i = 0; i < n; i++)
		for (list<int>::iterator it = G[i].begin(); it != G[i].end(); it++)
		{
			Grev[*it].push_back(i);
		}

	return Grev;
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
	F[nodes_processed] = start;
}

void FirstDFSLoop(vector< list<int> >& G, vector<int>& F, int n)
{
	vector<bool> Explored(n, false);
	int nodes_processed = -1;
	for (int start = n - 1; start >= 0; start--)
	{
		if (Explored[start] == false)
		{
			FirstDFS(G, F, Explored, start, nodes_processed);
		}
	}
}

void SecondDFS(vector< list<int> >& G, vector<int>& F, vector<bool>& E, vector<int>& L, int s, int node)
{
	E[node] = true;
	L[node] = s;
	for (list<int>::iterator it = G[node].begin(); it != G[node].end(); it++)
	{
		if (E[*it] == false)
		{
			SecondDFS(G, F, E, L, s, *it);
		}
	}
}

void SecondDFSLoop(vector< list<int> >& G, vector<int>& F, vector<int>& L, int n)
{
	vector<bool> Explored(n, false);
	int s;
	for (int i = n - 1; i >= 0; i--)
	{
		if (Explored[F[i]] == false)
		{
			s = F[i];
			SecondDFS(G, F, Explored, L, s, F[i]);
		}
	}
}

vector<int> SCC(vector< list<int> >& G)
{
	int n = G.size();
	vector<int> Leaders(n);
	vector<int> Finish(n);
	vector< list<int> > Grev = ReverseGraph(G, n);
	
	FirstDFSLoop(Grev, Finish, n);
	SecondDFSLoop(G, Finish, Leaders, n);
	
	vector<int> CountLeaders(n,0);

	for (int i = 0; i < n; i++)
	{
		CountLeaders[Leaders[i]]++;
	}
	
	sort(CountLeaders.begin(), CountLeaders.end());

	return CountLeaders;
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
	vector<int> scc_result;

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

	scc_result = SCC(graph);

	for (int i = n-1; i >= 0; i--)
	{
		if (scc_result[i] == 0)
		{
			break;
		}
		cout << scc_result[i]<<",";
	}

	return 0;
}