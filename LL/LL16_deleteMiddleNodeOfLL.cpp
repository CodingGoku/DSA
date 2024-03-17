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
Node* deleteMiddleNode(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    // if we dont give fast a head start then slow will point to the middle
    // but we want it to point to the node before the middle
    fast = fast->next->next;

    // for odd and even length LL
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // now slow points to the node before the middle node
    Node* middle = slow->next;
    slow->next = slow->next->next;
    free(middle);

    return head;
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    // convert arr to LL
    Node* head = convertArr2LL(arr);
    cout<<"\nLL: ";
    print(head);

    head = deleteMiddleNode(head);
    cout<<"\nafter deleting middle: ";
    print(head);
    return 0;
}