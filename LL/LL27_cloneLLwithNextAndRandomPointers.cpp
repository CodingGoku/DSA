#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* random;

    //constructor
    Node(int data1, Node* next1, Node* random1) {
        data = data1;
        next = next1;
        random = random1;
    }
    //constructor if next not given
    Node(int data1) {
        data = data1;
        next = nullptr;
        random = nullptr;
    }
};

Node* convertArr2LL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    // as arr[0] is done so start with 1
    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, nullptr);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head) {
    Node* temp = head;
    while(temp) // or while temp != null (same thing)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

// O(2N) ... for 2 while loops of N each
// O(2N) ... N for map and N for clone LL
// (for clone LL you cannot remove the O(N) space as it is required for this question)
Node* clone(Node* head) {
    // <original, clone>
    unordered_map<Node*, Node*> map;

    Node* temp = head;
    while(temp != NULL) {
        // clone node of original
        Node* newNode = new Node(temp->data);
        // map original to clone
        map[temp] = newNode;

        temp = temp->next;
    }

    temp = head;
    while(temp != NULL) {
        Node* copyNode = map[temp];
        // map clone node to it's clone next and clone random
        // that is only present in the map
        copyNode->next = map[temp->next];
        copyNode->random = map[temp->random];

        temp = temp->next;
    }

    // clone head
    return map[head];
}

// T: O(3N) ... for 3 while loops of N each
// S: O(N) ... for clone LL (which is required)
Node* cloneOP(Node* head) {
    // insert clone nodes
    Node* temp = head;
    while(temp != NULL) {
        Node* cloneNode = new Node(temp->data);
        cloneNode->next = temp->next;
        temp-> next = cloneNode;

        temp = temp->next->next;
    }

    // point clone random pointers to their clones
    temp = head;
    while(temp != NULL) {
        Node* cloneNode = temp->next;
        cloneNode->random = temp->random->next;

        temp = temp->next->next;
    }

    // separate clone LL from original LL
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    Node* temp = head;

    while(temp != NULL) {
        res->next = temp->next;
        temp->next = temp->next->next;

        res = res->next;
        temp = temp->next;
    }

    return dummyNode->next;
}

int main()
{
    vector<int> arr = {3,4,8,10};
    // convert arr to LL
    Node* head = convertArr2LL(arr);
    cout<<"\nLL: ";
    print(head);

    return 0;
}