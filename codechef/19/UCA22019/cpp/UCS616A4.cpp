#include<bits/stdc++.h>
using namespace std;
int zig=0;
int zigzag=0,zigzig=0;
struct NODE{
    int key;
    NODE *l;
    NODE *r;
    NODE *p;
    NODE(int d){
        key=d;
        l=NULL;
        r=NULL;
        p=NULL;
    }
};
NODE *baapu=NULL;
int h(NODE *root){
    if(root==NULL)return 0;
    int l=h(root->l);
    int r=h(root->r);

    return max(l,r)+1;
}

void rightrot(NODE *P)
{
    NODE *M=P->l;
    NODE *N=M->r;
    NODE *O=P->p;
    if(O)
    {
        if(O->r==P) O->r=M;
        else O->l=M;
    }
    if(N)
        N->p=P;
    M->p=O;
    M->r=P;
   
    P->p=M;
    P->l=N;
}
void leftrot(NODE *P)
{
    NODE *M=P->r;
    NODE *N=M->l;
    NODE *O=P->p;
    if(O)
    {
        if(O->r==P) O->r=M;
        else O->l=M;
    }
    if(N)
        N->p=P;
    M->p=O;
    M->l=P;
   
    P->p=M;
    P->r=N;
}

void bottomupsplay(NODE *root){

    while(root->p){
        if(!root->p->p){
            if(root->p->l==root){
               
                rightrot(root->p);
            }
            else{
                leftrot(root->p);
            }
            zig++;
        }
        else if(root->p->l==root && root->p->p->l==root->p){
            rightrot(root->p->p);
            rightrot(root->p);
            zigzig++;
        }
        else if(root->p->r==root && root->p->p->r==root->p){
            leftrot(root->p->p);
            leftrot(root->p);
            zigzig++;
        }
        else if(root->p->l==root && root->p->p->r==root->p){
            rightrot(root->p);
            leftrot(root->p);
            zigzag++;
        }
        else{
            leftrot(root->p);
            rightrot(root->p);
            zigzag++;
        }
    }
    baapu=root;
}

void add(int d){
    if(baapu==NULL){
        baapu=new NODE(d);
        return ;
    }
    NODE *root=baapu;
    while(1){
        if(root->key==d)break;
        if(d<root->key){
            if(root->l)root=root->l;
            else{
                NODE *temp=new NODE(d);
                temp->p=root;
                root->l=temp;
                root=root->l;
                break;
            }
        }
        else{
            if(root->r)root=root->r;
            else{
                NODE *temp=new NODE(d);
                temp->p=root;
                root->r=temp;
                root=root->r;
                break;
            }
        }
    }
    bottomupsplay(root);
}
void inorder(NODE *root){
    if(root==NULL)return;

    inorder(root->l);
    cout<<root->key<<" ";
    inorder(root->r);
}

void preorder(NODE *root){
    if(root==NULL){
     
        return;
    }
   
    cout<<root->key<<" ";
    preorder(root->l);
    preorder(root->r);
}

void postorder(NODE *root){
    if(root==NULL)return;

    postorder(root->l);
    postorder(root->r);
    cout<<root->key<<" ";
}

NODE* Search(int v)
{
    if(!baapu) return NULL;
    NODE *P=baapu;
   
    while(P)
    {
        if(P->key==v)
            break;
        if(v<(P->key))
        {
            if(P->l)
                P=P->l;
            else
                break;
        }
        else
        {
            if(P->r)
                P=P->r;
            else
                break;
        }
    }
    bottomupsplay(P);
    if(P->key==v) return P;
    else return NULL;
}
void GET_NODE(int v)
{
    if(!baapu) return;
    NODE *P=baapu;
   
    while(P)
    {
        if(P->key==v){
           
            break;
        }
           
        if(v<(P->key))
        {
            if(P->l)
                P=P->l;
            else
                break;
        }
        else
        {
            if(P->r)
                P=P->r;
            else
                break;
        }
    }
   
    bottomupsplay(P);
    baapu=P;
   
}
bool Remove(int v)
{
    NODE *N=Search(v);
    if(!N) return false;
    NODE *l=N->l;
   
    NODE *r=N->r;
   
    if(l==NULL){
        baapu=r;
         r->p=NULL;
        free(N);
    }
    else if(r==NULL){
         l->p=NULL;
        baapu=l;
        free(N);
    }
    else{
        l->p=NULL;
         r->p=NULL;
        baapu=l;
       
        while(l->r!=NULL)l=l->r; 
        bottomupsplay(l);
        l->r=r;
        r->p=l;
        baapu=l;
        free(N);
    }
    return true;
   
}
int main(){
   
    int q;
    cin>>q;
   
    while(q--){
   char c;cin>>c;
   int x;cin>>x;
   if(c=='i'){
       add(x);
   }
   else if(c=='s'){
       GET_NODE(x);
   }
   else{
       Remove(x);
   }

    }
    preorder(baapu);cout<<endl;
    inorder(baapu);cout<<endl;
    postorder(baapu);cout<<endl;
    cout<<zig<<endl;
    cout<<zigzig<<endl<<zigzag<<endl;
   

}
