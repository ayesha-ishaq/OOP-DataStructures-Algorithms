#include <iostream>
#include <cstring>
#include <fstream>
#include "linkedlist.h"
using namespace std;

int main()
{
	LinkedList<Person> list;
	Person p;
	fstream infile;
	infile.open("Assig01-person-data.txt",ios::in);
	while(!infile.eof())
	{
		p.setFName(infile);
		p.setLName(infile);
		p.setNo(infile);
		p.setEmail(infile);
		list.Append(p);
	}
	int oper;
	cout<<"\nPlease choose and option: ";
	cout<<"\n1)Find person's data\n2)Append new person\n3)Delete person's data\n4)Display all data\n5)Sort data\n6)Quit\n";
	cin>>oper;
	
	while(oper!=6)
	{
		if(oper==1)
		{
			string temp;
			cout<<"\nEnter first name of person to search: "; cin>>temp;
			list.returnSearch(temp);
		}
		if(oper==2)
		{
			Person p; string temp;
			cout<<"\nEnter first name: "; cin>>temp; p.setFirstName(temp);
			cout<<"\nEnter last name: "; cin>>temp; p.setLastName(temp);
			cout<<"\nEnter telephone number: "; cin>>temp; p.setTelNo(temp);
			cout<<"\nEnter email: "; cin>>temp; p.setemail(temp);
			list.Append(p);
		}
		if(oper==3)
		{
			string temp;
			cout<<"\nEnter first name of person to be deleted: "; cin>>temp;
			cout<<"Present nodes: "<<list.getCount();
			list.deleteValue(temp);
			cout<<endl<<"After deletion: "<<list.getCount();
		}
		if(oper==4)
		{
			list.DisplayAll();
		}
		if(oper==5)
		{
			list.bubbleSort();
		}
		cout<<"\n\nPlease choose and option: ";
		cout<<"\n1)Find person's data\n2)Append new person\n3)Delete person's data\n4)Display all data\n5)Sort data\n6)Quit\n";
		cin>>oper;
	}
	
	fstream outfile;
	outfile.open("Assig01-person-data.txt",ios::out);
	list.writeToFile(outfile);
}
