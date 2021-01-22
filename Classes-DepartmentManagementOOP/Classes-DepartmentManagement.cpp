#include <iostream>  //The first line from all the text files must be removed in order to take in data from the files successfully
#include <iomanip>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

// Department Management System

 class Address{
 	
 	int house;
 	int street;
 	char city[6];
 	
 	public:
 		Address()
 		{
 			house=0;
 			street=0;
 			city[0]=0;
		 }
 		void setAdd(fstream &fin);
 		int rHouse();
 		int rStreet();
 		char* rCity();
 }; 
void Address::setAdd(fstream &fin)
{
 	fin>>house;	fin>>street; fin>>city;
}
int Address::rHouse()
{
 	return house;
}
int Address::rStreet()
{
 	return street;
}
char* Address::rCity()
{
 	return city;
}

class Person{
	
	char name[20];
	char CNIC[20];
	char contact[20];
	Address A;
	
	public:
	Person()
	{	
		name[0]=0;
		CNIC[0]=0;
		contact[0]=0;
	}
	void setName(fstream &fin);
	void setCNIC(fstream &fin);
	void setContact(fstream &fin);
	void setAdd(fstream &fin);
	char* getName();
	char* getCNIC();
	char* getContact();
	int getHouse();
	int getStreet();
	char* getCity();	
};

void Person::setName(fstream &fin)
{
	fin>>name;
}
void Person::setCNIC(fstream &fin)
{
	fin>>CNIC;
}
void Person::setContact(fstream &fin)
{
	fin>>contact;
}
void Person::setAdd(fstream &fin)
{
	A.setAdd(fin);
}
char* Person::getName()
{
	return name;
}
char* Person::getCNIC()
{
	return CNIC;
}
char* Person::getContact()
{
	return contact;
}
int Person::getHouse()
{
	return A.rHouse();
}
int Person::getStreet()
{
	return A.rStreet();
}
char* Person::getCity()
{
	return A.rCity();
}
class Student: public Person
{	
	int rollNo;
	float CGPA;
	char prog[3];
	char code[4][6];
	
	public:
		Student ()
		{
			rollNo=0;
			CGPA=0;
			prog[0]=0;
			for(int i=0;i<4;i++)
			{
				code[i][0]=0;
			}
		}
		void setStudentInfo(fstream &fin, fstream &in);
		void setStudentCourse(char*,int);
 		int getRollNo();
 		float getCPGA();
 		char* getprog();
		void DisplayStudent();	
		char* getStudentCourses(int i);
};

void Student::setStudentInfo(fstream &fin, fstream &in)
{
	setName(fin);
	setCNIC(fin);
	fin>>rollNo;
	fin>>CGPA;
	fin>>prog;
	setContact(fin);
	setAdd(in);
}

int Student::getRollNo()
{
	return rollNo;
}
float Student::getCPGA()
{
	return CGPA;
}
char* Student::getprog()
{
	return prog;
}
char* Student::getStudentCourses(int i)
{
	return code[i];
}
void Student::setStudentCourse(char* c, int i)
{
	strcpy(code[i],c);
}
void Student::DisplayStudent()
{
	cout<<setw(12)<<left<<getName()<<setw(20)<<getCNIC()<<setw(8);
	cout<<rollNo<<setw(5)<<CGPA<<setw(5)<<prog<<setw(20);
	cout<<getContact()<<setw(8)<<getCity();
}
class Faculty: public Person
{	
	int EmpID;
	char Des[12];
	char JoinD[12];
	char code[2][6];
	
	public:
		Faculty()
		{
			EmpID=0;
			Des[0]=0;
			JoinD[0]=0;
			for(int i=0;i<2;i++)
			{
				code[i][0]=0;
			}
		}
		void setFacultyInfo(fstream &fin, fstream &in);
 		int getEmpID();
 		char* getDesig();
 		char* getJoinD();
 		char* getFacultyCourses(int i);
		void DisplayFaculty();
		void setFacultyCourses(char*,int i);	
};

void Faculty::setFacultyInfo(fstream &fin,fstream &in)
{
	setName(fin);
	setCNIC(fin);
	fin>>EmpID;
	fin>>Des;
	setContact(fin);
	fin>>JoinD;
	setAdd(in);
}
void Faculty::setFacultyCourses(char* c, int i)
{
	strcpy(code[i],c);
}
char* Faculty::getFacultyCourses(int i)
{
	return code[i];
}
int Faculty::getEmpID()
{
	return EmpID;
}
char* Faculty::getDesig()
{
	return Des;
}
char* Faculty::getJoinD()
{
	return JoinD;
}
void Faculty::DisplayFaculty()
{
	cout<<setw(10)<<left<<getName()<<setw(16)<<getCNIC()<<setw(6);
	cout<<EmpID<<setw(10)<<Des<<setw(11)<<JoinD<<setw(20);
	cout<<getContact()<<setw(8)<<getCity();
}
class Course
{
	
	char title[40];
	char code[6];
	int CrHrs;
	char Stream[15];
	int room;
	
	public: 
		Course()
		{
			title[0]=0;
			code[0]=0;
			CrHrs=0;
			Stream[0]=0;
			room=0;
		}
		void setCourseInfo(fstream &fin);
		void setRoom(int);
		char* getTitle();
		char* getCode();
		int getCrHrs();
		char* getStream();
		int getRoom();
};

void Course::setCourseInfo(fstream &fin)
{
	fin.getline(code,6 ,'\t');
	fin.getline(title,40 ,'\t');
	fin>>CrHrs;
	fin.getline(Stream,15);
}
void Course::setRoom(int i)
{
	room=i;
}
char* Course::getTitle()
{
	return title;
}
char* Course::getCode()
{
	return code;
}
int Course::getCrHrs()
{
	return CrHrs;
}
char* Course::getStream()
{
	return Stream;
}
int Course::getRoom()
{
	return room;
}
class Classroom
{
	int roomNo;
	char Floor;
	int Cap; //Capacity
	
	public:
		Classroom()
		{
			roomNo=0;
			Floor=0;
			Cap=0;
		}
		void setRoomInfo(fstream &fin);
		int getRoomNo();
		char getFloor();
		int getCapacity();
		void DisplayRoomInfo();
};

void Classroom::setRoomInfo(fstream &fin)
{
	fin>>roomNo;
	fin>>Floor;
	fin>>Cap;
}
int Classroom::getRoomNo()
{
	return roomNo;
}
char Classroom::getFloor()
{
	return Floor;
}
int Classroom::getCapacity()
{
	return Cap;	
}
void Classroom::DisplayRoomInfo()
{
	cout<<setw(5)<<left<<roomNo<<Floor<<" "<<Cap;	
}	
int main()
{
	Student studs[450]; 
	Faculty empls[50];
	Classroom rooms[12];
	Course crs[40];
	
	fstream fin, in;
	fin.open("Student.txt",ios::in);
	in.open("Address.txt",ios::in);
	int i=0;
	while(!fin.eof()&&!in.eof()&&i<450)
	{
		studs[i].setStudentInfo(fin,in);
		++i;
	}
	i=0;
	fin.close(); in.close();
	fin.open("Faculty.txt",ios::in);
	in.open("Address.txt",ios::in);
	while(!fin.eof()&&i<50)
	{
		empls[i].setFacultyInfo(fin,in);
		++i;
	}
	fin.close(); in.close();
	fin.open("Courses.txt",ios::in);
	i=0;
	while(!fin.eof()&&i<40)
	{
		crs[i].setCourseInfo(fin);
		++i;
	}
	fin.close();
	fin.open("Rooms.txt",ios::in);
	i=0;
	while(!fin.eof()&&i<10)
	{
		rooms[i].setRoomInfo(fin);
		++i;
	}
	//assignment of courses to student
	int st=0; int k=1;
	for(int cr=0; cr<10; cr++)
	{
		int m=4*cr; 
		for(st;st<(k*45);st++)
		{
			
			for(int j=0; j<4; j++)
			studs[st].setStudentCourse((crs[m++].getCode()),j);
			
			m=4*cr;
		}
		
		k++;
	}
	//Random assignment of courses to faculty
	st=0; k=1; int m=0;
	for(int cr=0; cr<10; cr++)
	{
	 	
		for(st;st<k*5;st++)
		{
			
			for(int j=0; j<2; j++)
			empls[st].setFacultyCourses((crs[m++].getCode()),j);
			
		}
		m-=8;
		k++;
	}
	//assignment of rooms to courses
	st=0; k=1;
	for(int cr=0; cr<10; cr++)
	{
	 	for(st;st<k*4;st++)
		{
			crs[st].setRoom(rooms[cr].getRoomNo());	
		}
		k++;
	}
	cout<<"Please select an option:\n1.Print Students list from a specific city.\n";
	cout<<"2.Print courses taken by a Student.\n3.Print courses being taught by a faculty.\n";
	cout<<"4.Print students enrolled in a course.\n5.Print all Students' information\n6.Print all Faculty's information\nOr 'Q' to quit.";
	char oper; cin>>oper;
	cout<<endl<<endl;
	
	while(oper!='q')
		{
			
		 if(oper=='1')	
		 {
			cout<<"Enter a city to search students: ";
			char city[6];
			cin>>city;
			for(int i=0; i<450; i++)
			{
				if(strcmpi(city,(studs[i].getCity()))==0)
				{
					studs[i].DisplayStudent();
					cout<<endl;
				}
			}
		}
		
		else if(oper=='2')
		{
			cout<<"Enter Student's roll no. to view subjects taken: ";
			int roll;
			cin>>roll;
			for(int i=0; i<450; i++)
			{
				if(studs[i].getRollNo()==roll)
				{
					cout<<"\nStudent name: "<<studs[i].getName()<<endl<<endl;
					for(int j=0; j<4; j++)
					{
						for(int o=0;o<40;o++)
						{
							if(strcmp((studs[i].getStudentCourses(j)),(crs[o].getCode()))==0)
							{
								cout<<crs[o].getTitle();
								cout<<endl;
							}
						}
						
					}
					break;
				}
			}
		}
		
		else if(oper=='3')
		{
			cout<<"Enter employ ID to view courses taught: ";
			int eID;
			cin>>eID;
		
			for(int i=0; i<50; i++)
			{
				if(empls[i].getEmpID()==eID)
				{
					cout<<"\nEmploy name: "<<empls[i].getName()<<endl<<endl;
					for(int j=0; j<2; j++)
					{
						for(int o=0;o<40;o++)
						{
							if(strcmp((empls[i].getFacultyCourses(j)),(crs[o].getCode()))==0)
							{
								cout<<crs[o].getTitle();
								cout<<endl;
							}
						}
						
					}
					break;
				}
			}
		}
		
		else if(oper=='4')
		{
			cout<<"Enter course code to list students enrolled: ";
			char cc[6];
			cin>>cc;
			for(int o=0;o<40;o++)
				{
					if(strcmpi(cc,(crs[o].getCode()))==0)
						{
							cout<<endl<<crs[o].getTitle();
							cout<<endl<<endl;
						}
				}
			cout<<setw(12)<<left<<"Name"<<setw(6)<<"Roll No."<<endl;
			for(int i=0; i<450; i++)
			{
				for(int j=0; j<4; j++)
					{
						if(strcmpi((studs[i].getStudentCourses(j)),cc)==0)
							{
								cout<<setw(12)<<left<<studs[i].getName()<<setw(6)<<studs[i].getRollNo();
								cout<<endl;
							}
					}	
			}
		}
		
		else if(oper=='5')
		{
			for(int x=0;x<450;x++)
			{
				studs[x].DisplayStudent();
				cout<<endl;
			}
		}
		
		else if(oper=='6')
		{
			for(int x=0;x<50;x++)
			{
				empls[x].DisplayFaculty();
				cout<<endl;
			}
		}
		
		else
		{
			cout<<"Incorrect Data"<<endl;
		}
		cout<<endl<<endl;
		cout<<"Please select an option again:\n1.Print Students list from a specific city.\n";
		cout<<"2.Print courses taken by a Student.\n3.Print courses being taught by a faculty.\n";
		cout<<"4.Print students enrolled in a course.\n5.Print all Students' information\n6.Print all Faculty's information\nOr 'Q' to quit.";
		cin>>oper;
		cout<<endl<<endl;
	
	}

}
