#include <iostream>
#include <string>
#include <list>
#include <iterator>

using namespace std;

template <typename type>
class HashChain{
	
	private:
		list<type> *info;
		int size;
	public:
		HashChain(int s)
		{
			size=s+17;
			info = new list<type>[s+17];
		}
		~HashChain()
		{
			delete info;
		}
		void insert(type sub)
		{
			int index=0;
			for(int i=0; i<sub.word.size(); i++)
			{
				index+=(sub.word[i]+(i*(i+51)*711));
			}
			index=index%(size);
			info[index].push_front(sub);
		}
		bool search(string name)
		{
			int index=0;
			for(int i=0; i<name.length(); i++)
			{
				index+=(name[i]+(i*(i+51)*711));
			}
			index=(index)%(size);
			typename std::list<type> :: iterator ite;
   			for(ite=info[index].begin(); ite!=info[index].end() ;ite++)
  		  	{
     		   if(ite->word==name)
       		 {
       		 	cout<<"\nMeaning: ";
       			cout<<ite->details;
          	  return true;
        	 }
    	 	}
    		return false;
		}
		int nonemptyN()
		{
			int count=0;
			for(int i=0; i<size; i++)
			{
				if(info[i].empty())
				count++;
			}
			cout<<"\nNon empty indexes: "<<(size-count);
			return(size-count);
		}
		int Keys()
		{
			int count=0; int sum=0;
			for(int i=0; i<size; i++)
			{
				if(!info[i].empty())
				{
					sum+=info[i].size();
					count++;
				}
			}
			return sum;
		}
	 
};
