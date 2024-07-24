#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
    int val = 0;
    Node* next = nullptr;

    Node(int _val) {
        val = _val;
    }
};

Node* reversell(Node* head) {
    Node* prev = NULL;
    Node* next = NULL;
    Node* curr = head;

    while ( curr ) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void print(Node* head) {

    Node* curr = head;

    while ( curr ) {
        cout << curr->val <<" ";
        curr = curr->next;
    }
    cout << endl;

}

int main () {

    Node* head = new Node(10);

    Node* temp = head;

    for ( auto i = 1; i < 10; i++ ) {
        head->next = new Node(i*rand()/1e7);
        head = head->next;
    }

    print(temp);

    temp = reversell(temp);

    print(temp);


}