//Ayesha Ishaq 18I0772 assignment 04
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sys/time.h>
#include "BST.h"
#include "Heaps.h"
using namespace std;

int main()
{
	
	int arrtree[100031];
	int arrheap[100031];
	struct timeval stop, start;
    int seconds, micro_seconds, total_micro_seconds;
	for(int i=0; i<100031; i++)
	{
		arrtree[i]=0; arrheap[i]=0;
	}
	ifstream infile;
	int i=0, num;
	infile.open("100k numbers.txt");
	
	BST<int> tree;
	minheap heap(100031);
	
	while(!infile.eof())
	{
		infile>>num;
		tree.insert(num);
		heap.insert(num);
	}

	//TreeSort
    gettimeofday(&start, NULL);
    //sorting
    //--------------------------------
	tree.treesort(arrtree);

    //--------------------------------
    gettimeofday(&stop, NULL);
	
    seconds = stop.tv_sec - start.tv_sec;
    micro_seconds = stop.tv_usec - start.tv_usec;
    if (micro_seconds < 0)
        seconds -= 1;
    total_micro_seconds = (seconds * 1000000) + abs(micro_seconds);

    cout<<"\n Sorting with BST took "<< total_micro_seconds/1000.0<<" ms";
    
	//-----------------------------------------------------------
  //HeapSort
    struct timeval stop2, start2;
    int seconds2, micro_seconds2, total_micro_seconds2;
    gettimeofday(&start2, NULL);
    //sorting
    //--------------------------------
	heap.minheapsort(arrheap);

    //--------------------------------
    gettimeofday(&stop2, NULL);
	
    seconds2 = stop2.tv_sec - start2.tv_sec;
    micro_seconds2 = stop2.tv_usec - start2.tv_usec;
    if (micro_seconds2 < 0)
        seconds2 -= 1;
    total_micro_seconds2 = (seconds2 * 1000000) + abs(micro_seconds2);

    cout<<"\n Sorting with Heaps took "<< total_micro_seconds2/1000.0<<" ms";
    
    ofstream outfile;

    outfile.open("treesort.txt");
    while(i<100031)
    {
    	outfile<<arrtree[i++];
    	outfile<<endl;
	}
	outfile.close();

    i=0;
    outfile.open("heapsort.txt");
    while(i<100031)
    {
    	outfile<<arrheap[i++];
    	outfile<<endl;
	}
    return 0;
}
