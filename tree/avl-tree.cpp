#include<bits/stdc++.h>


using namespace std;

class Node {
    public:
        int val = 0;
        Node* left = NULL;
        Node* right = NULL;
        int height = 1;
        Node(int _val) {
            val = _val;
        }
};

int getHeight ( Node* n) {

    if ( n == NULL ) return 0;

    return n->height;
} 

int getbf( Node* n ) {
    return getHeight(n->left) - getHeight(n->right);
}

Node *leftleftrotate(Node* n) {
    Node* x = n->right;
    Node* t = x->left;
    x->left = n;
    n->right = t;

    x->height = 1 + max(getHeight(x->left) , getHeight(x->right));
    n->height = 1 + max(getHeight(n->right), getHeight(n->left));

    return x;
}


Node *rightrightrotate(Node* n) {
    Node* x = n->left;
    Node* t = x->right;
    x->right = n;
    n->left = t;
    x->height = 1 + max(getHeight(x->left) , getHeight(x->right));
    n->height = 1 + max(getHeight(n->right), getHeight(n->left));
    return x;
}

Node* insert(Node* root, int key) {

    if ( root == NULL ) {
        Node* newNode = new Node(key);
        return newNode;
    }

    if ( root->val < key ) {
        root->right = insert(root->right, key);
    } else if ( root->val > key ) {
        root->left = insert(root->left, key);
    }

    int bf = getbf(root);

    // if bf is greater than the 2 the it is a left case 
    // and if the key is less than root->left->val then it is a left left case 
    if ( bf > 2 && root->left->val > key ) {
        root = rightrightrotate(root);

        return root;
    }
    // left right case then do leftleft rotate then rightright rotate
    if ( bf > 2 && root->left->val < key ) {
        root->left = leftleftrotate(root->left);

        root = rightrightrotate(root);

        return root;
    }

    if ( bf < -2 && root->right->val < key ) {
        root = leftleftrotate(root);
        return root;
    }

    if ( bf < -2 && root->right->val > key ) {
        root->right = rightrightrotate(root->right);
        root = leftleftrotate(root);

        return root;
    }

    return root;
}



void preOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preOrder(root);
    return 0;
}
