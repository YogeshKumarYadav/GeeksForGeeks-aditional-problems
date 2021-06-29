// { Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}// } Driver Code Ends


 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

//you have to complete this function

void swap(int* a, int* b )
{   
    int t = *a;
    *a = *b;
    *b = t;
}

node* partition(node *l, node *h){
    //Your code goes here

    node *i=l,*j=l->next,*pivot=l;
    while(j!=h->next)
    {
        if(j->data < pivot->data)
        {  swap(j->data, i->next->data);
           i=i->next;
        }
        j=j->next;
    }
    swap(pivot->data, i->data);
    return i;

}

void _quicksort(struct node *l, struct node *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        struct node *p = partition(l, h);
        _quicksort(l, p);
        _quicksort(p->next, h);
    }
}

void quickSort(struct node **headRef)
{
    struct node *h=*headRef;
    while(h->next!=NULL)
       h=h->next;
       
    _quicksort(*headRef,h);   
}
