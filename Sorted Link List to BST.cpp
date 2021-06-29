// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; 

TNode* sortedListToBST(LNode* head);

void preOrder(TNode* node)  
{  
    if (node == NULL)  
        return;  
    cout<<node->data<<" ";  
    preOrder(node->left);  
    preOrder(node->right);  
} 

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int data;
        cin>>data;
        LNode *head = new LNode(data);
        LNode *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        TNode* Thead=sortedListToBST(head);
        preOrder(Thead);
        cout<<"\n";
        
    }
    return 0;
}
// } Driver Code Ends


//User function Template for C++


//User function Template for C++

/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */


TNode* convert(LNode **head, int n)
{   if(n<=0)
        return NULL;
    
    TNode *rootleft=convert(head,n/2);    
    TNode *temp= new TNode((*head)->data);
    temp->left=rootleft;
    *head=(*head)->next;
    temp->right=convert(head,n-n/2-1);
    return temp;
}

TNode* sortedListToBST(LNode *head)
{
    //code here
    int n=0;
    LNode *temp=head;
    while(temp)
    {   temp=temp->next;
        n++;
    }
    TNode *root;
    return root=convert(&head,n);
    
}