// LC_199.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
  
};

void helper(TreeNode* root, vector<int>& vals, int depth) {
  if (root == nullptr) return;

  if (vals.size() <= depth) {
    vals.push_back(root->val);
  }

  helper(root->right, vals, depth + 1);
  helper(root->left, vals, depth + 1);
}

vector<int> rightSideView(TreeNode* root) {
  vector<int> vals;
  helper(root, vals, 0);
  return vals;
}

int main()
{
    // test here
}
