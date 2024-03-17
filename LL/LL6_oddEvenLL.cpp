// we insert even index and then odd index values in LL

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

// T : O(2N) ... 1/2N for even, 1/2 for odd, N for updation
// S : O(N) ... for array
Node* oddEvenLL(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    vector<int> arr;
    Node* temp = head;

    // insert even index
    while(temp != NULL && temp->next != NULL) {
        arr.push_back(temp->data);
        // to go to temp->next->next, temp->next should not be NULL
        // that is why we have the above condition
        temp = temp->next->next;
    }
    // last node might have left as in above condition temp->next != NULL
    if(temp) arr.push_back(temp->data);

    // insert odd index
    temp = head->next;
    while(temp != NULL && temp->next != NULL) {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) arr.push_back(temp->data);

    // update original LL
    int i=0;
    temp = head;
    while(temp != NULL) {
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }

    return head;
}

// T : O(N) ... 2x(N/2) for even and odd
// S : O(1) ... no array
Node* oddEvenLLop(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;

    // condition in while loop for just even is enough
    // as even is always ahead of odd
    while(even != NULL && even->next != NULL) {
        odd->next = odd->next->next;
        even->next = even->next->next;
        // move to the next odd and even nodes
        odd = odd->next;
        even = even->next;
    }
    // after odd position index elements even should come
    odd->next = evenHead;

    return head;
}

int main()
{
    vector<int> arr = {3,5,6,2,1,4};
    // convert arr to LL
    Node* head = convertArr2LL(arr);
    cout<<"\nLL1: ";
    print(head);

    head = oddEvenLL(head);
    cout<<"\nEvenOddIndex: ";
    print(head);

    // optimized
    head = convertArr2LL(arr);
    head = oddEvenLLop(head);
    cout<<"\nEvenOddIndexOp: ";
    print(head);
    return 0;
}