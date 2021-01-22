//Ayesha Ishaq 18I-0772
#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
	weightedGraph graph;
	char oper;
	cout<<"SHORTEST PATH WITH DIJKSTRA AND FLOYD WARSHELL\n\n";
	graph.creategraph();
	graph.FloydWarshell();
	cout<<"\nNo of vertices: "<<graph.graphSize();
	cout<<"\nTo find shortest path between two vertices press A, to quit press Q";
	cin>>oper;
	while(oper!='q')
	{
		int ver, des;
		cout<<"\nEnter vertex and destination: ";
		cin>>ver>>des;
		graph.dijkstra(ver);
		cout<<"\n\nPath and cost as calculated by Dijkstra:\n";
		graph.printShortestDistance(ver,des);
		graph.printShortestPath(ver,des);
		cout<<"\n\nPath and cost as calculated by Floyd Warshell:\n";
		graph.printFloydDistance(ver,des);
		graph.printFloydPath(ver,des);
		cout<<"\n\nTo find shortest path between two vertices press A, to quit press Q";
		cin>>oper;
	}
	

}
