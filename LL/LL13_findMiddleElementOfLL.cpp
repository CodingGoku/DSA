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

// T : O(N/2)
// S : O(1)
Node* middleOfLL(Node* head) {
    Node* slow = head;
    Node* fast = head;
    // for both odd and even LL cases
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    vector<int> arr1 = {1,2,3,4,5};
    // convert arr to LL
    Node* head1 = convertArr2LL(arr1);
    cout<<"\nLL1: ";
    print(head1);
    Node* t = middleOfLL(head1);
    cout<<"\nMiddle: ";
    cout<<t->data;

    vector<int> arr2 = {1,2,3,4,5,6};
    // convert arr to LL
    Node* head2 = convertArr2LL(arr2);
    cout<<"\nLL2: ";
    print(head2);
    t = middleOfLL(head2);
    cout<<"\nMiddle: ";
    cout<<t->data;
    return 0;
}