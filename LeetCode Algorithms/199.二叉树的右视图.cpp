/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * */
// #include<bits/stdc++.h>
// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // 层次遍历，每层最后一个节点
        if (root == nullptr) return {};
        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int len = que.size();    // 得到当前层有多少节点
            for (int i =0; i < len; ++i) {
                auto q = que.front();
                que.pop();
                if (q->left != nullptr) que.push(q->left);
                if (q->right != nullptr) que.push(q->right);
                if (i == len - 1) ans.push_back(q->val);
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    cout << 
    return 0;
}
