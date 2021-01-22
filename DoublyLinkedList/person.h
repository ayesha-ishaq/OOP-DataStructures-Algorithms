#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class Person {
	
	string firstname;
	string lastname;
	string telephone;
	string email;
	
	public:
/*	Person()
	{	
		strcpy(firstname,"");
		strcpy(lastname,"0");
		strcpy(telephone,"0");
		strcpy(email,"0");
	}*/
	void setFName(fstream &fin);
	void setLName(fstream &fin);
	void setNo(fstream &fin);
	void setEmail(fstream &fin);
	void setFirstName(string &info);
	void setLastName(string &info);
	void setTelNo(string &info);
	void setemail(string &info);
	void Display();
	string getFName();
	string getLName();
	string getNo();
	string getEmail();
	friend void operator<<(ostream &out, Person p);
	
};

void Person::setFName(fstream &fin)
{
	fin>>firstname;
}
void Person::setLName(fstream &fin)
{
	fin>>lastname;
}
void Person::setNo(fstream &fin)
{
	fin>>telephone;
}
void Person::setEmail(fstream &fin)
{
	fin>>email;
}
void Person::setFirstName(string &info)
{
	firstname=info;
}
void Person::setLastName(string &info)
{
	lastname=info;
}
void Person::setTelNo(string &info)
{
	telephone=info;
}
void Person::setemail(string &info)
{
	email=info;
}
void Person::Display() 
{
	cout<<"\n"<<firstname<<" "<<lastname<<" "<<telephone<<" "<<email;
}
string Person::getFName()
{
	return firstname;
}
string Person::getLName()
{
	return lastname;
}
string Person::getNo()
{
	return telephone;
}
string Person::getEmail()
{
	return email;
}
void operator<<(ostream &out, Person p)
{
	cout<<p.getFName(); cout<<" "; cout<<p.getLName(); cout<<" "; cout<<p.getNo(); cout<<" "; cout<<p.getEmail(); cout<<endl;
}
