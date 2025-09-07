#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};

class linkedlist {
public:
    Node* head;

    linkedlist() : head(nullptr) {}

    void Append(int e) {
        Node* point = new Node(e);
        if (head == nullptr) {
            head = point;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = point;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isPalindrome() {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        Node* mid = middle(); 
        Node* secondHalf = revlist(mid); 
        Node* first = head;
        Node* second = secondHalf;
        bool palindrome = true;

        while (second != nullptr) {
            if (first->data != second->data) {
                palindrome = false;
                break;
            }
            first = first->next;
            second = second->next;
        }

        revlist(secondHalf);
        return palindrome;
    }

private:
    Node* revlist(Node* ptr) {
        Node* previous = nullptr;
        Node* current = ptr;
        Node* n = nullptr;

        while (current != nullptr) {
            n = current->next;
            current->next = previous;
            previous = current;
            current = n;
        }
        return previous;
    }

    Node* middle() {
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // if odd length, skip the middle
        if (fast != nullptr) {
            slow = slow->next;
        }

        return slow;
    }
};

int main() {
    linkedlist list;

    list.Append(1);
    list.Append(2);
    list.Append(3);
    list.Append(2);
    list.Append(1);

    list.display();

    cout << (list.isPalindrome() ? "Palindrome" : "Not Palindrome") << endl;
}
