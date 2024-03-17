#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;

    //constructor
    Node(int val1, Node* next1, Node* prev1) {
        val = val1;
        next = next1;
        prev = prev1;
    }
    //constructor if next not given
    Node(int val1) {
        val = val1;
        next = nullptr;
        prev = nullptr;
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
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}

// to normal eye it looks O(N^2) as we have nested while loops but
// the first while loop moves temp and second moves nextNode
// and nextNode moves to the Nodes that temp will not traverse
// T : O(N)
// S : O(1)
Node* removeDuplicatesFromSortedDLL(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    Node* temp = head;
    Node* nextNode = temp->next;
    // skip duplicates
    while(temp != NULL && temp->next != NULL) {
        while(nextNode != NULL && nextNode->val == temp->val) {
            Node* duplicate = nextNode;
            nextNode = nextNode->next;
            free(duplicate);
        }
        // update temp->next and nextNode->prev after skipping dupes
        temp->next = nextNode; // if nextNode is null, temp points to null (example in 3,3,3)
        if(nextNode) nextNode->prev = temp;

        // move to next node
        temp = temp->next;
    }
    // head is never changed
    return head;
}

int main()
{
    vector<int> arr = {1,1,1,2,3,3,4};
    // convert arr to DLL
    Node* head = convertArr2DLL(arr);
    cout<<"\nDLL :";
    print(head);

    head = removeDuplicatesFromSortedDLL(head);
    cout<<"\nAfter removing duplicates: ";
    print(head);

    return 0;
}