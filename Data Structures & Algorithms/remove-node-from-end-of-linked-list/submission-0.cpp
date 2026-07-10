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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return head;
        }
        ListNode* temp = head;
        int length = 0;
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }
        temp = head;
        if (length == n) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }
        int result = length - n - 1;
        while (result != 0) {
            result--;
            temp = temp->next;
        }
        ListNode* deleteNode = temp->next;
        temp->next = temp->next->next;
        delete deleteNode;
        return head;
    }
};
