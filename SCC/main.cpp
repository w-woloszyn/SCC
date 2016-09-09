#include<iostream>
#include<string>
#include<sstream>
#include<list>
#include<vector>

using namespace std;

vector< list<int> > Reverse_Graph(vector< list<int> > G)
{
	int n = G.size();
	vector< list<int> > Gt(n);
	for (int i = 0; i < n; i++)
		for (list<int>::iterator it = G[i].begin(); it != G[i].end(); it++)
		{
			Gt[*it].push_back(i);
		}

	return Gt;
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
	vector< list<int> > graph_transposed;

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

	graph_transposed = Reverse_Graph(graph);

	return 0;
}