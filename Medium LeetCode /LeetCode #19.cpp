class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* non = new ListNode(0);
        non->next = head;

        ListNode* first = non;
        ListNode* second = non;

        for (int i = 0; i < n + 1; i++) {
            first = first->next;
        }

        while (first != NULL) {
            first = first->next;
            second = second->next;
        }

        ListNode* temp = second->next;
        second->next = second->next->next;
        delete temp;

        ListNode* newHead = non->next;
        delete non;
        return newHead;
    }
};
