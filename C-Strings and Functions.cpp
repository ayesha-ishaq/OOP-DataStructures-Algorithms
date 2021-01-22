//Ayesha Ishaq 18I-0772 
#include<iostream>
using namespace std;

bool strchrb(char arr[], char letter);
int strcmp(char arr1[], char arr2[]);
int strcmpi(char arr1[], char arr2[]);
void strcat(char arr1[], char arr2[]);
void strrev(char arr[]);
bool strpal(char arr[]);
void strenc(char arr[]);
void strdec(char arr[]);

int main()
{
	char array1[20] = "Some Text Here";
	char array2[20] = "Some Text Here";
	char array3[20] = "More Text Here";
	char array4[20] = "more text here";
	char array5[20] = "tibit";
	char array6[20] = "alaska";
	char arrayCode[30] = "this is a secret message";

	if (strchrb(array1, 'S'))
		cout << "S is present in array1 but ";
	if (!strchrb(array3, 'S'))
		cout << "S isn't present in array3" << endl;

	if (strcmp(array1, array2) == 0)
		cout << "array1 and array2 are the same." << endl;
	if (strcmp(array2, array3) != 0)
		cout << "array2 and array3 aren't the same." << endl;

	if (strcmp(array3, array4) != 0)
		cout << "array3 and array4 aren't the same. (sessitive case)" << endl;
	if (strcmpi(array3, array4) == 0)
		cout << "array3 and array4 are the same. (insessitive case)" << endl;

	strcat(array2, array3);
	cout << "After Concatenating : " << array2 << endl;

	strrev(array2);
	cout << "After reversal : " << array2 << endl;

	if (strpal(array5))
		cout << "tibit is palindrome." << endl;
	if (!strpal(array6))
		cout << "but alaska is not palindrome." << endl;
	//--- You can add lines below for bonus part.---
	strenc(arrayCode);
	cout<<arrayCode<<endl;
	strdec(arrayCode);
	cout<<arrayCode;


}

//-------------------Write your code below------------------------
bool strchrb(char arr[], char letter)
{
	bool present=false;
	for(int i=0;arr[i]!=0;i++)
	{
			if(arr[i]==letter||arr[i]==letter-32||arr[i]==letter+32)
			present=true;
	}
	return present;
}
int strcmp(char arr1[], char arr2[])
{	
	for(int i=0;arr1[i]!=0&&arr2[i]!=0;i++)
	{
		if(arr1[i]>arr2[i])
			return 1;
		else if(arr1[i]<arr2[i])
			return -1;
	}
	return 0;
}
int strcmpi(char arr1[], char arr2[])
{	char temp1, temp2;
	for(int i=0;arr1[i]!=0&&arr2[i]!=0;i++)
	{	temp1=arr1[i]; temp2=arr2[i];
		if(temp1>='A'&&temp1<='Z')
	 	temp1+=32;
	 	if(temp2>='A'&&temp2<='Z')
	 	temp2+=32;
		if(temp1>temp2)
			return 1;
		else if(temp1<temp2)
			return -1;
	}
	return 0;
}
void strcat(char arr1[], char arr2[])
{
		int i;
	for (i = 0; arr1[i] != 0; i++);
	for (int j = 0; arr2[j] != 0; j++)
			arr1[i++] = arr2[j];
	arr1[i] = 0;
}
void strrev(char arr[])
{
	int len;
	for (len=0;arr[len]!=0;len++);
	for(int i=0;i<len/2;i++)
	{
		char temp=arr[i];
		arr[i]=arr[len-i-1];
		arr[len-i-1]=temp;
	}
}
bool strpal(char arr[])
{
	bool pal=false;
	int len;
	for (len=0;arr[len]!=0;len++);
	for(int i=0;i<len/2;i++)
	{
		if(arr[i]==arr[len-i-1])
		pal=true;
		else 
		pal=false;
	}
	return pal;
}
void strenc(char arr[])
{
	for(int i=0;arr[i]!=0;i++)
	{	
		if((arr[i]>='a'&&arr[i]<='m')||(arr[i]>='A'&&arr[i]<='M'))
		{
			arr[i]=arr[i]+13;
		}
		else if((arr[i]>'m'&&arr[i]<='z')||(arr[i]>'M'&&arr[i]<='z'))
		{
			arr[i]=arr[i]-13;
		}
	}
}
void strdec(char arr[])
{
		for(int i=0;arr[i]!=0;i++)
	{	
		if((arr[i]>='a'&&arr[i]<='m')||(arr[i]>='A'&&arr[i]<='M'))
		{
			arr[i]=arr[i]+13;
		}
		else if((arr[i]>'m'&&arr[i]<='z')||(arr[i]>'M'&&arr[i]<='z'))
		{
			arr[i]=arr[i]-13;
		}
	}
}
