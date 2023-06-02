#include <iostream>
#include "bits/stdc++.h"
using namespace std;

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     };

class Solution {
public:

    string temp = "";
    int sum = 0;

    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        dfs(root);
        return sum;
    }

    void dfs(TreeNode* cur){
        if (cur == nullptr)
            return;
        if (!cur->left && !cur->right){
            temp.push_back('0' + cur->val);
            sum += stoi(temp);
            temp.pop_back();
            return;
        }

        temp.push_back('0' + cur->val);
        dfs(cur->left);
        dfs(cur->right);
        temp.pop_back();
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
