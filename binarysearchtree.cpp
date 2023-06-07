#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    void create();
    Node* insert(Node* root, int value);
    void inorder(Node* root);
    void preorder(Node* root);
    void postorder(Node* root);
};

void BST::create() {
    int value;
    cout << "Enter data (-1 to stop): ";
    cin >> value;

    while (value != -1) {
        root = insert(root, value);
        cout << "Enter data (-1 to stop): ";
        cin >> value;
    }
}

Node* BST::insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

void BST::inorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void BST::preorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void BST::postorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    BST bst;
    bst.create();

    cout << "Inorder traversal: ";
    bst.inorder(bst.root);
    cout << endl;

    cout << "Preorder traversal: ";
    bst.preorder(bst.root);
    cout << endl;

    cout << "Postorder traversal: ";
    bst.postorder(bst.root);
    cout << endl;

    return 0;
}
/*
//search a value
Node* search(Node* root, int value) {
    if (root == nullptr || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
    // Tree construction code...

    int key;
    cout << "Enter a value to search: ";
    cin >> key;

    Node* result = search(root, key);
    if (result != nullptr) {
        cout << "Value found in the tree!" << endl;
    } else {
        cout << "Value not found in the tree!" << endl;
    }

    return 0;
}
*/