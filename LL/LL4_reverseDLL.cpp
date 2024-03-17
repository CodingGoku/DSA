#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* back;

    //constructor
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }
    //constructor if next not given
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    // as arr[0] is done so start with 1
    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
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

// T : O(N)
// S : O(1)
Node* reverseDLL(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    Node* current = head;
    Node* last = NULL;
    while(current != NULL) {
        last = current->back;
        current->back = current->next;
        current->next = last;

        // move to next node, now next is back
        current = current->back;
    }
    // last->back is the last node, which is now the new head
    return last->back;
}

int main()
{
    vector<int> arr = {2, 5, 8, 7};

    // convert arr to DLL
    Node* head = convertArr2DLL(arr);
    cout<<"\nDLL: ";
    print(head);

    // reverse DLL
    head = reverseDLL(head);
    cout<<"\nreversed DLL: ";
    print(head);

    return 0;
}