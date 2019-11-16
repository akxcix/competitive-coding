#include <bits/stdc++.h>
using namespace std;

enum COLOR { r, b };

struct stuc_node {

int key;
COLOR color;
stuc_node *left, *right, *parent;

stuc_node(int key) : key(key) {
parent = left = right = NULL;
color = r;
}

stuc_node *uncle() {
if (parent == NULL or parent->parent == NULL)
return NULL;
if (parent->isOnLeft())
return parent->parent->right;
else
return parent->parent->left;
}

bool isOnLeft() { return this == parent->left; }

 
stuc_node *sibling() {  
if (parent == NULL)
return NULL;
if (isOnLeft())
return parent->right;
return parent->left;
}

void moveDown(stuc_node *nParent) {
if (parent != NULL) {
if (isOnLeft()) {
parent->left = nParent;
} else {
parent->right = nParent;
}
}
nParent->parent = parent;
parent = nParent;
}

bool hasrChild() {
return (left != NULL and left->color == r) or
(right != NULL and right->color == r);
}
};




class tree {
stuc_node *root;


void leftRotate(stuc_node *x) {

stuc_node *nParent = x->right;

if (x == root)
root = nParent;

x->moveDown(nParent);
x->right = nParent->left;
if (nParent->left != NULL)
nParent->left->parent = x;
nParent->left = x;
}

void rightRotate(stuc_node *x) {
stuc_node *nParent = x->left;
if (x == root)
root = nParent;
x->moveDown(nParent);
x->left = nParent->right;
if (nParent->right != NULL)
nParent->right->parent = x;
nParent->right = x;
}

void swapColors(stuc_node *x1, stuc_node *x2) {
COLOR temp;
temp = x1->color;
x1->color = x2->color;
x2->color = temp;
}

void swapkeyues(stuc_node *u, stuc_node *v) {
int temp;
temp = u->key;
u->key = v->key;
v->key = temp;
}

void fixrr(stuc_node *x) {

if (x == root) {
x->color = b;
return;
}

stuc_node *parent = x->parent, *grandparent = parent->parent, *uncle = x->uncle();

if (parent->color != b) {
if (uncle != NULL && uncle->color == r) {
parent->color = b;
uncle->color = b;
grandparent->color = r;
fixrr(grandparent);
} else {

if (parent->isOnLeft()) {
if (x->isOnLeft()) {
swapColors(parent, grandparent);
} else {
leftRotate(parent);
swapColors(x, grandparent);
}

rightRotate(grandparent);
} else {
if (x->isOnLeft()) {

rightRotate(parent);
swapColors(x, grandparent);
} else {
swapColors(parent, grandparent);
}
leftRotate(grandparent);
}
}
}
}

stuc_node *successor(stuc_node *x) {
stuc_node *temp = x;

while (temp->left != NULL)
temp = temp->left;

return temp;
}

stuc_node *BSTreplace(stuc_node *x) {
if (x->left != NULL and x->right != NULL)
return successor(x->right);
if (x->left == NULL and x->right == NULL)
return NULL;
if (x->left != NULL)
return x->left;
else
return x->right;
}

void deletestuc_node(stuc_node *v) {
stuc_node *u = BSTreplace(v);
bool uvb = ((u == NULL or u->color == b) and (v->color == b));
stuc_node *parent = v->parent;

if (u == NULL) {
if (v == root) {

root = NULL;
} else {
if (uvb) {

fixDoubleb(v);
} else {

if (v->sibling() != NULL)

v->sibling()->color = r;
}


if (v->isOnLeft()) {
parent->left = NULL;
} else {
parent->right = NULL;
}
}
delete v;
return;
}

if (v->left == NULL or v->right == NULL) {

if (v == root) {

v->key = u->key;
v->left = v->right = NULL;
delete u;
} else {

if (v->isOnLeft()) {
parent->left = u;
} else {
parent->right = u;
}
delete v;
u->parent = parent;
if (uvb) {

fixDoubleb(u);
} else {

u->color = b;
}
}
return;
}


swapkeyues(u, v);
deletestuc_node(u);
}

void fixDoubleb(stuc_node *x) {
if (x == root)

return;

stuc_node *sibling = x->sibling(), *parent = x->parent;
if (sibling == NULL) {

fixDoubleb(parent);
} else {
if (sibling->color == r) {

parent->color = r;
sibling->color = b;
if (sibling->isOnLeft()) {

rightRotate(parent);
} else {

leftRotate(parent);
}
fixDoubleb(x);
} else {

if (sibling->hasrChild()) {

if (sibling->left != NULL and sibling->left->color == r) {
if (sibling->isOnLeft()) {

sibling->left->color = sibling->color;
sibling->color = parent->color;
rightRotate(parent);
} else {

sibling->left->color = parent->color;
rightRotate(sibling);
leftRotate(parent);
}
} else {
if (sibling->isOnLeft()) {

sibling->right->color = parent->color;
leftRotate(sibling);
rightRotate(parent);
} else {

sibling->right->color = sibling->color;
sibling->color = parent->color;
leftRotate(parent);
}
}
parent->color = b;
} else {

sibling->color = r;
if (parent->color == b)
fixDoubleb(parent);
else
parent->color = b;
}
}
}
}

void gc(int m){
if(m==0)
cout << "R";
else
cout << "B";
}

void inorder(stuc_node *x) {
if (x == NULL)
return;
inorder(x->left);
cout << x->key <<" ";
gc(x->color);
cout<<  " ";
inorder(x->right);
}

void preorder(stuc_node *x) {
if (x == NULL)
return;
cout << x->key << " ";
gc(x->color);
cout<<  " ";
preorder(x->left);
preorder(x->right);
}

void postorder(stuc_node *x) {
if (x == NULL)
return;
postorder(x->left);
postorder(x->right);
cout << x->key <<" ";
gc(x->color);
cout<<  " ";  
}

public:

tree() { root = NULL; }

stuc_node *getRoot() { return root; }
stuc_node *search(int n) {
stuc_node *temp = root;
while (temp != NULL) {
if (n < temp->key) {
if (temp->left == NULL)
break;
else
temp = temp->left;
} else if (n == temp->key) {
break;
} else {
if (temp->right == NULL)
break;
else
temp = temp->right;
}
}

return temp;
}


void insert(int n) {
stuc_node *newstuc_node = new stuc_node(n);
if (root == NULL) {

newstuc_node->color = b;
root = newstuc_node;
} else {
stuc_node *temp = search(n);

if (temp->key == n) {

return;
}


newstuc_node->parent = temp;

if (n < temp->key)
temp->left = newstuc_node;
else
temp->right = newstuc_node;

fixrr(newstuc_node);
}
}


void deleteBykey(int n) {
if (root == NULL)
return;

stuc_node *v = search(n), *u;
if (v->key != n) {
return;
}

deletestuc_node(v);
}


void printInOrder() {
if (root == NULL) ;
else
inorder(root);
cout << endl;
}

void printPreOrder() {
if (root == NULL) ;
else
preorder(root);
cout << endl;
}

void printPostOrder() {
if (root == NULL) ;
else
postorder(root);
cout << endl;
}

};

int main() {
tree struc_tree;
int t;
cin >> t;

while(t--){
char c;
int num;
cin >> c >> num;
switch(c){
case'i':
struc_tree.insert(num);break;
case'd':
struc_tree.deleteBykey(num);break;
}
}
struc_tree.printPreOrder();
struc_tree.printInOrder();
struc_tree.printPostOrder();
return 0;
}
