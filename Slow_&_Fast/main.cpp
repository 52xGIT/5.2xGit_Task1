#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == NULL)
            head = newNode;
        else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void createLoop(int pos) {
        Node* temp = head;
        Node* loopNode = NULL;
        int count = 1;
        while (temp->next != NULL) {
            if (count == pos)
                loopNode = temp;
            temp = temp->next;
            count++;
        }
        temp->next = loopNode;
    }

    bool detectLoop() {
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                cout << "Loop found" << endl;
                return true;
            }
        }

        cout << "No loop found" << endl;
        return false;
    }
};

int main() {
    LinkedList list;

    for (int i = 1; i <= 5; i++)
        list.insert(i);

    list.createLoop(2);

    list.detectLoop();

    return 0;
}
