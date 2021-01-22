#include <iostream>
#include <fstream>
#include <string>
#include "HashChain.h"

using namespace std;
struct element{
	string word;
	string details; 
};

int main()
{
	HashChain<element> table(7000);
	element key;
	string temp;
	ifstream infile;
	infile.open("dictionary.txt");
	while(!infile.eof())
	{
		getline(infile, temp);
		while(temp.empty()&&(!infile.eof()))
		getline(infile,temp);
		int pos= temp.find("  ");
		if(pos>0&&(temp.substr(0,pos)!="Usage"))
		{
			key.word=temp.substr(0,pos);
			key.details=temp.substr(pos+2, temp.size());
		}
		else
			key.details=(key.details+" ")+temp;
			
		table.insert(key);
		
		//cout<<"\nword: "<<key.word<<" meaning: "<<key.details;
	}
	
	cout<<"Enter a word to search: ";
	getline(cin,temp);
	if(!table.search(temp))
	cout<<"\nNot Found.";
	cout<<"\n\n"<<"LOAD FACTOR: "<<((float)table.Keys()/table.nonemptyN());
	
	
}
