#ifndef __CHAIN_H__
#define __CHAIN_H__

#include <iostream>
using namespace std;
#include "xcept.h"

template <class T> class Chain;

template <class T>
class ChainNode
{
    friend class Chain<T>;
    
    private:
        T data;
        ChainNode<T> *link;
    public:
        //interface for other class to read/write private members
        T& getData(){return data;};
        ChainNode<T> *getLink(){return link;}; //?引用类型和指针类型的概念没搞清
        void setData(T& x){this->data=x;};
        void setLink(ChainNode<T> *p){this->link=p;};
};

template<class T>
class Chain
{
public:
	Chain() {first = 0;}
	~Chain();
	bool IsEmpty() const {return first == 0;}
	int Length() const;
	bool Find(int k, T& x) const;
	int Search(const T& x) const;
	void Output(ostream& out) const;
public:
	ChainNode<T> *first; // pointer to first node
};

template<class T>
bool Chain<T>::Find(int k, T& x) const
{
	// Set x to the kth element in the chain.
	// Return false if no kth; return true otherwise.

	if (k < 1)
		return false;

	ChainNode<T> *current = first;

	int index = 1;				 // index of current
	while (index < k && current)
	{
		current = current->link;
		index++;
	}

	if (current)
	{
		x = current->data;
		return true;
	}
	return false;				 // no kth element
}


template<class T>
int Chain<T>::Search(const T& x) const
{
	// Locate x. Return position of x if found.
	// Return 0 if x not in the chain.

	ChainNode<T> *current = first;
	int index = 1;				 // index of current

	while (current && current->data != x)
	{
		current = current->link;
		index++;
	}

	if (current)
		return index;

	return 0;
}


template<class T>
Chain<T>::~Chain()
{
	// Chain destructor. Delete all nodes in chain.

	ChainNode<T> *next;			 // next node
	while (first)
	{
		next = first->link;
		delete first;
		first = next;
	}
}


template<class T>
int Chain<T>::Length() const
{
	// Return the number of elements in the chain.
	ChainNode<T> *current = first;
	int len = 0;

	while (current)
	{
		len++;
		current = current->link;
	}
	return len;
}

template<class T>

void Chain<T>::Output(ostream& out) const

{// Insert the chain elements into the stream out.

	ChainNode<T> *current;

	for (current = first; current;
		current = current->link)
	out << current->data << "  ";

}


// overload <<
//
template <class T>
ostream& operator<<(ostream& out, const Chain<T>& x)
{x.Output(out); return out;}

#endif // __CHAIN_H__
