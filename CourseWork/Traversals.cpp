#include "Chain.h"
#include "Stack.h"

void postorder(int tree[], int n)
{
       int X,Y;
       Stack<int> *S= new Stack<int>();
       int * visited = new int[n+1]; // intermediate array to keep
				     // track of already visited elements 

       for(int i=0;i<=n;i++)
              visited[i]=0;

       S->Add(1); // push root index to S

       while(!S->IsEmpty()){
              X=S->Top();
              if(2*X<=n && tree[2*X-1]!=0 && !visited[2*X-1] )
                     S->Add(2*X); // push valid left child index to S
              else if(2*X+1<=n && tree[2*X]!=0 && !visited[2*X]  )
                     S->Add(2*X+1); // push valid right child index to S
              else{
                     cout<<tree[X-1]<<" ";
                     visited[X-1]=1;
                     S->Delete(Y); // delete the visited node index from S
              }
       }

    //delete visited;
}

void inorder(int tree[],int n)
{
    int visit[n];
    int i=0,left,father,right,done=0;
    
    memset(visit,0,n*sizeof(int));
    
    while (done==0){
        left=2*i+1;
        if (left<n && tree[left]!=0 && visit[left]==0) {i=left;}
        else {
            if (visit[i]==0) {
                cout<<tree[i]<<' ';
                visit[i]=1; //current node has been visited
            }
            
            right=left+1;
            if (right<n && tree[right]!=0 && visit[right]==0) {i=right;}
            else {
                father=(i-1)/2;
                if (i-1>=0) {i=father;}
                else {done=1; } //finish
            }
        }
    }
    
}

void preorder(int tree[],int n)
{
    int visit[n];
    int i=0,left,father,right,done=0;
    
    memset(visit,0,n*sizeof(int));
    
    while (done==0){
        if (visit[i]==0) {
            cout<<tree[i]<<' ';
            visit[i]=1; //current node has been visited
        }
        left=2*i+1;
        if (left<n && tree[left]!=0 && visit[left]==0) {i=left;}
        else {
            right=left+1;
            if (right<n && tree[right]!=0 && visit[right]==0) {i=right;}
            else {
                father=(i-1)/2;
                if (i-1>=0) {i=father;}
                else {done=1; } //finish
            }
        }
    }
    
}


int main()
{
	int tree[] = {23, 16, 29, 12, 19, 27, 31, 7, 14, 17, 21, 0, 0, 0, 0 };
    
    preorder(tree, sizeof(tree)/sizeof(int));
    cout<<endl;
    inorder(tree, sizeof(tree)/sizeof(int));
    cout<<endl;
	postorder(tree, sizeof(tree)/sizeof(int));
    cout<<endl;
	return 0;
}

