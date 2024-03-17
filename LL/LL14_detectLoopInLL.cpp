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

// T : O(Nx2x_) for map.find() depending on maps time complexity
// S : O(N)
bool detectLoop(Node* head) {
    unordered_map<Node*, int> map;
    Node* temp = head;
    // it will reach NULL if it is not a loop and return false;
    while(temp != NULL) {
        // it is a loop as the node is repeating
        if(map.find(temp) != map.end()) return true;

        map[temp] = 1;
        temp = temp -> next;
    }

    return false;
}

// T : around O(N) ... we cannot pin-point
// S : O(1)
bool detectLoopOP(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // if not a loop for even and odd size LL
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // loop is present
        if(slow == fast) return true;
    }
    return false;
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    // convert arr to LL
    Node* head = convertArr2LL(arr);

    //creating loop
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    Node* tail = temp;
    tail->next = head;

    cout<<"\nisLoop: ";
    cout<<detectLoop(head);

    cout<<"\nisLoopOP: ";
    cout<<detectLoopOP(head);
    return 0;
}