class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        
        if (root->left != nullptr && root->right != nullptr) {
            return 1 + countNodes(root->right) + countNodes(root->left);
        }
        
        if (root->right != nullptr) {
            return 1 + countNodes(root->right);
        }

        if (root->left != nullptr) {
            return 1 + countNodes(root->left);
        }
        
        return 0;
    }
};
