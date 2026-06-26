class Solution {
public:
    unordered_map<int, int> mp;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int left, int right) {
        if (left > right)
            return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int idx = mp[rootVal];

        root->left = build(preorder, inorder, left, idx - 1);
        root->right = build(preorder, inorder, idx + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};