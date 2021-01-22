#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;
tm* mylocaltime(time_t* t);
void displayTMmembers(tm *timeinfo);
char* asctime (tm* timeptr);
int main()
{
	time_t rawtime;
	char com;
	struct tm *timeinfo;
	rawtime = time ( NULL );
	timeinfo = mylocaltime ( &rawtime );
	do
	{
		cout<<"Press T to view members of structure tm\nPress A to view in asctime format.\n";
		cin>>com;
	}
	while(com!='t'&&com!='a');
	if(com=='t')
	displayTMmembers(timeinfo);
	if(com=='a')
	cout << "\n\nThe current date/time is: "<< asctime (timeinfo);
	
}

tm* mylocaltime(time_t* t)
{ 
	struct tm *p=new tm;
	
	int years, leap, months, weeks, days, hours, mins, seconds, temp=0;
	
	years=(*t)/(365*24*60*60); 
	leap=years/4;
	
	days=(*t)/(24*60*60); //exact no. of days since 1st Jan 1970
	
	int k=0, u=1970;
	for(months=days;months>=0;temp++)
	{	
		if(k==0||k==2||k==4||k==6||k==7||k==9||k==11)
		months-=31;
		else if(k==3||k==5||k==8||k==10)
		months-=30;
		else if(k==1&&u%4!=0)
		months-=28;
		else if(k==1&&u%4==0)
		months-=29;
		k++;
		if(k==12)
		k=0;
		u++; //counting months for each year precisely;
	}
	months=temp-(years*12); //no. of months passed in current year
	
	weeks=days+3; //1st of Jan 1970 was a thursday +3 is sunday;
	
	hours=(*t)/(60*60);
	hours=hours-(((years*365)+leap)*24);  //hours passed from beginning of current year
	
	days=days-((years*365)+leap); //days passed from beginning of current year
	
	(*p).tm_yday=days; 
	
	mins=(*t)/60;
	mins=mins-(((years*365)+leap)*24*60); //mins passed since beginning of current year
	
	seconds=(*t)-(((years*365)+leap)*24*60*60); //seconds passed since beginning of current year
	
	int D=0, Y=1970+years;
	for(int i=1;i<months;i++)
	{
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
		D+=31;
		else if(i==4||i==6||i==9||i==11)
		D+=30;
		else if(i==2&&(Y%4)!=0)
		D+=28;
		else if(i==2&&(Y%4)==0)
		D+=29;	
	}
	
	days=days-D; //D represents exact days passed since beginning of current year; days are now days of current month;
	
	hours=(hours-((D*24)+(days*24)))+5; //exact hours passed since previous day 00:00
	
	mins=(mins-(D*24*60))-(((days*24)+hours-5)*60); //exact mins passed since previous hour
	
	seconds=((seconds-(D*24*60*60)))-(((days*24)+hours-5)*60*60)-(mins*60); //exact seconds passed since previous min
	
	if(hours>0&&hours<24)
	{
		days+=1; //days are updated if hours show that we're actually into a new day
		weeks=(weeks+1)%7; //week day found on basis of remainder where 0=sunday;
	}
	
	p->tm_sec=seconds;
	p->tm_min=mins;
	p->tm_hour=hours;
	p->tm_mday=days;
	p->tm_mon=months;
	p->tm_year=Y;
	p->tm_wday=weeks;
	
	return p;
}

char* asctime (tm* timeptr)
{ 
	char *arr= new char[50];	
	char temp[5]={0};
	int in;
	in=timeptr->tm_wday;
	switch (in)
	{
		case 0:
			strcpy(arr,"Sun ");
			break;
		case 1:
			strcpy(arr,"Mon ");
			break;
		case 2:
			strcpy(arr,"Tue ");
			break;
		case 3:
			strcpy(arr,"Wed ");
			break;
		case 4:
			strcpy(arr,"Thu ");
			break;
		case 5:
			strcpy(arr,"Fri ");
			break;
		case 6:
			strcpy(arr,"Sat");
			break;
	}
	
	in=timeptr->tm_mon;
	switch (in)
	{
		case 1:
			strcat(arr,"Jan ");
			break;
		case 2:
			strcat(arr,"Feb ");
			break;
		case 3:
			strcat(arr,"Mar ");
			break;
		case 4:
			strcat(arr,"Apr ");
			break;
		case 5:
			strcat(arr,"May ");
			break;
		case 6:
			strcat(arr,"June ");
			break;
		case 7:
			strcat(arr,"July ");
			break;
		case 8:
			strcat(arr,"Aug ");
			break;
		case 9:
			strcat(arr,"Sep ");
			break;
		case 10:
			strcat(arr,"Oct ");
			break;
		case 11:
			strcat(arr,"Nov ");
			break;
		case 12:
			strcat(arr,"Dec ");
			break;
	}
	
	in=timeptr->tm_mday;
	for(int i=1; i>=0; i--)
	{
		temp[i]=in%10+'0';
		in=in/10;
	}
	strcat(arr,temp); strcat(arr," ");

	in=timeptr->tm_hour;
	for(int i=1; i>=0; i--)
	{
		temp[i]=in%10+'0';
		in=in/10;
	}
	strcat(arr,temp); strcat(arr,":");
	
	in=timeptr->tm_min;
	for(int i=1; i>=0; i--)
	{
		temp[i]=in%10+'0';
		in=in/10;
	}
	strcat(arr,temp); strcat(arr,":");
	
	in=timeptr->tm_sec;
	for(int i=1; i>=0; i--)
	{
		temp[i]=in%10+'0';
		in=in/10;
	}
	strcat(arr,temp); strcat(arr," ");

	in=timeptr->tm_year;
	for(int i=3; i>=0; i--)
	{
		temp[i]=in%10+'0';
		in=in/10;
	}

	strcat(arr,temp); 
	
	return arr;
}

void displayTMmembers(tm *timeinfo)
{
	cout<<"\nStructure tm's memebers:\n";
    cout<<"\n    tm_sec: "<<timeinfo->tm_sec;
	cout<<"    tm_min: "<< timeinfo->tm_min;
	cout<<"    tm_hour: "<< timeinfo->tm_hour<<endl<<endl;
	cout<<"    tm_mday: "<<timeinfo->tm_mday;
	cout<<"    tm_mon: "<< timeinfo->tm_mon;
	cout<<"    tm_year: " << timeinfo->tm_year<<endl<<endl;
	cout<<"    tm_wday: "<< timeinfo->tm_wday;
	cout<<"    tm_yday: "<< timeinfo->tm_yday<<endl;
}
