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

// T : O(Len + Len-n)
// S : O(1)
Node* removeNthNodefromEnd(Node* head, int n) {
    Node* temp = head;
    int cnt = 0;

    while(temp != NULL) {
        cnt++;
        temp = temp->next;
    }

    // remove head
    if(n == cnt) {
        Node* newHead = head->next;
        free(head);
        return newHead;
    }

    // res gives 1 node before the delete node
    int res = cnt - n;
    temp = head;

    while(temp != NULL) {
        res--;
        if(res == 0) {
            Node* deleteNode = temp->next;
            temp->next = temp->next->next;
            free(deleteNode);
            break;
        }
        temp = temp->next;
    }
    return head;
}

// T : O(Len)
// S : O(1)
Node* removeNthNodefromEndFast(Node* head, int n) {
    Node* fast = head;
    for(int i=0; i<n; i++) fast = fast->next;
    // you are asked to delete head
    if(fast == NULL) return head->next;

    Node* slow = head;
    while(fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    // now slow points to 1 node prev to deleteNode
    Node* deleteNode = slow->next;
    slow->next = slow->next->next;
    free(deleteNode);

    return head;
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    // convert arr to LL
    Node* head = convertArr2LL(arr);
    cout<<"\nLL: ";
    print(head);

    head = removeNthNodefromEnd(head, 2);
    cout<<"\nDelete 2nd node from end: ";
    print(head);

    head = convertArr2LL(arr);
    head = removeNthNodefromEndFast(head, 3);
    cout<<"\nDelete 3rd node from end: ";
    print(head);
    return 0;
}