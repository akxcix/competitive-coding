#include<bits/stdc++.h>
using namespace std;

struct Node  
{  
    int data;  
    Node *left;  
    Node *right;  
    int ht;  
};  
int ht(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->ht;  
}  
  
Node* newNode(int data)  
{  
    Node* node = new Node(); 
    node->data = data;  
    node->left = NULL;  
    node->right = NULL;  
    node->ht = 1; 
    return(node);  
}  

Node *rightRotate(Node *y)  
{  
    Node *x = y->left;  
    Node *T2 = x->right;  
    x->right = y;  
    y->left = T2;  
    y->ht = max(ht(y->left), 
                    ht(y->right)) + 1;  
    x->ht = max(ht(x->left), 
                    ht(x->right)) + 1;  
    return x;  
}  
   
   
Node *leftRotate(Node *x)  
{  
    Node *y = x->right;  
    Node *T2 = y->left;  
    y->left = x;  
    x->right = T2;   
    x->ht = max(ht(x->left),     
                    ht(x->right)) + 1;  
    y->ht = max(ht(y->left),  
                    ht(y->right)) + 1;  
    return y;  
} 

int getBalance(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return ht(N->left) - ht(N->right);  
}   
Node* insert(Node* node, int data)  
{  
    if (node == NULL)  
        return(newNode(data));  
  
    if (data < node->data)  
        node->left = insert(node->left, data);  
    else if (data > node->data)  
        node->right = insert(node->right, data);  
    else   
        return node;

    node->ht = 1 + max(ht(node->left),  
                        ht(node->right));  
    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data) { 
        cout<<node->data<<endl;
        return rightRotate(node);  
    }
    if (balance < -1 && data > node->right->data)  {
        cout<<node->data<<endl;
        return leftRotate(node);
    }
    if (balance > 1 && data > node->left->data)  
    {  cout<<node->data<<endl;
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
    if (balance < -1 && data < node->right->data)  
    {  cout<<node->data<<endl;
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  

    return node;  
}  


Node * minValueNode(Node* node)  
{  
    Node* current = node;  
    while (current->left != NULL)  
        current = current->left;  
  
    return current;  
}  
  
  
Node* deleteNode(Node* root, int data)  
{  
      
   
    if (root == NULL)  
        return root;  
  
  
    if ( data < root->data )  
        root->left = deleteNode(root->left, data);  
  
   
    else if( data > root->data )  
        root->right = deleteNode(root->right, data);  
 
    else
    {  
 
        if( (root->left == NULL) || 
            (root->right == NULL) )  
        {  
            Node *temp = root->left ?  
                         root->left :  
                         root->right;  
  
    
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else  
            *root = *temp;   
            free(temp);  
        }  
        else
        {  
              
            Node* temp = minValueNode(root->right);  
    
            root->data = temp->data;  
  
             
            root->right = deleteNode(root->right,  
                                     temp->data);  
        }  
    }  
   
    if (root == NULL)  
    return root;  
  
   
    root->ht = 1 + max(ht(root->left),  
                           ht(root->right));  
  
    
    int balance = getBalance(root);  
  
    
    if (balance > 1 &&  
        getBalance(root->left) >= 0)  {
            cout<<root->data<<endl;
        return rightRotate(root);  
        }
    
    if (balance > 1 &&  
        getBalance(root->left) < 0)  
    {  cout<<root->data<<endl;
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
  
      
    if (balance < -1 &&  
        getBalance(root->right) <= 0){ 
            cout<<root->data<<endl; 
        return leftRotate(root);  
        }
      
    if (balance < -1 &&  
        getBalance(root->right) > 0)  
    {  cout<<root->data<<endl;
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
  
    return root;  
}  

void preOrder(Node *root)  
{  
    if(root != NULL)  
    {  
        cout << root->data << " ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  
void inOrder(Node *root)  
{  
    if(root != NULL)  
    {  
        inOrder(root->left);
        cout << root->data << " ";  
          
        inOrder(root->right);  
    }  
}
void postOrder(Node *root)  
{  
    if(root != NULL)  
    {  
        
        postOrder(root->left);  
        postOrder(root->right); 
         cout << root->data << " ";  
    }  
} 
int main()  
{  
    Node *root = NULL;  
    int n;
    cin>>n;
    while(n--){
        char c;
        int num;
        cin>>c>>num;
        if(c=='i') root = insert(root, num);  
        else if(c=='d') root=deleteNode(root,num);
       } 
    preOrder(root); 
    cout<<endl;   
    inOrder(root); 
    cout<<endl;  
    postOrder(root);   
    return 0;  
    
}
