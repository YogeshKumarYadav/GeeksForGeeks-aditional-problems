// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};





// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



 // } Driver Code Ends
/* The structure of Node is

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
  public:
    // Return a integer of integers having all the nodes in both the BSTs in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {   //Your code here
        vector<int> arr;
        stack<Node*> stk1,stk2;
        Node *a=root1,*b=root2;
        while(a)
        {   stk1.push(a);
            a=a->left;
        }
        while(b)
        {   stk2.push(b);
            b=b->left;
        }
            
        while(!(stk1.empty() && stk2.empty()))
        {   a=b=NULL;
            if(!stk1.empty())
                a=stk1.top();
            if(!stk2.empty())
                b=stk2.top();
            
            if(a==NULL)
            {   arr.push_back(b->data);
                stk2.pop();
            }
            else if(b==NULL)
            {   arr.push_back(a->data);
                stk1.pop();
            }
            else if(a->data <= b->data)
            {   arr.push_back(a->data);
                stk1.pop();
                b=NULL;
            }
            else
            {   arr.push_back(b->data);
                stk2.pop();
                a=NULL;
            }
            
            if(a && a->right)
            {   a=a->right;
                while(a)
                {  stk1.push(a);
                   a=a->left;
                }
            }  
            if(b && b->right)
            {   b=b->right;
                while(b)
                {  stk2.push(b);
                   b=b->left;
                }
            }
            
       }
       
       return arr;
       
    }
};

// { Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}  // } Driver Code Ends