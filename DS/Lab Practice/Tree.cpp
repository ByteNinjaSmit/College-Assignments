#include<iostream>
#include<vector>

using namespace std;

// Binary Tree
class Binary_Tree{
    public:
    int id;
    Binary_Tree* left;
    Binary_Tree* right;
    Binary_Tree(int id=0) {
        this->id = id;
        left = nullptr;
        right = nullptr;
    }

    // accept node
    void accept();

    // insert node
    void insert(int id);

    // inorder traversal
    void inorder();

    // preorder traversal
    void preorder();

    // postorder traversal
    void postorder();

    // search node
    bool search(int id);

    // delete node
    void deleteNode(int id);

    // find minimum value
    int findMin();

    // find maximum value
    int findMax();
};

// accept node
void Binary_Tree::accept(){
    cout << "Node " << id << " accepted" << endl;
}

// insert node
void Binary_Tree::insert(int id) {
    if (this->id > id) {
        if (left == nullptr) {
            left = new Binary_Tree(id);
        } else {
            left->insert(id);
        }
    } else if (this->id < id) {
        if (right == nullptr) {
            right = new Binary_Tree(id);
        } else {
            right->insert(id);
        }
    }
}

// inorder traversal
void Binary_Tree::inorder() {
    if (left != nullptr) {
        left->inorder();
    }
    cout << id << " ";
    if (right != nullptr) {
        right->inorder();
    }
}

// preorder traversal
void Binary_Tree::preorder() {
    cout << id << " ";
    if (left != nullptr) {
        left->preorder();
    }
    if (right != nullptr) {
        right->preorder();
    }
}

// postorder traversal
void Binary_Tree::postorder() {
    if (left != nullptr) {
        left->postorder();
    }
    if (right != nullptr) {
        right->postorder();
    }
    cout << id << " ";
}

// search node
bool Binary_Tree::search(int id) {
    if (this->id == id) {
        return true;
    }
    if (this->id > id && left != nullptr) {
        return left->search(id);
    }
    if (this->id < id && right != nullptr) {
        return right->search(id);
    }
    return false;
}

// delete node
void Binary_Tree::deleteNode(int id) {
    if (left != nullptr && left->id == id) {
        Binary_Tree* temp = left;
        left = nullptr;
        delete temp;
    } else if (right != nullptr && right->id == id) {
        Binary_Tree* temp = right;
        right = nullptr;
        delete temp;
    } else if (this->id > id && left != nullptr) {
        left->deleteNode(id);
    } else if (this->id < id && right != nullptr) {
        right->deleteNode(id);
    }
}

// find minimum value
int Binary_Tree::findMin() {
    if (left == nullptr) {
        return id;
    }
    return left->findMin();
}

// find maximum value
int Binary_Tree::findMax() {
    if (right == nullptr) {
        return id;
    }
    return right->findMax();
}

int main(){
    Binary_Tree tree(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "Inorder Traversal: ";
    tree.inorder();
    cout << endl;

    cout << "Preorder Traversal: ";
    tree.preorder();
    cout << endl;

    cout << "Postorder Traversal: ";
    tree.postorder();
    cout << endl;

    cout << "Search Node 4: " << (tree.search(4) ? "Found" : "Not Found") << endl;

    tree.deleteNode(4);

    cout << "Search Node 4 after deletion: " << (tree.search(4) ? "Found" : "Not Found") << endl;

    cout << "Minimum Value: " << tree.findMin() << endl;

    cout << "Maximum Value: " << tree.findMax() << endl;

    return 0;
}