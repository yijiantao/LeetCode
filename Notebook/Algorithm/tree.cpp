#include <iostream>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // TreeNode() : val(0), left(nullptr), right(nullptr) {}
    // TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode *createTree(std::vector<int> tree) {
        TreeNode *root;
        return root;
    }

    // 前序遍历
    void preorder(TreeNode *root, std::vector<int> &res) {
        if (root == nullptr)
            return;
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }
    std::vector<int> preorderTraversal(TreeNode *root) {
        std::vector<int> res{};
        preorder(root, res);
        return res;
    }

    // 中序遍历

    // 后序遍历
};

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int>> descriptions = {{20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};
    Solution s;
    std::vector<int> ans{};
    ans = s.preorderTraversal();
    for (auto _v : ans) {
        std::cout << _v << ' ';
    }
    return 0;
}
