#include<iostream>
using namespace std;

class Node{
    public:
    int key;
    Node* lchild;
    Node* rchild;
    Node(int x){
        this->key = x;
        lchild=NULL;
        rchild=NULL;
    }
};

class BST{
    public:
    Node* root = new Node(-1);  // Sentinel
    void insert(Node* root,int x){
        if(root->key > x ){
            if(root->lchild == NULL){
                root->lchild = new Node(x);
            }else{
                insert(root->lchild, x);
            }
        } else{
            if(root->rchild == NULL){
                root->rchild = new Node(x);
            }else{
                insert(root->rchild, x);
            }
        }
    }
    void inorder(Node* root){
        if(root == NULL){
            return;
        }
        inorder(root->lchild);
        if(root->key == -1){
            // Ignore if sentinel
        }else{
            cout<<root->key<<" ";
        }
        inorder(root->rchild);
    }
    void preorder(Node* root){
        if(root == NULL){
            return;
        }
        if(root->key == -1){
            // Ignore if sentinel
        }else{
            cout<<root->key<<" ";
        }
        preorder(root->lchild);
        preorder(root->rchild);
    }
    void postorder(Node* root){
        if(root == NULL){
            return;
        }
        postorder(root->lchild);
        postorder(root->rchild);
        if(root->key == -1){
            // Ignore if sentinel
        }else{
            cout<<root->key<<" ";
        }
    }
    void search(Node* root, int x){
        if(root == NULL){
            cout<<"Not Found"<<endl;
        }
        else if(root->key == x){
            cout<<"Found "<<x<<endl;
        }
        else if(x > root->key){
            search(root->rchild, x);
        }
        else if(x < root->key){
            search(root->lchild, x);
        }
    }

};

int main(){
    cout<<"How many numbers? ";
    int n;
    cin>>n;
    int temp;
    BST tree;
    for(int i=0; i<n;i++){
        cout<<"Enter number: ";
        cin>>temp;
        tree.insert(tree.root, temp);
    }
    cout<<"In order traversal:"<<endl;
    tree.inorder(tree.root); cout<<endl;
    tree.preorder(tree.root); cout<<endl;
    tree.postorder(tree.root); cout<<endl;
    cout<<"How many searches? ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter value to search: ";
        cin>>temp;
        tree.search(tree.root, temp);
    }
    return 0;
}