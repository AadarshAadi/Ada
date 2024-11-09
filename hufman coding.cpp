#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
struct Node {
    char ch;
    int freq;
    Node *left, *right;
};

Node* nodes[MAX_SIZE];
int nodeCount = 0;

Node* createNode(char ch, int freq) {
    Node* node = new Node;
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = nullptr;
    return node;
}

void insertNode(Node* node) {
    nodes[nodeCount++] = node;
}

void buildMinHeap() {
    for (int i = nodeCount / 2 - 1; i >= 0; i--) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < nodeCount && nodes[left]->freq < nodes[smallest]->freq)
            smallest = left;
        if (right < nodeCount && nodes[right]->freq < nodes[smallest]->freq)
            smallest = right;
        
        if (smallest != i) {
            swap(nodes[i], nodes[smallest]);
            i = smallest + 1;
        }
    }
}

Node* extractMin() {
    Node* minNode = nodes[0];
    nodes[0] = nodes[--nodeCount];
    buildMinHeap();
    return minNode;
}

void generateCodes(Node* root, string str) {
    if (!root->left && !root->right) {
        cout << root->ch << ": " << str << "\n";
        return;
    }
    if (root->left) generateCodes(root->left, str + "0");
    if (root->right) generateCodes(root->right, str + "1");
}

void huffmanTree(char chars[], int freqs[], int n) {
    for (int i = 0; i < n; i++) {
        insertNode(createNode(chars[i], freqs[i]));
    }

    while (nodeCount > 1) {
        buildMinHeap();
        Node* left = extractMin();
        Node* right = extractMin();

        Node* combined = createNode('\0', left->freq + right->freq);
        combined->left = left;
        combined->right = right;
        insertNode(combined);
    }

    generateCodes(nodes[0], "");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    char chars[MAX_SIZE];
    int freqs[MAX_SIZE];
    
    cout << "Enter characters:\n";
    for (int i = 0; i < n; i++) {
        cin >> chars[i];
    }

    cout << "Enter frequencies:\n";
    for (int i = 0; i < n; i++) {
        cin >> freqs[i];
    }

    huffmanTree(chars, freqs, n);
    return 0;
}