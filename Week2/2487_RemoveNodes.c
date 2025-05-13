/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNodes(struct ListNode* head) {
    if (!head || !head->next)
        return head;

    struct ListNode* nextNode = removeNodes(head->next);

    if (nextNode && head->val < nextNode->val) {
        free(head);
        return nextNode;
    }

    head->next = nextNode;
    return head;
}
