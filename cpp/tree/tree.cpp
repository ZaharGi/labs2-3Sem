#include "tree.h"
#include <algorithm>
#include <cmath>
using namespace std;

Tree::Tree() : root(nullptr) {}

Tree::~Tree() { 
    destroy(root); 
}

void Tree::destroy(TreeNode* node) {
    if (!node) return;
    destroy(node->left); 
    destroy(node->right); 
    delete node;
}

TreeNode* insertNode(TreeNode* root, int v) {
    if (!root) return new TreeNode(v);
    if (v < root->value) root->left = insertNode(root->left, v);
    else if (v > root->value) root->right = insertNode(root->right, v);
    return root;
}

void Tree::insert(int v) { 
    root = insertNode(root, v); 
}

int checkAVLHelper(TreeNode* root, bool& isBalanced) {
    if (!root) return 0;
    
    int leftH = checkAVLHelper(root->left, isBalanced);
    int rightH = checkAVLHelper(root->right, isBalanced);
    
    if (abs(leftH - rightH) > 1) isBalanced = false;
    
    return max(leftH, rightH) + 1;
}

bool isAVL(TreeNode* root) {
    bool balanced = true;
    checkAVLHelper(root, balanced);
    return balanced;
}
