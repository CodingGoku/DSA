#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    //constructor
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    //constructor if next not given
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    // as arr[0] is done so start with 1
    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr);
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

// T : O(max(N1, N2))
// S : O(max(N1, N2))
Node* add2Numbers(Node* head1, Node* head2) {
    Node* t1 = head1;
    Node* t2 = head2;
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;
    int carry = 0;

    while(t1 != NULL || t2 != NULL) {
        int sum = carry;
        // if not NULL
        if(t1) sum += t1->data;
        if(t2) sum += t2->data;

        Node* newNode = new Node(sum%10);
        carry = sum/10;

        curr->next = newNode;
        curr = newNode;

        // if not NULL move to next node
        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;
    }

    // if carry is left after the sum
    if(carry) {
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    // dummyNode's next is the head of sum
    return dummyNode->next;
}

int main()
{

    vector<int> arr1 = {3,5};
    // convert arr to LL
    Node* head1 = convertArr2LL(arr1);
    cout<<"\nLL1: ";
    print(head1);

    vector<int> arr2 = {4,5,9,9};
    // convert arr to LL
    Node* head2 = convertArr2LL(arr2);
    cout<<"\nLL2: ";
    print(head2);

    // add 2 numbers
    Node* head = add2Numbers(head1, head2);
    cout<<"\nSUM: ";
    print(head);

    return 0;
}