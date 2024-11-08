#include<iostream>
using namespace std;

struct Node {

    int data;
    Node *left;
    Node *right;

    Node(int val){

       data = val;
       left = NULL; 
       right = NULL;
}
};

Node* insertBST(Node *root, int val) {
    if (root == NULL) {
        return new Node(val);
    }

    if (val < root-> data){
        root -> left = insertBST(root -> left, val);
    } else {
        //val > root->data// 
        root->right = insertBST(root-> right, val);

    }
    return root;
}

void inorder(Node *root){
    if (root == NULL) {
        return;
    
    }

    inorder(root -> left);
    cout << root->data <<"";
    inorder(root->right);
}


int main(){
    Node *root = NULL;
    int n, val;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the values to insert in the BST:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insertBST(root, val);
    }

    inorder(root);
    cout << endl;

    return 0;
}