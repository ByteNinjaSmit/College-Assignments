#include <iostream>
using namespace std;

class RedBlackTree {
    enum Color { RED, BLACK };

    class Node {
    public:
        int data;
        Color color;
        Node* left;
        Node* right;
        Node* parent;

        Node(int val) {
            data = val;
            color = RED;
            left = right = parent = nullptr;
        }
    };

    Node* root;

    Node* createNode(int val) {
        return new Node(val);
    }

    void rotateLeft(Node* &root, Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr)
            y->left->parent = x;
        y->parent = x->parent;

        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node* &root, Node* y) {
        Node* x = y->left;
        y->left = x->right;
        if (x->right != nullptr)
            x->right->parent = y;
        x->parent = y->parent;

        if (y->parent == nullptr)
            root = x;
        else if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;

        x->right = y;
        y->parent = x;
    }

    void fixViolation(Node* &root, Node* z) {
        while (z != root && z->parent->color == RED) {
            Node* gp = z->parent->parent;
            if (z->parent == gp->left) {
                Node* uncle = gp->right;
                if (uncle != nullptr && uncle->color == RED) {
                    z->parent->color = BLACK;
                    uncle->color = BLACK;
                    gp->color = RED;
                    z = gp;
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        rotateLeft(root, z);
                    }
                    z->parent->color = BLACK;
                    gp->color = RED;
                    rotateRight(root, gp);
                }
            } else {
                Node* uncle = gp->left;
                if (uncle != nullptr && uncle->color == RED) {
                    z->parent->color = BLACK;
                    uncle->color = BLACK;
                    gp->color = RED;
                    z = gp;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rotateRight(root, z);
                    }
                    z->parent->color = BLACK;
                    gp->color = RED;
                    rotateLeft(root, gp);
                }
            }
        }
        root->color = BLACK;
    }

    void inorder(Node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data << " (" << (root->color == RED ? "R" : "B") << ") ";
            inorder(root->right);
        }
    }

public:
    RedBlackTree() {
        root = nullptr;
    }

    void insert(int val) {
        Node* z = createNode(val);
        Node* y = nullptr;
        Node* x = root;

        while (x != nullptr) {
            y = x;
            if (z->data < x->data)
                x = x->left;
            else
                x = x->right;
        }

        z->parent = y;
        if (y == nullptr)
            root = z;
        else if (z->data < y->data)
            y->left = z;
        else
            y->right = z;

        fixViolation(root, z);
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    RedBlackTree rbt;
    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(30);
    rbt.insert(15);
    rbt.insert(25);
    rbt.insert(5);
    rbt.insert(1);
    rbt.display();
    return 0;
}
