/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return root;

        // Start from the leftmost node of each level
        Node* leftMost = root;

        // Stop before reaching the leaf level
        while (leftMost->left != NULL) {

            Node* curr = leftMost;

            // Traverse current level using next pointers
            while (curr != NULL) {

                // Connect left child to right child
                curr->left->next = curr->right;

                // Connect right child to next node's left child
                if (curr->next != NULL) {
                    curr->right->next = curr->next->left;
                }

                // Move to next node in the current level
                curr = curr->next;
            }

            // Move to the next level
            leftMost = leftMost->left;
        }

        return root;
    }
};