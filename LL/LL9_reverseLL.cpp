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

// T : O(2N) ... for 2 iterations or while loops
// S : O(N) ... stack
Node* reverseLL(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    stack<int> st;
    Node* temp = head;
    // insert into stack
    while(temp != NULL) {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    // update LL with stack top
    while(temp != NULL) {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

// T : O(N)
// S : O(1)
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

// T : O(N)
// S : O(N) ... recursive stack space
Node* reverseLLsop(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    // recursion
    Node* newHead = reverseLLsop(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    // convert arr to LL
    Node* head = convertArr2LL(arr);
    cout<<"\nLL: ";
    print(head);

    head = reverseLL(head);
    cout<<"\nreverse: ";
    print(head);

    // optimized
    head = convertArr2LL(arr);
    head = reverseLLop(head);
    cout<<"\nreverseLLop: ";
    print(head);

    // super optimized recursive
    head = convertArr2LL(arr);
    head = reverseLLsop(head);
    cout<<"\nreverseLLsop: ";
    print(head);
    return 0;
}