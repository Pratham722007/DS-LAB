#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* nxt;
};

class CirQueue {
private:
    Node* frnt;
    Node* rear;

public:
    CirQueue() {
        frnt = nullptr;
        rear = nullptr;
    }

    void enq(int val) {
        Node* newNode = new Node();
        newNode->val = val;
        newNode->nxt = nullptr;

        if (isEmp()) {
            frnt = newNode;
            rear = newNode;
            newNode->nxt = frnt; // Point to itself to make the circular link
        } else {
            rear->nxt = newNode;
            rear = newNode;
            rear->nxt = frnt; // Maintain the circular link
        }
    }

    void deq() {
        if (isEmp()) {
            cout << "Queue is empty!" << endl;
        } else if (frnt == rear) { // Only one element in the queue
            delete frnt;
            frnt = nullptr;
            rear = nullptr;
        } else {
            Node* temp = frnt;
            frnt = frnt->nxt;
            rear->nxt = frnt; // Maintain the circular link
            delete temp;
        }
    }

    int peek() {
        if (isEmp()) {
            cout << "Queue is empty!" << endl;
            return -1;
        } else {
            return frnt->val;
        }
    }

    bool isEmp() {
        return frnt == nullptr;
    }
};

int main() {
    CirQueue cq;
    cq.enq(10);
    cq.enq(20);
    cq.enq(30);

    cout << "Front element: " << cq.peek() << endl; // Output should be 10
    cq.deq();
    cout << "Front element after dequeue: " << cq.peek() << endl; // Output should be 20

    return 0;
}
