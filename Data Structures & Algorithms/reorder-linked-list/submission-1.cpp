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
    ListNode* reverseLL(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* merge2LL(ListNode* i, ListNode* j) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while (i != NULL && j != NULL) {
            temp->next = i;
            temp = j;
            ListNode* iNext = i->next;
            i->next = j;
            ListNode* jNext = j->next;
            j->next = iNext;
            i = iNext;
            j = jNext;
        }
        if (i == NULL) {
            temp->next = j;
        } else {
            temp->next = i;
        }
        return dummyNode->next;
    }

    void reorderList(ListNode* head) {
        ListNode* temp = head;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* newHead = reverseLL(slow->next);
        slow->next = NULL;
        ListNode* i = head;
        ListNode* j = newHead;
        merge2LL(i, j);
    }
};
