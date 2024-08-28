#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void addToHead(Node*& head, int newData) {
    Node* newNode = new Node(newData);
    newNode->next = head;
    head = newNode;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* merge(Node* a, Node* b) {
    if (a == nullptr) {
        return b;
    }
    if (b == nullptr) {
        return a;
    }

    Node* c;
    if (a->data < b->data) {
        c = a;
        c->next = merge(a->next, b);
    } else {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

Node* take_input(int n) {
    Node* head = nullptr;
    int value;
    for (int i = 0; i < n; i++) {
        cin >> value;
        addToHead(head, value);
    }
    return head;
}

ostream& operator<<(ostream &os, Node* head) {
    print(head);
    return os;
}

Node* midpoint(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* mid = midpoint(head);
    Node* half = mid->next;
    mid->next = nullptr;

    Node* left = mergeSort(head);
    Node* right = mergeSort(half);

    return merge(left, right);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n1, n2;

        cin >> n1;
        Node* head1 = take_input(n1);  // Corrected variable name

        cin >> n2;
        Node* head2 = take_input(n2);  // Corrected variable name

        Node* mergeHead1 = mergeSort(head1);  // Added "Node*" to declare the variable
        Node* mergeHead2 = mergeSort(head2);  // Added "Node*" to declare the variable

        Node* sorted = merge(mergeHead1, mergeHead2);
        print(sorted);
    }

    return 0;
}
