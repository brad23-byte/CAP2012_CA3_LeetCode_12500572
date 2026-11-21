class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* non = new ListNode(0);
        non->next = head;
        ListNode* curr = non;

        while (curr->next != NULL) {
            if (curr->next->val == val) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }

        ListNode* newHead = non->next;
        delete non;
        return newHead;
    }
};
