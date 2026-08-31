/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    ListNode* prev = head;
    ListNode* curr = head->next;
    int index = 1; // curr starts at index 1

    int firstIdx = -1, prevIdx = -1;
    int minDist = INT_MAX, maxDist = -1;

    while (curr->next != nullptr) {
        ListNode* forward = curr->next;

        bool isMax = curr->val > prev->val && curr->val > forward->val;
        bool isMin = curr->val < prev->val && curr->val < forward->val;

        if (isMax || isMin) {
            if (firstIdx == -1) {
                firstIdx = index;   // first critical point found
            } else {
                minDist = min(minDist, index - prevIdx);
            }
            prevIdx = index;
            maxDist = index - firstIdx; // keeps updating; final value = last - first
        }

        prev = curr;
        curr = forward;
        index++;
    }

    if (firstIdx == -1 || prevIdx == firstIdx) return {-1, -1}; // fewer than 2 critical points
    return {minDist, maxDist};
}
};