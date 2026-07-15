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
    ListNode* findKnode(ListNode* temp, int k) {
        k--;
        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseLL(ListNode* temp) {
        ListNode* curr = temp;
        ListNode* prev = NULL;
        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        while (temp != NULL) {
            ListNode* kNode = findKnode(temp, k);
            if (kNode == NULL) {
                if (prevNode != NULL) {
                    prevNode->next = temp;
                    break;
                }
            }
            ListNode* nextNode = kNode->next;
            kNode->next = NULL;
            reverseLL(temp);
            if (temp == head) {
                head = kNode;
            } else {
                prevNode->next = kNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};
