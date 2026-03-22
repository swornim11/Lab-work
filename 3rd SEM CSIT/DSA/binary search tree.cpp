#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int val) {

    if(root == NULL) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void inorder(Node* root) {
    if(root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {

    Node* root = NULL;
    int n, value;

    cout<<"===== Swornim Maharjan =====\n";
    cout<<"=== Binary Search Tree ===\n";

    cout<<"Enter number of elements: ";
    cin>>n;

    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++) {
        cin>>value;
        root = insert(root, value);
    }

    cout<<"\nBST Traversal:\n";
    inorder(root);

    return 0;
}
