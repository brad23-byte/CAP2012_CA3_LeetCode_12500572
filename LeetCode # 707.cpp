class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(NULL) {}
    };

    Node* non;
    int size;

public:
    MyLinkedList() {
        non = new Node(0);
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }

        Node* curr = non->next;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        return curr->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }

        Node* prev = non;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }

        Node* newNode = new Node(val);
        newNode->next = prev->next;
        prev->next = newNode;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }

        Node* prev = non;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }

        Node* temp = prev->next;
        prev->next = prev->next->next;
        delete temp;
        size--;
    }
};
