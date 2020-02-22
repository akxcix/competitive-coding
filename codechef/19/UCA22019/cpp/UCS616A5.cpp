#include<bits/stdc++.h>
using namespace std;
int count1=0;
struct node{
	int data;
	node *left=NULL;
	node *right=NULL;
	node *parent=NULL;
}*root=NULL,*l=NULL,*ml=NULL,*mr=NULL,*r=NULL;

void preorder(node *root)  
{  
    if(root != NULL)  
    {  
        cout << root->data << " ";  
        preorder(root->left);  
        preorder(root->right);  
    }  
}


void postorder(node *root)  
{  
    if(root != NULL)  
    {  
        postorder(root->left);  
        postorder(root->right);  
    	cout << root->data << " ";  
        
	}
	  
}
void inorder(node *root)  
{  
    if(root != NULL)  
    {  
        inorder(root->left);  
        cout << root->data << " ";  
		inorder(root->right);  
    	
	}
	  
}

void leftrotate(node *n)
{
	node *temp=new node;
	temp=n->right;
	if(temp->left!=NULL)
	{
		temp->left->parent=n;
	}
		n->right=temp->left;
		if(n->parent==NULL)
		{
			root=temp;
			temp->parent=NULL;
		}
		else
		{
			temp->parent=n->parent;
			if (n->parent->left==n)
			{
				n->parent->left=temp;
			}
			else if (n->parent->right==n)
			{
				n->parent->right=temp;
			}
		}
		temp->left=n;
		n->parent=temp;
		
}
void rightrotate(node *n)
{
	node *temp=new node;
	temp=n->left;
	if(temp->right!=NULL)
	{
		temp->right->parent=n;
	}
		n->left=temp->right;

		if(n->parent==NULL)
		{
			root=temp;
			temp->parent=NULL;
		}
		else
		{
			temp->parent=n->parent;
			if (n->parent->left==n)
			{
				n->parent->left=temp;
			}
			else if (n->parent->right==n)
			{
				n->parent->right=temp;
			}
		}
		temp->right=n;
		n->parent=temp;
}
void insertleft(node *n)
{
	if(n==NULL)
	return;
	n->parent=NULL;
	if(l==NULL)
	{
		l=n;
		while(n->right!=NULL)
		n=n->right;
		ml=n;
		return;
	}
	ml->right=n;
	n->parent=ml;
	while(n->right!=NULL)
	n=n->right;
	ml=n;	
}
void insertright(node *n)
{
	if(n==NULL)
	return;
	n->parent=NULL;
	if(r==NULL)
	{
		r=n;
		while(n->left!=NULL)
		n=n->left;
		mr=n;
		return;
	}
	mr->left=n;
	n->parent=mr;
	while(n->left!=NULL)
	n=n->left;
	mr=n;	
}
void reassemble()
{
	count1++;
	if((l!=NULL)||(r!=NULL))
	{
		
		insertleft(root->left);
		insertright(root->right);
		root->left=l;
		root->right=r;
		if(l!=NULL)
		{
			l->parent=root;
		}
		if(r!=NULL)
		{
			r->parent=root;
		}
	}
	l=ml=mr=r=NULL;
}
void search(int val)
{
	node *n=root;
	while(n->data!=val)
	{
		if(n->data>val)
		{
			if(n->left==NULL)
			break;
			if((n->left->data==val)||(n->left->data<val))
			{
				node *temp;
				temp=root->left;
				root->left=NULL;
				temp->parent=NULL;
				insertright(root);
				root=temp;
				n=temp;
			}
			else
			{
				rightrotate(root);
				node *temp;
				temp=root->left;
				root->left=NULL;
				if(temp!=NULL)
				{
					temp->parent=NULL;
					insertright(root);
					root=temp;
					n=temp;
				}
				else
				{
					n=root;
					break;
				}
			}
		}
		else
		{
			if(n->right==NULL)
			break;
			if((n->right->data==val)||(n->right->data>val))
			{
				node *temp;
				temp=root->right;
				root->right=NULL;
				temp->parent=NULL;
				insertleft(root);
				root=temp;
				n=temp;
			}
			else
			{
				leftrotate(root);
				node *temp;
				temp=root->right;
				root->right=NULL;
				if(temp!=NULL)
				{
					temp->parent=NULL;
					insertleft(root);
					root=temp;
					n=temp;
				}
				else
				{
					n=root;
					break;
				}
			}
		}
	}
	reassemble();
	
}
void insert(int val)
{
	node *n=new node;
	n->data=val;
	if(root==NULL)
	{
		root=n;
		return;
	}
	
	search(val);
	if(root->data==val)
	return;
	else if(val<root->data)
	{
		n->right=root;
		root->parent=n;
		n->left=root->left;
		if(root->left!=NULL)
		root->left->parent=n;
		
		root->left=NULL;
		root=n;
		
	}
	else
	{
		n->left=root;
		root->parent=n;
		n->right=root->right;
		if(root->right!=NULL)
		root->right->parent=n;
		
		root->right=NULL;
		root=n;
	}
}
void findmax(node *n)
{
	while(n->right!=NULL)
	n=n->right;
	
	search(n->data);
}
void deletenode(int val)
{
	if(root==NULL)
	return;
	
	search(val);
	if(root->data==val)
	{
		if((root->left==NULL)&&(root->right==NULL))
		{
			root=NULL;
			return;
		}
		
		else if(root->left==NULL)
		{
			root->right->parent=NULL;
			root=root->right;
		}
		else if(root->right==NULL)
		{
			root->left->parent=NULL;
			root=root->left;
		}
		else
		{	
			node *temp;
			temp=root->right;
			root->left->parent=NULL;
			root=root->left;
			findmax(root);
			root->right=temp;
			temp->parent=root;
		}
	}
	
}
int main()
{
	int x,t1;
	cin>>t1;
	char a;
	for(int i=0;i<t1;i++)
	{
		cin>>a>>x;
	    if(a=='i')
		{
			insert(x);
		}
		else if(a=='d')
		{
			deletenode(x);	
		}
		else if(a=='s')
		{
			search(x);	
		}
	
	}
	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl<<count1;
	return 0;
}

