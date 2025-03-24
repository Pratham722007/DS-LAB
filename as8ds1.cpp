#include <iostream>
using namespace std;

struct Node {
    int val;
    int pri;
    Node* nxt;
};

class PrioQueue {
private:
    Node* frnt;

public:
    PrioQueue() {
        frnt = nullptr;
    }

    void enq(int val, int pri) {
        Node* newNode = new Node();         //   10  20  30  40 50  null
        newNode->val = val;                       
        newNode->pri = pri;                //    5  4   2  1   3  
        newNode->nxt = nullptr;

        if (isEmp() || frnt->pri < pri) {
            newNode->nxt = frnt;
            frnt = newNode;
        } else {
            Node* temp = frnt;
            while (temp->nxt != nullptr && temp->nxt->pri >= pri) {
                temp = temp->nxt;
            }
            newNode->nxt = temp->nxt;
            temp->nxt = newNode;
        }
    }

    void deq() {
        if (isEmp()) {
            cout << "Queue is empty!" << endl;
        } else {
            Node* temp = frnt;
            frnt = frnt->nxt;
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

    bool isFul() {
        return false;
    }

    bool isEmp() {
        return frnt == nullptr;
    }
};

int main() {
    PrioQueue pq;
    pq.enq(10, 2);
    pq.enq(20, 1);
    pq.enq(30, 3);

    cout << "Front element: " << pq.peek() << endl;
    pq.deq();
    cout << "Front element after dequeue: " << pq.peek() << endl; 

    return 0;
}
