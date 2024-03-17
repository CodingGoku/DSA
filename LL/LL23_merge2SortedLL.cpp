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

// T : O(N1 + N2)
// S : O(N1 + N2)
Node* merge2SortedLL(Node* head1, Node* head2) {
    Node* t1 = head1;
    Node* t2 = head2;

    // create new LL
    Node* newHead = NULL;
    Node* t3;

    while(t1 != NULL && t2 != NULL) {
        if(t1->data < t2->data) {
            // set the head of the new LL
            if(newHead == NULL) {
                newHead = t1;
                t3 = newHead;
            }
            else {
                t3->next = new Node(t1->data);
                t3 = t3->next;
            }

            t1 = t1->next;
        }
        // if(t2->data <= t1->data)
        else {
            // set the head of the new LL
            if(newHead == NULL) {
                newHead = t2;
                t3 = newHead;
            }
            else {
                t3->next = new Node(t2->data);
                t3 = t3->next;
            }

            t2 = t2->next;
        }
    }

    // if t1 is still remaining
    while(t1 != NULL) {
        t3->next = new Node(t1->data);
        t3 = t3->next;

        t1 = t1->next;
    }

    // if t2 is still remaining
    while(t2 != NULL) {
        t3->next = new Node(t2->data);
        t3 = t3->next;

        t2 = t2->next;
    }

    return newHead;
}

// T : O(N1 + N2)
// S : O(1)
Node* merge2SortedLLop(Node* head1, Node* head2) {
    Node* t1 = head1;
    Node* t2 = head2;

    // create new LL
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while(t1 != NULL && t2 != NULL) {
        if(t1->data < t2->data) {
            // update link for merging
            temp->next = t1;
            // move temp to the end till it is sorted
            temp = temp->next;

            t1 = t1->next;
        }
        // if(t2->data <= t1->data)
        else {
            // update link for merging
            temp->next = t2;
            // move temp to the end till it is sorted
            temp = temp->next;

            t2 = t2->next;
        }
    }

    // if t1 is still remaining
    // as we are just linking temp to the rest of the t1
    // we only need if-statement
    if(t1 != NULL) temp->next = t1;

    // if t2 is still remaining
    // even if t2 is null it's fine
    // as it will be the end
    else temp->next = t2;

    return dummyNode->next;
}

int main()
{
    vector<int> arr1 = {3,4,8,10};
    // convert arr to LL
    Node* head1 = convertArr2LL(arr1);
    cout<<"\nLL1: ";
    print(head1);
    vector<int> arr2 = {1,3,3,6,11,14};
    // convert arr to LL
    Node* head2 = convertArr2LL(arr2);
    cout<<"\nLL2: ";
    print(head2);

    // dont know why both are not working at the same time
    // Node* newHead = merge2SortedLL(head1, head2);
    // cout<<"\nMergedLL: ";
    // print(newHead);

    Node* newHead2 = merge2SortedLLop(head1, head2);
    cout<<"\nMergedLLop: ";
    print(newHead2);
    return 0;
}