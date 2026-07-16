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
    ListNode* convertToLL(vector<int> arr) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        for (int i = 0; i < arr.size(); i++) {
            ListNode* newNode = new ListNode(arr[i]);
            temp->next = newNode;
            temp = newNode;
        }
        return dummyNode->next;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        vector<int> arr;

        while (t1 != NULL) {
            arr.push_back(t1->val);
            t1 = t1->next;
        }

        while (t2 != NULL) {
            arr.push_back(t2->val);
            t2 = t2->next;
        }
        sort(arr.begin(), arr.end());

        ListNode* head = convertToLL(arr);
        return head;
    }
};
