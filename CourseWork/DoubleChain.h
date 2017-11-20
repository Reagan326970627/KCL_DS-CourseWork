//
//  DoubleChain.h
//  CourseWork
//
//  Created by 李根 on 2017/11/12.
//  Copyright © 2017年 李根. All rights reserved.
//

#ifndef DoubleChain_h
#define DoubleChain_h

template <class T> class DoubleChain;

template <class T>
class DoubleChainNode
{
    friend class DoubleChain<T>;
private:
    T data;
    DoubleChainNode<T> *preLink;
    DoubleChainNode<T> *link;
public:
    //interface for other class to read/write private members
    T& getData(){return data;};
    DoubleChainNode<T> *getLink(){return link;};
    DoubleChainNode<T> *getpreLink(){return preLink;}
    
    void setData(T& x){this->data=x;};
    void setLink(DoubleChainNode<T> *p) {this->link=p;};
    void setpreLink(DoubleChainNode<T> *p) {this->preLink=p;}
    DoubleChainNode(){preLink=NULL; link=NULL;};
    ~DoubleChainNode(){};
};

template <class T>
class DoubleChain {
public:
    DoubleChain(){first=NULL; last=NULL;}
    ~DoubleChain(){}
    int Length() const;
    void doubleTraverse();
    DoubleChain<T>& addLast(T& x);
    T& accessMid();
    
    DoubleChain<T>& addFirst(T& x);
    DoubleChain<T>& removeFirst();
    
    DoubleChain<T>& Remove(int k, T& x); //(Delete function is renamed into Remove because of the requirement)
    DoubleChain<T>& Insert(int k, const T& x);
private:
    DoubleChainNode<T> *first;
    DoubleChainNode<T> *last;  //change when addLast, insert(k=length OR empty) and addFirst(empty)
};

template<class T>
int DoubleChain<T>::Length() const
{
    // Return the number of elements in the chain.
    DoubleChainNode<T> *current = first;
    int len=0;

    while (current!= NULL)
    {
        len++;
        current=current->link;
    }
    return len;
}

template<class T>
DoubleChain<T>& DoubleChain<T>::Remove(int k, T& x)
{
    // Set x to the kth element and delete it.
    // Throw OutOfBounds exception if no kth element.
    if (k < 1 || !first)
        throw OutOfBounds();     //no kth
    
    // p will eventually point to kth node
    DoubleChainNode<T> *p = first;
    
    // move p to kth & remove from chain
    if (k == 1)            // p already at kth
        
        first = first->link;    // remove
    else
    {
        //use q to get to k-1st
        DoubleChainNode<T> *q = first;
        for (int index = 1; index < k - 1 && q; index++)
            q = q->link;
        
        if (q==NULL || q->link==NULL)
            throw OutOfBounds();    //no kth
        
        p = q->link;            //kth
        q->link = p->link;      //remove from chain
        x = p->data;            //save the deleted value temporarily
        delete p;
        //add backward pointer
        p=q->link;
        p->preLink=q;
    }
    // save kth element and free node p
    return *this;
}


template<class T>
DoubleChain<T>& DoubleChain<T>::Insert(int k, const T& x)

{    // Insert x after the kth element.
    // Throw OutOfBounds exception if no kth element.
    // Pass NoMem exception if inadequate space.
    
    if (k < 0) throw OutOfBounds();
    
    // p will eventually point to kth node
    DoubleChainNode<T> *p = first;
    
    for (int index = 1; index < k && p; index++)
        p = p->link;             // move p to kth
    
    // no kth
    if (k > 0 && !p)
        throw OutOfBounds();
    // insert
    
    DoubleChainNode<T> *y = new DoubleChainNode<T>;
    
    y->data = x;
    
    if (k)
    {    // insert after p
        y->link = p->link;
        y->preLink = p; //backward pointer
        p->link = y;
        if (k==this->Length()) {last=y;}  //kth is the last element
    }
    else
    {    // insert as first element
        y->link = first;
        first = y;
        last = y;
    }
    return *this;
    
}


template<class T>
DoubleChain<T>& DoubleChain<T>::addFirst(T& x)
{
    DoubleChainNode<T> *p=new DoubleChainNode<T>();
    
    if (first==NULL){
        p->data=x;
        first=p;
        last=p;
    }
    else{
        p->link=first;
        p->data=x;
        first=p;
    }
    
    return *this;
}


template<class T>
DoubleChain<T>& DoubleChain<T>::removeFirst(){
    
    if (first == NULL) {throw NoMem();}
    else {
        first=first->link;
    }
    return *this;
}
template<class T>
void DoubleChain<T>::doubleTraverse()
{
    DoubleChainNode<T> *p = first;
    if (p!=NULL) {return;}
    else{
        //traverse forward
        while (p->link!=NULL) {
            p=p->link;
        }
        //traverse backward
        while (p->preLink!=NULL) {
            p=p->preLink;
        }
    }
    return;
}

template<class T>
DoubleChain<T>& DoubleChain<T>::addLast(T& x)
{
    DoubleChainNode<T> *q=new DoubleChainNode<T>();
    if (last==NULL) {
        q->data=x;
        first=q;
        last=q;
    }
    else
    {
        q->data=x;
        last->link=q;
        q->preLink=last;
        last=q;
    }
    return *this;
}

template<class T>
T& DoubleChain<T>::accessMid()
{
    int mid=this->Length();
    int counter=0;
    mid=mid/2;
    
    DoubleChainNode<T> *p = first;
    
    while (p->link!=NULL && counter<mid) //Traverse sequentially
    {
        p=p->link;
        counter+=1;
    }
    
    if (counter!=mid) {throw "No such a element!";}
    
    return p->data;
}

#endif /* DoubleChain_h */
