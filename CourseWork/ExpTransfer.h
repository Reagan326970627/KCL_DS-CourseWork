//
//  ExpTransfer.h
//  CourseWork
//
//  Created by 李根 on 2017/11/15.
//  Copyright © 2017年 李根. All rights reserved.
//

#ifndef ExpTransfer_h
#define ExpTransfer_h

#include "xcept.h"
#include "Stack.h"
#include "TreeNode.h"
using namespace std;
class ExpTransfer{
public:
    TreeNode<char> *endRoot;
public:
    ExpTransfer(){endRoot=NULL;};
    ~ExpTransfer(){};
    void transFromPostfix(char postfix[]);
    void printPrefix(TreeNode<char> *p);
    void printInfix(TreeNode<char> *p);
};

void ExpTransfer::printInfix(TreeNode<char> *p){
    if (p==NULL) {throw NoMem();}
    else{
        if (p->getleftChild()!=NULL) {printInfix(p->getleftChild());}
        cout<<p->getData()<<' ';
        if (p->getrightChild()!=NULL) {printInfix(p->getrightChild());}
    }
    return;
}

void ExpTransfer::printPrefix(TreeNode<char> *p){
    if (p==NULL) {throw NoMem();}
    else
    {
        cout<<p->getData()<<' ';
        if (p->getleftChild()!=NULL) {printPrefix(p->getleftChild());}
        if (p->getrightChild()!=NULL) {printPrefix(p->getrightChild());}
    }
    return;
}

void ExpTransfer::transFromPostfix(char postfix[])
{
    //0-length-1
    Stack<char> stack;
    TreeNode<char> *leftChild=NULL,*rightChild=NULL,*root=NULL,*current=NULL;
    char temp,oper;
    int done=0,watch;
    
    watch=strlen(postfix);
    if (strlen(postfix)==0) {throw NoMem();}
    else
    {
        for (int i=strlen(postfix)-1; i>=0; i--) {
            if (postfix[i]=='+' || postfix[i]=='-' ||postfix[i]=='*'||postfix[i]=='/'){
                if (current==NULL) {current=new TreeNode<char>(postfix[i]); endRoot=current;}
            else
            {
                if (current->getrightChild()==NULL)
                {
                    rightChild=new TreeNode<char>(postfix[i]);
                    current->setrightChild(rightChild);
                    rightChild->setpreLink(current);
                    current=rightChild;
                }
                else if (current->getleftChild()==NULL)
                {
                    leftChild=new TreeNode<char>(postfix[i]);
                    current->setleftChild(leftChild);
                    leftChild->setpreLink(current);
                    current=leftChild;
                }
            }
            }
            else
            {
                if (current->getrightChild()==NULL)
                {
                    rightChild=new TreeNode<char>(postfix[i]);
                    current->setrightChild(rightChild);
                    rightChild->setpreLink(current);
                }
                else if (current->getleftChild()==NULL)
                {
                    leftChild=new TreeNode<char>(postfix[i]);
                    current->setleftChild(leftChild);
                    leftChild->setpreLink(current);
                }
            }
            
            if (current->getleftChild()!=NULL && current->getrightChild()!=NULL)
            {
                if (current->getpreLink()!=NULL){current=current->getpreLink();}
            }
            
}
            
//            if (postfix[i]=='+' || postfix[i]=='-' ||postfix[i]=='*'||postfix[i]=='/') {stack.Add(postfix[i]);}
//            else {
//                done++;
//                if (done==2) {
//                    rightChild=new TreeNode<char>(postfix[i]);
//                    //(TreeNode<char> *) malloc(sizeof(TreeNode<char>));
//                    //rightChild->setData(postfix[i]);
//
//                    done++;
//                }
//                else
//                {
//                    //form a subtree
//                    leftChild=new TreeNode<char>(postfix[i]);
//                    //(TreeNode<char> *) malloc(sizeof(TreeNode<char>));
//                    //leftChild->setData(postfix[i]);
//                    oper=stack.Top();
//                    root=new TreeNode<char>(oper);
//                    //(TreeNode<char> *) malloc(sizeof(TreeNode<char>));
//                    //root->setData(stack.Top());
//                    stack.Delete(temp);
//
//                    leftChild->setpreLink(root);
//                    rightChild->setpreLink(root);
//
//                    root->setleftChild(leftChild);
//                    root->setrightChild(rightChild);
//
//                    if (i==0) {done=0; endRoot=root;} //finish
//                    else{
//                        rightChild=root;
//                        done=1;
//                    }
//                }
//
//            }
         
        
    }
    
}

#endif /* ExpTransfer_h */
