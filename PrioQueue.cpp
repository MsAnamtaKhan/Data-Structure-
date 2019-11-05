/**********************PROGRAM TO WRITE IMPLEMENTATION OF Cprio CLASS**************************/
#include<iostream>
#include "PrioQueue.h"
using namespace std;

	//PARAMETRIC CONSTRUCTOR
Cprio::Cprio(Cnode *&ptr) :Cqueue(ptr)
	{}

	//NULL CONSTRUCTOR
	Cprio::Cprio() {}

	//PRE CONDITION TO CHECK QUEUE IS NOT EMPTY
	bool Cprio::isNotEmpty()const
	{
		return Cqueue::isNotEmpty();
	}

	//PRE CONDITION TO CHECK QUEUE IS NOT EMPTY
	bool Cprio::isEmpty()const
	{
		return Cqueue::isEmpty();
	}
	//FUNCTION TO ADD PRIORITY QUEUE
	Cprio& Cprio::Add(Cnode *&ptr)
	{
		if (!top)
		{
			tail = top = ptr;
			tail->next = ptr = NULL;
			return *this;
		}
		if (top->pri < ptr->pri)
		{
		
			Cstack::push(ptr);
			return *this;
		}
		else
		{
			if (tail->pri >= ptr->pri)
			{

				Cqueue::Add(ptr);
				return *this;
			}
			else
			{

				Cnode *bptr, *rptr;
				bptr = rptr = top;
				while (rptr->pri >= ptr->pri)
				{
					bptr = rptr;
					rptr = rptr->next;
				}
				ptr->next = rptr;
				bptr->next = ptr;
				ptr = NULL;
				return *this;
			}
		}
	}

	//FUNCTION TO REMOVE QUEUE
	Cnode* Cprio::remove()
	{
		return Cqueue::remove();
	}

	//FUNCTION TO COPY ONE PRIORITY QUEUE IN TO ANOTHER
Cprio::Cprio(const Cprio &src) :Cqueue((Cqueue&)src)
	{
		tail = top;
		if (tail)
		{
			while (tail->next)
			{
				tail = tail->next;
			}
		}
	}

	//2ND METHOD FOR COPY CONSTRUCTOR
	/*Cprio(const Cprio &src)
		{
			this->top = src.top;
			this->tail = src.tail;
			if (src.top)
			{
				Cnode *ptr;
				tail = top = new Cnode(*src.top);
				ptr = src.top->next;
				while (ptr)
				{
					tail->next = new Cnode(*ptr);
					tail = tail->next;
					ptr = ptr->next;

				}
			}
		}*/

	//FUNCTION TO EQUAL TWO PRIORITY QUEUES
	Cprio& Cprio::operator=(const Cprio& obj)
	{
		if (this == &obj)
			return *this;
		((Cqueue*)this)->operator=((Cqueue&)obj);
		return *this;
	}

//2ND METHOD FUNCTION TO EQUAL TWO PRIORITY QUEUES
	/*Cprio &operator=(const Cprio &obj)
	{
		if (this == &obj)
			return *this;

		if (true)
		{

			Cprio temp;
			temp.top = top;
			temp.tail = tail;
		}

		if (true)
		{

			Cprio temp = obj;
			top = temp.top;
			tail = temp.tail;
			temp.top = NULL;
			temp.tail = NULL;
		}
		return *this;
	}*/
	Cprio::~Cprio()
	{
		Cqueue::~Cqueue();
	
	}