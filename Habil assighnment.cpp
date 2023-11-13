#include<iostream>
using namespace std;

class node {
public:
    int val;
    node* next;

    //constructor
    node(int data) {
        val = data;
        next = NULL;
    }
};

void inshead(node* &head, int val) {
    node* new_node = new node(val);
    new_node->next = head;
    head = new_node;
}

void insend(node* &head, int val) {
    node* new_node = new node(val);
    if (head == NULL) {
        head = new_node;
        return;
    }
    node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void insatn(node* &head, int val, int n) {
    node* new_node = new node(val);
    if (n == 1 || head == NULL) {
        new_node->next = head;
        head = new_node;
        return;
    }
    node* current = head;
    for (int i = 1; i < n - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        cout << "Invalid position. Inserting at the end." << endl;
        insend(head, val);
    } else {
        new_node->next = current->next;
        current->next = new_node;
    }
}

void delhead(node* &head) {
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
}

void delend(node* &head) {
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    delete current->next;
    current->next = NULL;
}

void delatn(node* &head, int n) {
    if (n == 1 || head == NULL) {
        delhead(head);
        return;
    }
    node* current = head;
    for (int i = 1; i < n - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) {
        cout << "Invalid position. Deleting from the end." << endl;
        delend(head);
    } else {
        node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

bool search(node* head, int key) {
    node* temp = head;
    while (temp != NULL) {
        if (temp->val == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void updateatn(node* head, int n, int newVal) {
    node* current = head;
    for (int i = 1; i < n && current != NULL; i++) {
        current = current->next;
    }
    if (current != NULL) {
        current->val = newVal;
        cout << "Value at position " << n << " updated to " << newVal << endl;
    } else {
        cout << "Invalid position." << endl;
    }
}

void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    node* head = NULL;

    insend(head, 1);
    display(head);
    insend(head, 2);
    display(head);
    insend(head, 5);
    display(head);
    insend(head, 8);
    display(head);
    inshead(head, 8);
    display(head);

    cout << "Search 8: " << search(head, 8) << endl;

    insatn(head, 3, 2);
    display(head);

    updateatn(head, 3, 10);
    display(head);

    delhead(head);
    display(head);

    delend(head);
    display(head);

    delatn(head, 2);
    display(head);

    updateatn(head, 5, 20);

    return 0;
}
