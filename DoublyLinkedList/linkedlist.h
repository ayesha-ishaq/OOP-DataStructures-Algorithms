#include <iostream>
#include "person.h"
using namespace std;

template <class T>
class LinkedList{
	
	private:
		struct nodeType{
			T info;
			nodeType *next;
			nodeType *prev;
		};
		
		nodeType *head;
		nodeType *tail;
		int count;
		
	public:
		LinkedList()
		{
			head=NULL;
			tail=NULL;
			count=0;
		}
		~LinkedList()
		{
			nodeType *d=head;
			while(head!=NULL)
			{
				d=d->next;
				delete head;
				head=d;
			}
		}
		nodeType* gethead()
		{
			return head;
		}
		nodeType* getTail()
		{
			return tail;
		}
		int getCount()
		{
			return count;
		}
		void DisplayAll()
		{
			nodeType *ptr=head;
			while(ptr!=NULL)
			{
				cout<<ptr->info;
				ptr=ptr->next;
			}
		}
		void Append(T &data)
		{
				nodeType *ptr=new nodeType;
				ptr->next=NULL;
				ptr->prev=tail;
				ptr->info=data;

				if(head==NULL)
				{
					head=ptr;
					tail=ptr;
				}
				else 
				{
						tail->next=ptr;
						tail=ptr;
				}
				
				count++;
		}

		void deleteValue(string &name)
		{
			nodeType *curr=head;
			string s1=head->info.getFName();
			if(head==NULL)
			{
				cout<<"Empty List.";
			}
			else if(name==s1)
			{
				head=head->next;
				head->prev=NULL;
				delete curr;
			}
			else 
			{
				while(name!=s1 && curr!=NULL)
				{
					curr=curr->next;
					s1=curr->info.getFName();
				}
				if(curr==NULL)
				cout<<"Value not found!";
				if(curr==tail)
				{
					tail=curr->prev;
					tail->next=NULL;
					delete curr;
				}
				else
				{
					curr->prev->next=curr->next;
					curr->next->prev=curr->prev;
					delete curr;	
				}
				
			}
			
			count--;
		}

		bool emptyList()
		{
			if(head==NULL && tail==NULL)
			return true;
		}
		void returnSearch(string &name)
		{
			nodeType *ptr=head;
			string s1=head->info.getFName();
			while(name!=s1)
			{
				ptr=ptr->next;
				s1=ptr->info.getFName();
			}
			ptr->info.Display(); cout<<endl;
		}
		void bubbleSort()
		{
			nodeType *ptr;
			for(int i=1; i<count; i++)
			{
				ptr=head;
				for(int j=0; j<(count-i); j++)
				{
					if((ptr->info.getFName())>(ptr->next->info.getFName()))
					{
						Person temp=ptr->next->info;
						ptr->next->info=ptr->info;
						ptr->info=temp;
					}
					ptr=ptr->next;
				}
			}
		}
		void writeToFile(fstream &fout)
		{
			nodeType *ptr=head;
			while(ptr!=NULL)
			{
				fout<<ptr->info.getFName()<<"\t"<<ptr->info.getLName()<<"\t"<<ptr->info.getNo()<<"\t"<<ptr->info.getEmail()<<"\n";
				ptr=ptr->next;
			}
		}
		
};


