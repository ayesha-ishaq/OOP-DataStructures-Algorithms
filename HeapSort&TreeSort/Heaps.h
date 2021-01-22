//Ayesha Ishaq 18I0772 assignment 04
#include <iostream>
#include <string>
using namespace std;

class minheap{
	private:
		int *arr;
		int size;
		int count;
	public:
		minheap(int s)
		{
			size=++s;
			count=0;
			arr=new int[size];
			for(int i=0; i<size; i++)
			arr[i]=0;
		}
		bool heapfull()
		{
			if (count==(size-1))
			return true;
			return false;
		}
		void insert(int val)
		{
			if(heapfull())
			{
				cout<<"Heap is full.";
			}
			else
			{
			int i=++count;
			while(arr[i/2]>val&&i!=1)
			{
				arr[i]=arr[i/2];
				i=i/2;
			}
			arr[i]=val;
			}
		}
		void deletemin()
		{
			int i=1;
			while(i*2<count)
			{	if(arr[2*i]<arr[(2*i)+1])
				{
				arr[i]=arr[i*2];
				i=i*2;
				}
				else
				{
				arr[i]=arr[i*2+1];
				i=(i*2)+1;
				}
			}
			arr[i]=arr[count];
			arr[count]=0;
			count--;
		}
		void displayheap()
		{
			for(int i=1; i<=count; i++)
			{
				cout<<arr[i]<<" ";
			}
		}
		void minheapsort(int arr2[])
		{
			int size2=count;
			for(int i=0; i<size2; i++)
			{
				arr2[i]=arr[1];
				deletemin();
			}
		}
};

