//
//  TreeNode.h
//  CourseWork
//
//  Created by 李根 on 2017/11/15.
//  Copyright © 2017年 李根. All rights reserved.
//

#ifndef TreeNode_h
#define TreeNode_h
template <class T>
class TreeNode{
private:
    T data;
    TreeNode<T> *preLink;
    TreeNode<T> *leftChild;
    TreeNode<T> *rightChild;
public:
    TreeNode<T>(T& x){
        data=x;
        preLink=NULL;
        leftChild=NULL;
        rightChild=NULL;
    };
    ~TreeNode(){};
    T& getData(){return this->data;}
    TreeNode<T> *getleftChild(){return this->leftChild;}
    TreeNode<T> *getrightChild(){return this->rightChild;}
    TreeNode<T> *getpreLink(){return this->preLink;}
    
    void setData(T& x){this->data=x;}
    void setleftChild(TreeNode<T> *x){this->leftChild=x;}
    void setrightChild(TreeNode<T> *x){this->rightChild=x;}
    void setpreLink(TreeNode<T> *x){this->preLink=x;}
};

#endif /* TreeNode_h */
