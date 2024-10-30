//Ian Hernández Hernández
//A01276755


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
    void recoverTree(TreeNode* root) {
        
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;
        
        inorderTraversal(root, first, second, prev);

        if (first && second) {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    
    }

    void inorderTraversal(TreeNode* node, TreeNode*& first, TreeNode*& second, TreeNode*& prev) {
        if (!node) return;

        
        inorderTraversal(node->left, first, second, prev);


        if (prev && prev->val > node->val) {
            if (!first) {
                first = prev;
            }
            second = node;
        }
        prev = node;

  
        inorderTraversal(node->right, first, second, prev);
    }
};