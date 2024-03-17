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

// T : O(2N) ... for 2 while loops
// S : O(1)
Node* sortLLof012(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    Node* temp = head;
    // T: O(N)
    while(temp != NULL) {
        // count 0,1,2
        if(temp->data == 0) cnt0++;
        else if(temp->data == 1) cnt1++;
        else cnt2++;

        temp = temp->next;
    }

    temp = head;
    // T: O(N)
    while(temp != NULL) {
        // update LL
        if(cnt0) {
            temp->data = 0;
            cnt0--;
        }
        else if(cnt1) {
            temp->data = 1;
            cnt1--;
        }
        else {
            temp->data = 2;
            cnt2--;
        }

        temp = temp->next;
    }
    return head;
}

// optimized
// T : O(N)
// S : O(1)
Node* sortLLof012op(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    Node* zeroHead = new Node(-1);
    Node* zero = zeroHead;
    Node* oneHead = new Node(-1);
    Node* one = oneHead;
    Node* twoHead = new Node(-1);
    Node* two = twoHead;

    Node* temp = head;
    while(temp != NULL) {
        if(temp->data == 0) {
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data == 1) {
            one->next = temp;
            one = temp;
        }
        else {
            two->next = temp;
            two = temp;
        }

        // move to next node
        temp = temp->next;
    }

    // zero's next will be oneHead's next if it is not NULL else twoHead's next
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    // one's next is twoHead's next even if it is NULL no problem as it is end
    one->next = twoHead->next;
    // two's next should be null to stop it
    two->next = NULL;

    Node* newHead = zeroHead->next;
    // delete dummyNodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
}

int main()
{

    vector<int> arr = {1,2,0,1,1,2,1,2,0};
    // convert arr to LL
    Node* head = convertArr2LL(arr);
    cout<<"\nLL: ";
    print(head);

    head = sortLLof012(head);
    cout<<"\nsorted: ";
    print(head);

    // optimized
    head = convertArr2LL(arr);
    head = sortLLof012op(head);
    cout<<"\nsortedOP: ";
    print(head);
    return 0;
}