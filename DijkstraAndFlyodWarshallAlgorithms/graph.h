//Ayesha Ishaq 18I-0772
#include <iostream>
#include <fstream>
#include <string>
#include <cfloat>
#include <stack>
using namespace std;
class weightedGraph
{
	private:
	double **weightMat;
	double *smallestWeight;
	int size;
	double *path;
	double **distF;
	int **pathF;
		
	public:
		weightedGraph()
		{
			weightMat=NULL;
			smallestWeight=NULL;
			path=NULL;
			pathF=NULL;
			distF=NULL;
			size=0;
		}
		void creategraph()
		{
			int vertex;
			int adjver;
			int weight;
			string name;
			cout<<"Enter file name: ";
			cin>>name;
			ifstream fin;
			fin.open(name.c_str());
			if(!fin)
			cout<<"file not open";
			fin>>size;
	        weightMat=new double*[size];
	        path=new double[size];
			smallestWeight=new double[size];
	        for(int i=0; i<size; i++)
	        {
	        	weightMat[i]=new double[size];
	        	
			}
			for(int i=0;i<size;i++)
				for(int j=0;j<size;j++)
				{
					if(i!=j)
					weightMat[i][j]=DBL_MAX;
				}
			for(int i=0; i<size; i++)
			{
				fin>>vertex;
				fin>>adjver;
				while(adjver!=-999)
				{
					fin>>weight;
					weightMat[vertex][adjver]=weight;
					fin>>adjver;
				}
			}
		}
		void dijkstra(int vertex)
		{
		
			for (int j = 0; j < size; j++)
				{
					smallestWeight[j] = weightMat[vertex][j];
					if (vertex == j)
					path[j] = 0;
					else if (smallestWeight[j] == DBL_MAX)
					path[j] = -1;
					else
					path[j] = vertex;
				}
			bool *weightFound;
			weightFound = new bool[size];
			for (int j = 0; j < size; j++)
				weightFound[j] = false;
			weightFound[vertex] = true;
			smallestWeight[vertex] = 0;
			path[vertex]=0;
			for (int i = 0; i < size - 1; i++)
			{
				double minWeight = DBL_MAX;
				int v;
				for (int j = 0; j < size; j++)
					if (!weightFound[j])
						if (smallestWeight[j] < minWeight)
						{
							v = j;
							minWeight = smallestWeight[v];
						}
				weightFound[v] = true;
				for (int j = 0; j < size; j++)
					if (!weightFound[j])
						if (minWeight + weightMat[v][j] < smallestWeight[j])
						{
							path[j]=v;
							smallestWeight[j] = minWeight + weightMat[v][j];
						}
			} 
		
				
		}	 

		void printShortestDistance(int vertex, int des)
       	{
			cout << "\nSmallest cost from "<<vertex<<" to "<<des<< endl;
				if(vertex==des)
				cout<<"No Cost";
				else if(smallestWeight[des]==DBL_MAX)
				cout<<"Infinite";
				else
				cout <<smallestWeight[des];
				cout<<endl;
		}		
		void printShortestPath(int vertex, int des)
		{
			if(path[des]!=-1)
			{
			int x=des;
			stack<int> s;
			while(x!=vertex)
			{
				s.push(x);
				x=path[x];
			}
			cout<<"\nShortest path from "<<vertex<<" to "<<des;
			cout<<endl<<vertex;
			while(!s.empty())
			{
				cout<<"->"<<s.top();
				s.pop();
			}
			}
			else
			cout<<"No path from "<<vertex<<" to "<<des;
			cout<<endl;
		}
	void printFloydDistance(int vertex, int des)
	{
		cout<<"\nSmallest cost by Floyd from "<<vertex<<" to "<<des<<endl;
		if(vertex==des)
		cout<<"No cost";
		else if(distF[vertex][des]==DBL_MAX)
		cout<<"Infinite";
		else
		cout<<distF[vertex][des];
		cout<<endl;
	}
	void printFloydPath(int vertex, int des)
	{
		if (des!= vertex && pathF[vertex][des] != -1) 
		{
			int x=des;
			stack<int> s;
			while(x!=vertex)
			{
				s.push(x);
				x=pathF[vertex][x];
			}
			cout<<"\nShortest path from "<<vertex<<" to "<<des;
			cout<<endl<<vertex;
			while(!s.empty())
			{
				cout<<"->"<<s.top();
				s.pop();
			}
		}
		else
		cout<<"No path between "<<vertex<<" and "<<des;
		
		cout<<endl;
	}

	
	void FloydWarshell()
	{
		distF=new double*[size];
		pathF=new int*[size];
		for(int i=0;i<size;i++)
		{
			distF[i]=new double[size];
			pathF[i]=new int[size];
		}
		for (int v = 0; v < size; v++) 
		{
			for (int u = 0; u < size; u++) 
			{
				distF[v][u] = weightMat[v][u];
				if (v == u)
					pathF[v][u] = 0;
				else if (distF[v][u] == DBL_MAX)
					pathF[v][u] = -1;
				else
					pathF[v][u] = v;
			}
		}
		for (int k = 0; k < size; k++) 
		{
			for (int v = 0; v < size; v++) 
			{
				for (int u = 0; u < size; u++) 
				{
					if (distF[v][k]!=DBL_MAX&&distF[k][u]!=DBL_MAX&&distF[v][k] + distF[k][u] < distF[v][u]) 
					{
						distF[v][u] = distF[v][k] + distF[k][u];
						pathF[v][u] = pathF[k][u];
					}
				}
			}
		}

	}
		~weightedGraph()
		{
			for (int i=0; i < size; i++)
				delete [] weightMat[i];
			delete [] weightMat;
			delete smallestWeight;
			for (int i=0; i < size; i++)
				delete [] pathF[i];
			for (int i=0; i < size; i++)
				delete [] distF[i];
		}
	int graphSize()
	{
		return size;
	}
	void print()
	{
		for(int i=0; i<size; i++)
		{
			for(int j=0; j<size; j++)
				{
					if(weightMat[i][j]!=DBL_MAX&&i!=j)
					cout<<"("<<i<<","<<j<<")"<<" ";
				}
				cout<<endl;
		}
	}
};
