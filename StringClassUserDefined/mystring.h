//Ayesha Ishaq
//Roll no. 18I-0772
#include <cstring>
#include <iostream>
using namespace std;

/*Changed string to mystring in main where s1 and s2 are declared
and where << (cout) operator overload is used, terminated it with ;
and added cout before endl; */

class mystring //named the class mystring because when named string, including cstring gives the error "reference to string is ambiguous" 
{
	private:
		char *arr=new char[200];
		
	public:
		mystring()
		{
			arr[0]=0;
		}
		mystring(char* str)
		{
			strcpy(arr,str);
		}
		int length();
		void swap(mystring&);
		mystring operator+(mystring);
		bool operator<(mystring);
		bool operator>(mystring);
		bool operator==(mystring);
		char operator[](int);
		friend void operator<<(ostream& out, mystring);
		friend void operator>>(istream& in, mystring);	
};
int mystring::length()
{
	return (strlen(arr));
}
void mystring::swap(mystring& A)
{
	char *temp=new char[200];		
	strcpy(temp,(A.arr));
	strcpy((A.arr),arr);
	strcpy(arr,temp);
	delete [] temp;
}
mystring mystring::operator+(mystring A)
{
	char *temp=new char[200];
	strcpy(temp,arr);
	strcat(temp,(A.arr));
	return temp;
}
bool mystring::operator<(mystring A)
{
	if(strcmp(arr,(A.arr))==-1)
	return true;
	else
	return false;
}
bool mystring::operator> (mystring A)
{
	int *p=new int;
	*p=strcmp(arr,(A.arr));
	if((*p)== 1)
	return true;
	else
	return false;
}
bool mystring::operator==(mystring A)
{
	int *p=new int;
	*p=strcmpi(arr,(A.arr));
	if((*p)==0)
	return true;
	else
	return false;
}
char mystring::operator[](int i)
{
	return arr[i];	
}
void operator<<(ostream& out, mystring A) //requirement: when this opeator overload is used in main is should not be followed by << but should be terminated with ;
{
	cout<<(A.arr);
}
void operator>>(istream& in,mystring A) //requirement: when this opeator overload is used in main is should not be followed by >> but should be terminated with ;
{
	cin>>(A.arr);
}
