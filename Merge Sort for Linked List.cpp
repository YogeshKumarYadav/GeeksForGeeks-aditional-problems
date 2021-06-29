// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* merge(Node* l, Node* r)
    {
        Node *temp=NULL;
        if(l==NULL)
          return r;
        else if(r==NULL)
          return l;
        else
        {
            if(l->data < r->data)
            {   temp=l;
                temp->next=merge(l->next,r);
            }
            else
            {   temp=r;
                temp->next=merge(l,r->next);
            }
        }
        return temp;
        
    }
    
    
    void split(Node **l, Node **r, Node *head)
    {
        Node *fast=head,*slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        *l=head;
        *r=slow->next;
        slow->next=NULL;
    }
    
    void _mergesort(Node** head)
    {
        Node *l,*r,*h=*head;
        if(h==NULL || h->next==NULL)
            return;
        
        split(&l,&r,h);
        _mergesort(&l);
        _mergesort(&r);
        *head=merge(l,r);
    }
    
    Node* mergeSort(Node* head) {
        // your code here
        
        _mergesort(&head);
        return head;
        
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends