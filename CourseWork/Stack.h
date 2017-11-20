#ifndef __STACK_H__
#define __STACK_H__

#include "LinearList.h"

template<class T>
class Stack: private LinearList<T>{
public:
        Stack<T>(){};
        ~Stack(){};
        bool IsEmpty() const {
            return LinearList<T>::IsEmpty();
        }
        bool IsFull() const { return (
            LinearList<T>::Length() == LinearList<T>::GetMaxSize());
           
        }
        T& Top() const{
             //this function return the top element but not delete it
             if (LinearList<T>::IsEmpty()) throw OutOfBounds();
             T x; 
             LinearList<T>::Find(LinearList<T>::Length(), x); 
             return x;
        }
        Stack<T>& Add(const T& x) {
             LinearList<T>::Insert(LinearList<T>::Length(), x); return *this;
        }
        Stack<T>& Delete(T& x) {
             LinearList<T>::Delete(LinearList<T>::Length(), x); return *this;
        }
};

#endif // __STACK_H__
