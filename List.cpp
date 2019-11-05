/****************PROGRAM TO WRITE THE IMPLEMENTATION OF LIST CLASS******************/
#include<iostream>
#include "List.h"
using namespace std;

//NULL CONSTRUCTOR
	Clist::Clist() :head(NULL),count(0)
	{
	}

	//PARAMETRIC CONSTRUCTOR
	Clist::Clist(Cnode *&ptr) :head(ptr)
	{
		head->next = NULL;
		ptr = NULL;
		++count;
	}

	//PRECONDITION FUNCTION TO CHECK IF LIST IS EMPTY OR NOT
	bool Clist::isEmpty()const
	{
		if (head)
			return false;
		else
			return true;
	}

	//PRECONDITION FUNCTION TO CHECK IF LIST IS EMPTY OR NOT
	bool Clist::isNotEmpty()const
	{
		if (head)
			return true;
		else
			return false;
	}

	//FUNCTION TO GET NUMBER OF NODES
	int Clist:: getCount()const
	{
		return count;
	}

	//FUNCTION TO INSERT NODES
	Clist& Clist::insert(Cnode *&ptr)
	{

		ptr->next = head;
		head = ptr;
		ptr = NULL;
		++count;
		return *this;
	}

	//FUNCTION TO DISPLAY NODES
	void Clist:: print()
	{
		cout << "LIST OF NODES" << endl;
			Cnode *ptr = head;
			int x = count;
			while (x>0)
			{
				ptr->print();
				ptr = ptr->next;
				--x;
			}
	}


	//REMOVE FUNCTION
	Cnode* Clist::remove()
	{
		Cnode *ptr = head;
			head = head->next;
			ptr->next = NULL; --count;
			return ptr;
	}

	//FUNCTION TO REMOVE NODE FROM SPECIFIC POSITION
	Cnode * Clist::removeAt(int index)
	{
		if (index <= 0)
		{
			return remove();
		}
		if (index >= count)
			index = count - 1;
		Cnode *rptr = head;
		for (int i = 1; i < index; ++i)
		{
			rptr = rptr->next;
		}
		Cnode *ptr;
		ptr = rptr->next;
		rptr = ptr->next;
		--count;
		ptr->next = NULL;
		return ptr;
	}

	//ASSGNMENT OPERATOR
	Clist&  Clist:: operator=(const Clist& robj)
	{
		if (this == &robj)
			return *this;
		if (true)
		{
			Clist temp;
			temp.head = head;
		}
		if (true)
		{
			Clist temp = robj;
			head = temp.head;
			temp.head = NULL;
		}
		return *this;
	}


	//FUNCTION TO INSERT NODE AT SPECIFIC POSITTION
	Clist& Clist::insertAt(int index, Cnode *ptr)
	{
		if (index <= 0)
		{
			insert(ptr);
			return *this;
		}
		if (index > count)
			index = count;

		Cnode *rptr = head;
		for (int i = 1; i < index; ++i)
			rptr = rptr->next;
		ptr->next = rptr->next;
		rptr->next = ptr;
		++count;
		rptr = ptr = NULL;
		return *this;
	}

	//CONSTRUCTOR TO TAKE INPUT FROM FILE
	Clist::Clist(ifstream &inFile)
	{
		head = NULL;
		inFile.read((char*)&count, sizeof(count));
		if (count > 0)
		{
			Cnode *ptr;
			head = ptr = new Cnode(inFile);
			for (int i = 1; i < count; ++i)
			{
				ptr->next = new Cnode(inFile);
				ptr = ptr->next;
			}
			ptr->next = NULL;
		}
	}

	//COPY CONSTRUCTOR
	Clist::Clist(const Clist &src) :head(src.head), count(src.count)
	{
		if (count > 0)
		{
			Cnode *ptr, *dptr;
			dptr = head = new Cnode(*src.head);
			ptr = head->next;
			for (int i = 1; i < count; ++i)
			{
				dptr->next = new Cnode(*ptr);
				dptr = dptr->next;
				ptr = ptr->next;
			}
			dptr->next = NULL;
		}
	}


	//DESTRUCTOR TO RETURN BACK MEMORY
	Clist::~Clist()
	{
		void deleteNodes(Cnode *ptr);
		deleteNodes(head);
	}

	//FUNCTION TO DELETE NODES
	void deleteNodes(Cnode *ptr)
	{
		if (ptr)
		{
			deleteNodes(ptr->next);
			delete ptr;
		}
	}	

	//FUNCTION TO READ FROM FILE
	void Clist::readFromFile(ifstream &inFile)
	{
		if (true)
		{
			Clist temp;
			temp.head = this->head;
		}
		inFile.read((char*)&count, sizeof(count));
		if (count > 0)
		{
			Cnode *ptr;
			ptr = head=new Cnode(inFile);
			for (int i = 1; i < count; ++i)
			{
				ptr->next = new Cnode(inFile);
				ptr = ptr->next;
			}
			ptr->next = NULL;
		}
	}

	//WRITE TO FILE
	void Clist::writeToFile(ofstream &oFile)
	{
		oFile.write((char*)&this->count, sizeof(count));
		if (count > 0)
		{
			Cnode *ptr = head;
			for (int i = 0; i < count; ++i)
			{
				ptr->writeToFile(oFile);
				ptr = ptr->next;
			}

		}
	}

	//IS SIMILAR FUNCTION TO CHECK TWO LISTS ARE EQUAL OR NOT
	bool Clist:: isSimilar(const Clist &obj1, const Clist &obj2)
	{
		bool f = false;
		Cnode *ptr2 = obj2.head;
		Cnode *ptr1 = obj1.head;
		while (ptr1 != NULL && ptr2 != NULL)
		{
			if (ptr1->getData() == ptr2->getData())
				f = true;
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		return f;
	}

	//FUNCTION TO ARARNGE LIST AS AN ARRAY
	Cnode& Clist::operator[](int index)
	{
		if (index <= 0)
			return *head;
		if (index >= count)
		{	index = count - 1;
		Cnode *rptr = head;
		for (int i = 0; i < index; ++i)
			rptr = rptr->next;
		return *rptr;
	    }
		return *head;
	}

	//FUNCTION TO SWAP NODES
	Clist& Clist::swapNodesAt(int index1, int index2)
	{
		if (index1 > 0)
			index1= 0;
		if (index2 < 0)
			index2 = 0;
		if (index1 >= count)
			index1 = count - 1;
		if (index2 >= count)
			index2 = count - 1;
		if (index1 == index2)
			return *this;
		if (index1 < index2)
		{
			insertAt((index2 - 1), removeAt(index1));
			insertAt((index1), removeAt(index2));
		}
		else
		{
			insertAt((index1 - 1), removeAt(index2));
			insertAt((index2), removeAt(index1));
		}
		return *this;
	}

	//FUNCTION TO REVERSE LIST
	Clist & Clist::reverse()
	{
		if (count < 2)
			return *this;
		Cnode **Arr = new Cnode *[count];
		Cnode *rptr;
		rptr = head;
		for (int i = 0; i < count; ++i)
		{
			Arr[i] = rptr;
			rptr = rptr->next;
		}
		for (int i = 0; i < count; ++i)
			Arr[i]->next = Arr[i - 1];
		Arr[0] = NULL;
		head = Arr[count - 1];
		delete []Arr;
		return *this;
	}


	//FUNCTION TO DELETE NODES
	void Clist::deleteNodes()
	{
		Cnode *ptr = head;
		while (ptr)
		{
			ptr = ptr->next;
			delete head;
			head = ptr;
			--count;
		}
	}

	Clist & Clist::operator+(const Clist &obj)
	{
		if (obj.count == 0)
			return  *this;
			Clist rCopy = obj;
		if (!head)
		{
			head = rCopy.head;
			count = rCopy.count;
		}
		else
		{
			Cnode *rptr = head;
			for (int i = 1; i < count; ++i)
				rptr = rptr->next;
			rptr->next = rCopy.head;
			count += rCopy.count;
		}
		rCopy.head = NULL;
		return *this;
		}