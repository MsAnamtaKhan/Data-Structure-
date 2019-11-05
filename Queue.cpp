/**********************PROGRAM TO WRITE IMPLEMENTATION OF Cqueue CLAS**************************/
#include<iostream>
#include "Queue.h"
using namespace std;
    //NULL CONSTRUCTOR
	Cqueue::Cqueue() :tail(NULL) {}

	//PARAMETRIC CONSTRUCTOR
	Cqueue::Cqueue(Cnode *&ptr) :Cstack(ptr)
	{
		tail = top;

	}

	//PRE CONDITION TO CHECK QUEUE IS NOT EMPTY
	bool Cqueue::isNotEmpty()const
	{
		return Cstack::isNotEmpty();
	}

	//PRE CONDITION TO CHECK QUEUE IS NOT EMPTY
	bool Cqueue::isEmpty()const
	{
		return Cstack::isEmpty();
	}
	//FUNCTION TO INSERT QUEUE
	Cqueue& Cqueue::Add(Cnode *&ptr)
	{
			tail->next = ptr;
			tail = tail->next;
			tail->next = NULL;
			ptr = NULL;
		return *this;
	}

	//FUNCTION TO REMOVE QUEUE
	Cnode* Cqueue::remove()
	{
		if (!top)
		{
			return Cstack::pop();
		}
		else
		{
			if (!top->next)
			{
				tail = NULL;
			}

			return Cstack::pop();
		}

	}

	//FUNCTION TO PRINT QUEUE
	void Cqueue::print()const
	{

		Cstack::print();
	}

	//FUNCTION TO COPY ONE QUEUE INTO ANOTHER 
	Cqueue::Cqueue(const Cqueue &src)
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
	}

	//FUNCTION TO EQUAL TWO QUEUES
	Cqueue& Cqueue::operator=(const Cqueue &obj)
	{
		if (this == &obj)
			return *this;

		if (true)
		{

			Cqueue temp;
			temp.top = top;
			temp.tail = tail;
		}

		if (true)
		{

			Cqueue temp = obj;
			top = temp.top;
			tail = temp.tail;
			temp.top = NULL;
			temp.tail = NULL;
		}
		return *this;
	}

	//DESTRUCTOR FOR QUEUE CLASS
	Cqueue::~Cqueue()
	{
		Cstack::~Cstack();
		tail = NULL;
	}



