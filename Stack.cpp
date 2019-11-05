/**********************PROGRAM TO WRITE IMPLEMENTATION OF CSTACK CLASS***********************/
#include<iostream>
#include "Stack.h"
using namespace std;

	//DAFAULT CONSTRUCTor
	Cstack::Cstack():top(NULL) {}

	//PARAMETRIC CONSTRUCTOR
	Cstack::Cstack(Cnode *ptr)
	{
		top = ptr;
		top->next = NULL;
		ptr = NULL;
		++count;
	}

	//PARAMETRIC CONSTRUCTOR
	Cstack::Cstack(ifstream &inFile) :top(NULL), count(0)
	{
		int size;
		inFile.read((char*)&size, sizeof(size));
		if (size > 0)
		{
			Cnode *ptr;
			ptr = top = new Cnode(inFile);
			count = size;
			for (int i = 1; i < count; ++i)
			{
				ptr->next = new Cnode(inFile);
				ptr = ptr->next;

			}
			ptr->next = NULL;
		}
	}

	//WRITE TO FILE FOR STACK
	void Cstack:: writeToFile(ofstream &oFile)
	{
		oFile.write((char*)&this->count, sizeof(count));
		if (count > 0)
		{
			Cnode *ptr = top;
			for (int i = 0; i < count; ++i)
			{
				ptr->writeToFile(oFile);
				ptr = ptr->next;
			}

		}
	}

	//FUNCTION TO READ FROM FILE
	void Cstack::readFromFile(ifstream &inFile)
	{
		if (true)
		{
			Cstack temp;
			temp.top = this->top;
		}
		inFile.read((char*)&count, sizeof(count));
		if (count > 0)
		{
			Cnode *ptr;
			ptr = top; new Cnode(inFile);
			for (int i = 1; i < count; ++i)
			{
				ptr->next = new Cnode(inFile);
				ptr = ptr->next;
			}
			ptr->next = NULL;
		}
	}
	//PRE CONDITION FUNCTION TO CHECK NODE IS NOT EMPTY
	bool Cstack::isNotEmpty()const
	{
		if (top)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//PRE CONDITION TO CHECK CNODE IS EMPTY
	bool Cstack::isEmpty()const
	{
		if (top)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	//FUNCTIION TO ADD NODE
	Cstack* Cstack::push(Cnode *&ptr)
	{ 
			ptr->next = top;
			top = ptr;
			ptr = NULL;
			++count;
		 return this;
	}

	//FUNCTION TO REMOVE NODES
	Cnode* Cstack:: pop()
	{
		Cnode *ptr = top;

			top = top->next;
			ptr->next = NULL;
			--count;
		
		return ptr;
	}

	//FUNCTION TO PRINT STACK
	void Cstack::print()const
	{
		cout << "List of Node:" << endl;
			Cnode *ptr = top;
			while (ptr)
			{
				ptr->print();
				ptr = ptr->next;
			}
	}

	//FUNCTION TO COPY STACK INTO ANOTHER CSTACK
	Cstack::Cstack(const Cstack &src)
	{
		this->top = src.top;
		if (src.top)
		{
			Cnode *ptr, *dptr;
			dptr = top = new Cnode(*src.top);
			ptr = src.top->next;
			while (ptr)
			{
				dptr->next = new Cnode(*ptr);
				ptr = ptr->next;
				dptr = dptr->next;
			}
		}
	}
	
	//FUNCTION TO EQUAL TWO STACK
	Cstack& Cstack::operator=(const Cstack &obj)
	{
		if (this == &obj)
			return *this;

		if (true)
		{
			Cstack temp;
			temp.top = top;
		}
		if (true)
		{
			Cstack temp = obj;
			top = temp.top;
			temp.top = NULL;
		} return *this;

	}

	//DESTRUCTOR TO RETURN MEMORY SPACE
	Cstack::~Cstack()
	{
		Cnode *ptr = top;
		while (ptr)
		{
			ptr = ptr->next;
			delete top;
			top = ptr;
		}
	}

	//GET COUNT
	int Cstack::getCount()const
	{
		return count;
	}

	




