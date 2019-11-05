/****************PROGRAM TO WRITE THE IMPLEMENTATION OF CNODE CLASS******************/
#include<iostream>
#include<fstream>
#include "Node.h"
using namespace std;

//NULL CONSTRUCTOR
Cnode::Cnode()
{
	pri = 0;
	data = 0;
	next = NULL;
}
//PARAMETRIC CONSTRUCTOR
Cnode::Cnode(int d, int p) :data(d), pri(p) {}

//PARAMETRIC CONSTRUCTOR TO READ FROM FILE
Cnode::Cnode(ifstream &inFile)
{
	inFile.read((char*)this, sizeof(this));
}

//FUNCTION TO TAKE INPUT FROM FILE
void Cnode::readFromFile(ifstream &inFile)
{
	inFile.read((char*)this, sizeof(*this));
}

//FUNCTION TO WRITE INTO THE FILE 
void Cnode::writeToFile(ofstream &oFile)
{

	oFile.write((char*)this, sizeof(*this));
}

//FUNCTION TO GET VALUE
int Cnode::getData()const
{
	return data;
}

//FUNCTION TO SET NODE VALUES
Cnode& Cnode::setData(int data, int p)
{
	this->data = data;
	this->pri = p;
	return *this;
}

//FUNCTION TO PRINT NODES
void Cnode::print()
{
	cout << data << " " << pri << endl;
}

