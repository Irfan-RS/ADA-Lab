/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode node;

node* getnode(int val) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void reorderList(struct ListNode* head) {
    if (!head || !head->next || !head->next->next) {
        return; 
    }

    node *temp1 = head, *temp2 = head;
    while (temp2 && temp2->next) {
        temp1 = temp1->next;
        temp2 = temp2->next->next;
    }

    node *prev = NULL, *curr = temp1->next, *next;
    temp1->next = NULL; 

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    node *first = head, *second = prev;
    while (second) {
        node *tmp1 = first->next, *tmp2 = second->next;

        first->next = second;
        second->next = tmp1;

        first = tmp1;
        second = tmp2;
    }
}
