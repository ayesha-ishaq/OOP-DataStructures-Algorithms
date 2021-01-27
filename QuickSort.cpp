#include <iostream>
#include <fstream>
using namespace std;


int partition(int arr[], int l, int r)
{
	int piv=arr[l];
	int i=l, j=r;
	while(i<j)
	{
		while(arr[i]<=piv&&i<r)
		i++;
		while(arr[j]>piv)
		j--;
		
		if(i<j)
		{
	
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	arr[l]=arr[j];
	arr[j]=piv;
	
	return j;
}
void QuickSort(int arr[], int l, int r)
{
	if(l<r)
	{
		int j=partition(arr,l,r);
		QuickSort(arr,l,j-1);
		QuickSort(arr,j+1,r);
	}
}

int main()
{
	ifstream fin;
	fin.open("text.txt");
	int array[20];
	int i=0;
	if(!fin)
	cout<<"FILE NOT OPEN";
	while(!fin.eof())
	{
		fin>>array[i];
		i++;
	}
	
	QuickSort(array,0,(i-1));
		
	for(int k=0; k<i; k++)
	cout<<array[k]<<" ";
}
