#include <iostream>

enum Color
{
    RED,
    BLACK
};

struct Node
{
    int data;
    Color color;
    Node *parent;
    Node *left;
    Node *right;

    Node(int value) : data(value), color(RED), parent(nullptr), left(nullptr), right(nullptr) {}
};

class RedBlackTree
{
private:
    Node *root;

    void leftRotate(Node *x)
    {
        Node *y = x->right;
        x->right = y->left;

        if (y->left != nullptr)
        {
            y->left->parent = x;
        }

        y->parent = x->parent;

        if (x->parent == nullptr)
        {
            root = y;
        }
        else if (x == x->parent->left)
        {
            x->parent->left = y;
        }
        else
        {
            x->parent->right = y;
        }

        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node *y)
    {
        Node *x = y->left;
        y->left = x->right;

        if (x->right != nullptr)
        {
            x->right->parent = y;
        }

        x->parent = y->parent;

        if (y->parent == nullptr)
        {
            root = x;
        }
        else if (y == y->parent->left)
        {
            y->parent->left = x;
        }
        else
        {
            y->parent->right = x;
        }

        x->right = y;
        y->parent = x;
    }

    void insertFixup(Node *z)
    {
        while (z->parent && z->parent->color == RED)
        {
            if (z->parent == z->parent->parent->left)
            {
                Node *y = z->parent->parent->right;

                if (y && y->color == RED)
                {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else
                {
                    if (z == z->parent->right)
                    {
                        z = z->parent;
                        leftRotate(z);
                    }

                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            }
            else
            {
                Node *y = z->parent->parent->left;

                if (y && y->color == RED)
                {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else
                {
                    if (z == z->parent->left)
                    {
                        z = z->parent;
                        rightRotate(z);
                    }

                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }

        root->color = BLACK;
    }

    void insert(int value)
    {
        Node *z = new Node(value);
        Node *y = nullptr;
        Node *x = root;

        while (x != nullptr)
        {
            y = x;
            if (z->data < x->data)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }

        z->parent = y;

        if (y == nullptr)
        {
            root = z;
        }
        else if (z->data < y->data)
        {
            y->left = z;
        }
        else
        {
            y->right = z;
        }

        insertFixup(z);
    }

    void inorderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

public:
    RedBlackTree() : root(nullptr) {}

    void insertValue(int value)
    {
        insert(value);
    }

    void printInorder()
    {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};

int main()
{
    RedBlackTree rbTree;

    rbTree.insertValue(7);
    rbTree.insertValue(3);
    rbTree.insertValue(18);
    rbTree.insertValue(10);
    rbTree.insertValue(22);
    rbTree.insertValue(8);
    rbTree.insertValue(11);

    std::cout << "Inorder traversal of the Red-Black Tree: ";
    rbTree.printInorder();

    return 0;
}
