#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin;
	fin.open("text.txt");
	int array[20];
	int i=0;
	while(!fin.eof())
	{
		fin>>array[i];
		i++;
	}
	
	for(int k=1; k<i; k++)
	{
		for(int j=0; j<i-k; j++)
		{
			if(array[j]>array[j+1])
			{
				int temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
	
	for(int k=0; k<i; k++)
	cout<<array[k]<<" ";
}
