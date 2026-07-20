/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    // Step 1: Store parent of every node
    void mapParentNodes(TreeNode* root,
                        unordered_map<TreeNode*, TreeNode*>& parentMap) {

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                parentMap[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }
    }

    // Step 2: BFS starting from target
    vector<int> bfsFromTarget(TreeNode* target,
                              unordered_map<TreeNode*, TreeNode*>& parentMap,
                              int k) {

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int currentLevel = 0;

        while (!q.empty()) {

            int size = q.size();

            if (currentLevel++ == k)
                break;

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                // Left child
                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }

                // Right child
                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }

                // Parent
                if (parentMap.count(node) &&
                    !visited.count(parentMap[node])) {

                    visited.insert(parentMap[node]);
                    q.push(parentMap[node]);
                }
            }
        }

        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        if (root == NULL)
            return {};

        unordered_map<TreeNode*, TreeNode*> parentMap;

        // Build parent mapping
        mapParentNodes(root, parentMap);

        // BFS from target
        return bfsFromTarget(target, parentMap, k);
    }
};