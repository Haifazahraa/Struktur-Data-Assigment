#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    string data;
    vector<TreeNode*> children;

    TreeNode(const string& value) : data(value) {}
};

class Tree {
private:
    TreeNode* root;

public:
    Tree() : root(nullptr) {}

    void insertNode(TreeNode* parent, const string& value) {
        TreeNode* newNode = new TreeNode(value);
        if (!root) {
            root = newNode;
            cout << "Node " << value << " berhasil ditambahkan sebagai root.\n";
        } else {
            parent->children.push_back(newNode);
            cout << "Node " << value << " berhasil ditambahkan sebagai child dari " << parent->data << ".\n";
        }
    }

    void displayChildAndDescendant(TreeNode* node) {
        if (!node) return;

        if (!node->children.empty()) {
            cout << "Node " << node->data << " memiliki child:\n";
            for (TreeNode* child : node->children) {
                cout << child->data << " ";
            }
            cout << endl;
        }

        for (TreeNode* child : node->children) {
            displayChildAndDescendant(child);
        }
    }

    TreeNode* getRoot() const {
        return root;
    }
};

int main() {
    Tree tree;
    TreeNode* parentNode = nullptr;

    int numNodes;
    cout << "Masukkan jumlah node tree: ";
    cin >> numNodes;

    for (int i = 0; i < numNodes; i++) {
        string nodeName;
        cout << "Masukkan nama node " << i + 1 << ": ";
        cin >> nodeName;

        if (!tree.getRoot()) {
            tree.insertNode(nullptr, nodeName);
            parentNode = tree.getRoot();
        } else {
            tree.insertNode(parentNode, nodeName);
        }
    }

    cout << "\nTree yang telah dibuat:\n";
    tree.displayChildAndDescendant(tree.getRoot());

    return 0;
}
