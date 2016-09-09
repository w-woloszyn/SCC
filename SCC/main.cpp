#include<iostream>
#include<string>
#include<sstream>
#include<list>
#include<vector>
using namespace std;

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

	return 0;
}