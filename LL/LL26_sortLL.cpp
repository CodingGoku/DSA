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

// T: O(N + NLogN + N)
// S: O(N) ... for arr
Node* sortLL(Node* head) {
    Node* temp = head;
    vector<int> arr;

    // store in arr
    while(temp != NULL) {
        arr.push_back(temp->data);

        temp = temp->next;
    }

    // sort arr
    sort(begin(arr), end(arr));

    // update the LL
    temp = head;
    for(int i=0; i<arr.size(); i++) {
        temp->data = arr[i];

        temp = temp->next;
    }

    return head;
}

Node* merge2SortedLLop(Node* head1, Node* head2) {
    Node* t1 = head1;
    Node* t2 = head2;

    // create new LL
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while(t1 != NULL && t2 != NULL) {
        if(t1->data < t2->data) {
            // update link for merging
            temp->next = t1;
            // move temp to the end till it is sorted
            temp = temp->next;

            t1 = t1->next;
        }
        // if(t2->data <= t1->data)
        else {
            // update link for merging
            temp->next = t2;
            // move temp to the end till it is sorted
            temp = temp->next;

            t2 = t2->next;
        }
    }

    // if t1 is still remaining
    // as we are just linking temp to the rest of the t1
    // we only need if-statement
    if(t1 != NULL) temp->next = t1;

    // if t2 is still remaining
    // even if t2 is null it's fine
    // as it will be the end
    else temp->next = t2;

    return dummyNode->next;
}

Node* findMiddle(Node* head) {
    Node* slow = head;
    // we want slow to stop at first middle, that is why
    // we started fast from head->next instead of head
    Node* fast = head->next;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // now slow points to middle node
    return slow;
}

// using merge sort
// T: O(logNx(N + N/2)) ... logN for merge sort and 
// at each call, N for merge2SortedLL and N/2 to find the middle
// S: O(logN) ... recursive stack space
Node* sortLLop(Node* head) {
    //base case
    if(head == NULL || head->next == NULL) return head;

    Node* middle = findMiddle(head);
    // right head
    Node* right = middle->next;
    
    // break LL into left and right
    middle->next = nullptr;

    // left head
    Node* left = head;

    left = sortLLop(left);
    right = sortLLop(right);
    return merge2SortedLLop(left, right);
}

int main()
{
    vector<int> arr = {3,4,2,1,5};
    // convert arr to LL
    Node* head = convertArr2LL(arr);
    cout<<"\nLL: ";
    print(head);

    head  = sortLL(head);
    cout<<"\nsortedLL: ";
    print(head);

    head = convertArr2LL(arr);
    head = sortLLop(head);
    cout<<"\nsortLLop: ";
    print(head);
    return 0;
}