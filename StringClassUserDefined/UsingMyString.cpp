#include <iostream>
#include "mystring.h"

using namespace std;

int main()
{

    char arr1[30],arr2[30];
    cout<<"Enter first string: ";
    cin.getline(arr1,30);
    cout<<"Enter second string: ";
    cin.getline(arr2,30);

    mystring s1(arr1);    //parametrized constructor
    mystring s2(arr2);    //parametrized constructor

    cout<<"Length of s1:"<<s1.length()<<endl;
    cout<<"Length of s2:"<<s2.length()<<endl;

    cout<<"s1+s2 : "<<s1+s2;
	cout<<endl;  // + and << operator overloaded

    if(s1<s2)           // < operator overloaded
        cout<<"s1 < s2"<<endl;
    else if(s1>s2)      // > operator overloaded
        cout<<"s1 > s2"<<endl;
    else if(s1==s2)     // == operator overloaded
        cout<<"s1 == s2"<<endl;
    s1.swap(s2);
    cout<<"After swapping\ns1 = "<<s1; cout<<"\ns2 = "<<s2; cout<<endl;

    cout<<"Individual elements of s1 are\n";
    for(int i=0;i<s1.length();i++)
        cout<<"s1["<<i<<"]= "<<s1[i]<<endl;         // [ ] operator overloaded

    return 0;
}
