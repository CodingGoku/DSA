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

Node* reverseLLop(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    Node* prev = NULL;
    Node* temp = head;
    while(temp != NULL) {
        Node* front = temp->next; // store front
        temp->next = prev; // update next
        prev = temp; // move prev ahead
        temp = front; // move temp ahead
    }
    // new head as now temp is NULL
    return prev;
}

// T : O(3N) ... O(N)-reverse, O(N)-iteration, O(N)-reverse
// S : O(1)
Node* add1toNumber(Node* head) {
    // reverse LL
    head = reverseLLop(head);
    Node* temp = head;
    // we are adding only 1 to the number
    int carry = 1;
    
    while(temp != NULL) {
        temp->data = temp->data + carry;
        if(temp->data < 10) {
            carry = 0;
            break; // no more change to the LL
        }
        else {
            temp->data = 0; // 9 + 1 = 10
            carry = 1;
        }
        temp = temp->next;
    }

    // if a carry is left in the end
    if(carry == 1) {
        Node* newHead = new Node(1);
        // reverse LL to normal
        head = reverseLLop(head);
        newHead->next = head;
        return newHead;
    }

    head = reverseLLop(head);
    return head;
}

int helper(Node* temp) {
    if(temp == NULL) return 1;

    int carry = helper(temp->next);

    temp->data = temp->data + carry;

    if(temp->data < 10) {
        return 0; // carry is 0
    }
    // otherwise temp-> data = 0 and carry = 1 (9+1 = 10)
    temp->data = 0;
    return 1; // carry is 1
}

// T : O(N)
// S : O(N) ... recursive stack space
Node* add1toNumberOP(Node* head) {
    Node* temp = head;
    int carry = helper(temp);
    if(carry == 1) {
        Node* newHead = new Node(1);
        newHead->next = head;
        return newHead;
    }
    return head;
}

int main()
{
    vector<int> arr = {9,9,9,9};
    // convert arr to LL
    Node* head = convertArr2LL(arr);
    cout<<"\nLL: ";
    print(head);

    head = add1toNumber(head);
    cout<<"\nAdd 1: ";
    print(head);

    head = convertArr2LL(arr);
    head = add1toNumberOP(head);
    cout<<"\nAdd 1 OP: ";
    print(head);
    return 0;
}