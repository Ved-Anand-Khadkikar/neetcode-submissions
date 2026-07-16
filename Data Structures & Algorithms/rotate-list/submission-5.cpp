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
    ListNode* moveLL(ListNode* temp, int k) {
        while (temp != NULL) {
            k--;
            if (k == 0) {
                break;
            }
            temp = temp->next;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* temp = head;
        ListNode* tail = head;
        int length = 1;
        while (tail->next != NULL) {
            tail = tail->next;
            length++;
        }
        if (k % length == 0) {
            return head;
        }
        tail->next = head;
        k = k % length;
        tail = moveLL(temp, length - k);
        head = tail->next;
        tail->next = NULL;
        return head;
    }
};