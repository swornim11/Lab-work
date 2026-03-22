#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create new node
Node* createNode(int value) {
    if (value == -1) return NULL; // -1 represents NULL
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Preorder
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Postorder
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// Function to build tree using user input (level-order)
Node* buildTree() {
    int value;
    cout << "Enter root value (-1 for NULL): ";
    cin >> value;
    Node* root = createNode(value);
    if (!root) return NULL;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        int leftVal, rightVal;
        cout << "Enter left child of " << curr->data << " (-1 for NULL): ";
        cin >> leftVal;
        curr->left = createNode(leftVal);
        if (curr->left) q.push(curr->left);

        cout << "Enter right child of " << curr->data << " (-1 for NULL): ";
        cin >> rightVal;
        curr->right = createNode(rightVal);
        if (curr->right) q.push(curr->right);
    }

    return root;
}

int main() {
    cout << "===== Swornim Maharjan =====\n";
    cout << "===== DFS Traversals =====\n";

    Node* root = buildTree();

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}
