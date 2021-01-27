#include <iostream>
#include <fstream>
using namespace std;
void merge(int arr[],int l, int m, int r)
{
	int i, j ,k;
	int s1=(m-l)+1;
	int s2=r-m;
	int L[s1]; int R[s2];
	for(i=0; i<s1; i++)
	{
		L[i]=arr[l+i];
	}
	for(j=0; j<s2; j++)
	{
		R[j]=arr[m+1+j];
	}
	i=0; j=0; k=l;
	while(i<s1&&j<s2)
	{
		if(L[i]<R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	
	while(i<s1)
		arr[k++]=L[i++];
	while(j<s2)
		arr[k++]=R[j++];
	
}
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = (l+(r-1))/2;
		
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);

		merge(arr,l,m,r);
	}
}

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
	
	mergeSort(array,0,(i-1));
	
	for(int k=0; k<i; k++)
	cout<<array[k]<<" ";
}
