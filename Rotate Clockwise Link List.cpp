//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
} 

Node* rightRotate(Node* head, int k) ;



 // } Driver Code Ends
//User function Template for C++

/* Definition for singly-linked list.
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
Node* rightRotate(Node* head, int k) 
{
    if(k == 0)
        return head;
    if(head->next == NULL || head == NULL)
        return head;
        
    Node *t = head, *newhead = NULL;
    int n = 1;
    while(t->next != NULL)
    {   t = t->next;
        n++;
    }
    t->next = head;
    
    int shift = n - (k % n);
    t = head;
    while(shift-- > 1)
        t = t->next;
    
    newhead = t->next;
    t->next = NULL;
    return newhead;
}

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		struct Node *head = NULL,  *tail = NULL;

		int n;
		cin>>n;

		for (int i = 0; i < n; ++i)
		{
			int data;
			cin>>data;
			append(&head, &tail, data);
			
		}
		int k;
		cin>>k;

		Node* updated_head = rightRotate(head, k); 
		printList(updated_head); 
	}
	return 0; 
}  // } Driver Code Ends