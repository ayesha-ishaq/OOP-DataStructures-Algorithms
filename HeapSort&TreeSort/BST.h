//Ayesha Ishaq 18I0772 assignment 04
#include <iostream>
#include <string>

using namespace std;

template <class type>
class BST{
	
	private:
		struct treenode{
			type info;
			treenode *left;
			treenode *right;
		};
		treenode *root;
		void displayinord(treenode *ptr)
		{
			if(ptr)
			{
				displayinord(ptr->left);
				cout<<ptr->info<<" ";
				displayinord(ptr->right);
			}
		}
		int countTrav(treenode *ptr)
		{
			if(ptr)
			{
				return (1 + (countTrav(ptr->left)+countTrav(ptr->right)));
			}
			else
			return 0;
		}
		int suminord(treenode *ptr)
		{
			if(ptr)
			{
				return ((ptr->info)+(suminord(ptr->left)+suminord(ptr->right)));
			}
			else
			return 0;
		}

		void deleteNode(type num, treenode *&ptr)
		{
			if(ptr->info>num)
			deleteNode(num,ptr->left);
			else if(ptr->info<num)
			deleteNode(num,ptr->right);
			else if(ptr->info==num)
			makeDeletion(ptr);
			else
			cout<<"value not found!";
		}
		void makeDeletion(treenode *&ptr)
		{
			treenode *temp;
			if(ptr==NULL)
			cout<<"Value not found!";
			else
			{
				if(!(ptr->right))
				{
					temp=ptr;
					ptr=ptr->left;
					delete temp;
				}
				else if(!(ptr->left))
				{
					temp=ptr;
					ptr=ptr->left;
					delete temp;
				}
				else
				{
					temp=ptr->left;
					while(temp->right)
						temp=temp->right;
					temp->right=ptr->right;
					temp=ptr;
					ptr=ptr->left;
					delete temp;
				}
			}
		}
		sort(treenode *ptr, type arr[], int &i)
		{
			if(ptr)
			{
				sort(ptr->left,arr,i);
				arr[i++]=ptr->info;
				sort(ptr->right,arr,i);
			}
		}
	
	public:
		BST()
		{
			root=NULL;
		}
		void insert(type value)
		{
			treenode *ptr=root, *newnode;
			newnode=new treenode;
			newnode->left=newnode->right=NULL;
			newnode->info=value;
			if(root==NULL)
			root=newnode;
			else 
			{
				while(ptr!=NULL)
				{
					if(ptr->info>value)
					{
						if(ptr->left)
						ptr=ptr->left;
						else
						{
							ptr->left=newnode;
							break;
						}
					}
					else
					{
						if(ptr->right)
						ptr=ptr->right;
						else
						{
							ptr->right=newnode;
							break;
						}
					}
				}
				
			}
		}
		void treesort(type arr[])
		{
			int i=0;
			sort(root,arr,i);
		}
		void remove(type val)
		{
			deleteNode(val, root);
		}
		bool search(type value)
		{
			treenode *ptr=root;
			if(root==NULL)
			cout<<"empty tree";
			else
			{
				while(ptr)
				{
					if(ptr->info==value)
					return true;
					else if(ptr->info>value)
					ptr=ptr->left;
					else
					ptr=ptr->right;
				}
				return false;
			}
		}
		int count()
		{
			return countTrav(root);
		}
		void display()
		{
			displayinord(root);
		}

};

