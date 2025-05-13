/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        function<bool(TreeNode*, TreeNode*)> checkSymmetry = [&](TreeNode* leftSubtree, TreeNode* rightSubtree) -> bool {
            if (!leftSubtree && !rightSubtree) return true;
          
            if (!leftSubtree || !rightSubtree || leftSubtree->val != rightSubtree->val) return false;

            return checkSymmetry(leftSubtree->left, rightSubtree->right) && 
                   checkSymmetry(leftSubtree->right, rightSubtree->left);
        };
      
        return checkSymmetry(root, root);
    }
};
