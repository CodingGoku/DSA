#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* child;
    Node* next;

    //constructor
    Node(int data1, Node* child1, Node* next1) {
        data = data1;
        child = child1;
        next = next1;
    }
    //constructor if next not given
    Node(int data1) {
        data = data1;
        child = nullptr;
        next = nullptr;
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

// it is just flattening, not sorting
Node* flattenLL(Node* head) {
    Node* temp = head;
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    
    while(temp != NULL) {
        Node* t2 = temp;
        while(t2 != NULL) {
            temp->next = t2;
            temp = t2;

            t2 = t2->next;
        }

        temp = temp->next;
    }
    return dummyNode->next;
}

Node* merge2Lists(Node* head1, Node* head2) {
    Node* t1 = head1;
    Node* t2  = head2;
    // dummy is now vertical LL as we are storing in child
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while(t1 != NULL && t2 != NULL) {
        if(t1->data < t2->data) {
            temp->child = t1;
            temp = t1;

            t1 = t1->next;
        }
        else {
            temp->child = t2;
            temp = t2;

            t2 = t2->next;
        }
    }

    // if t1 is left merge
    if(t1) temp->child = t1;
    else temp->child = t2;

    return dummyNode->child;
}

// T : O(2NM) ... O(N) for recursion and O(M1 + M2) ~ O(2M) for merge function
// S : O(N) ... recursive stack space
Node* mergeAll(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    Node* mergeHead = mergeAll(head->next);

    return merge2Lists(mergeHead, head);
}

int main()
{
    return 0;
}