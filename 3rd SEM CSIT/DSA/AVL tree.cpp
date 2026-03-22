#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    int height;
};

// Utility functions
int getHeight(Node* n) {
    return (n == NULL) ? 0 : n->height;
}

int getBalance(Node* n) {
    return (n == NULL) ? 0 : getHeight(n->left) - getHeight(n->right);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* createNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

// Rotations
Node* rightRotate(Node* y) {
    cout << "Performing RIGHT ROTATION on node " << y->key << endl;

    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    cout << "Performing LEFT ROTATION on node " << x->key << endl;

    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Insert with step display
Node* insert(Node* node, int key) {

    if (node == NULL) {
        cout << "Inserted: " << key << endl;
        return createNode(key);
    }

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    // LL Case
    if (balance > 1 && key < node->left->key) {
        cout << "LL Imbalance at node " << node->key << endl;
        return rightRotate(node);
    }

    // RR Case
    if (balance < -1 && key > node->right->key) {
        cout << "RR Imbalance at node " << node->key << endl;
        return leftRotate(node);
    }

    // LR Case
    if (balance > 1 && key > node->left->key) {
        cout << "LR Imbalance at node " << node->key << endl;
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL Case
    if (balance < -1 && key < node->right->key) {
        cout << "RL Imbalance at node " << node->key << endl;
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Inorder traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int n, value;
    cout<<"----Swornim Maharjan----"<<endl;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter value " << i + 1 << ": ";
        cin >> value;

        root = insert(root, value);

        cout << "Current Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    cout << "\nFinal AVL Tree (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
