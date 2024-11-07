#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// Node structure
struct Node {
    char symbol;
    int freq;
    Node* left;
    Node* right;

    Node(char symbol, int freq, Node* left = nullptr, Node* right = nullptr) {
        this->symbol = symbol;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
};

// Comparison object for priority queue
struct compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

// Print Huffman codes from the root
void printCodes(Node* root, string str) {
    if (!root)
        return;

    if (root->symbol != '$')
        cout << root->symbol << " -> " << str << endl;

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

int main() {
    vector<char> chars = { 'a', 'b', 'c', 'd', 'e', 'f' };
    vector<int> freqs = { 5, 9, 12, 13, 16, 45 };

    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for (int i = 0; i < chars.size(); ++i) {
        minHeap.push(new Node(chars[i], freqs[i]));
    }

    while (minHeap.size() != 1) {
        Node* left = minHeap.top();
        minHeap.pop();

        Node* right = minHeap.top();
        minHeap.pop();

        Node* top = new Node('$', left->freq + right->freq, left, right);
        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");

    return 0;
}
