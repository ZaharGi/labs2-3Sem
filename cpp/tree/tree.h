#ifndef TREE_H
#define TREE_H

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : value(v), left(nullptr), right(nullptr) {}
};

class Tree {
private:
    TreeNode* root;
    void destroy(TreeNode* node);
public:
    Tree();
    ~Tree();
    void insert(int v);
    TreeNode* getRoot() const { return root; }
};

TreeNode* insertNode(TreeNode* root, int v);
bool isAVL(TreeNode* root);
#endif
