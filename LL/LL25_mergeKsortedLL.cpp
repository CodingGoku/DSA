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

// T : O(KxN + M + MlogM + M) ... KxN for traversing K LL of size N each and storing in arr (M = KxN = total data),
// MlogM for sorting arr, M for converting arr to LL
// S : O(2M) ... M for arr and M for mergedLL
Node* mergeKsortedLL(vector<Node*> v) {
    // to store the data of all the LL
    vector<int> arr;

    for(int i=0; i<v.size(); i++) {
        // temp points to the head of the next LL
        Node* temp = v[i];
        while(temp != NULL) {
            arr.push_back(temp->data);

            temp = temp->next;
        }
    }

    // sort arr
    sort(begin(arr), end(arr));

    // convert arr to a LL
    Node* head = convertArr2LL(arr);
    return head;
}

// from LL23
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

// T : O(Nx(Kx(K+1))/2) ... merge2sorted takes N1 + N2,
// our merge : N1+N2, (N1+N2)+N3, (N1+N2+N3)+N4, ... , assume all LL of size N
// 2N + 3N + 4N ..., adding 1 more N wont matter that much
// 1N + 2N + 3N + 4N + ... + KN
// N (1+2+3+4+ ... + k)
// N (Kx(K+1))/2)
// S : O(1) ... we are just updating the pointers
Node* mergeKsortedLLop(vector<Node*> v) {
    Node* head = v[0];
    for(int i=1; i<v.size(); i++) {
        head = merge2SortedLLop(head, v[i]);
    }

    return head;
}

// T : O(KlogK + KxNx(3logK)) ... KlogK for inserting K elements in pq (inserting 1 takes logN), while loop runs for KxN (all nodes)
// and we have 3 operations in the while loop pq.top(), pq.pop(), pq.push(), each taking logK
// so complete while loop takes KxNx(3logK)
// S : O(K) ... priority queue
Node* mergeKsortedLLsop(vector<Node*> v) {

    priority_queue<pair<int, Node*>,
    vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
    // insert heads of all LLs in pq
    for(int i=0; i<v.size(); i++) {
        // first check if LL head (i.e. v[i]) is not NULL
        if(v[i]) pq.push({v[i]->data, v[i]});
    }

    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        temp->next = it.second;
        temp = temp->next;

        // after pop we need to add the next node of that LL to pq if it is not null
        if(it.second->next) pq.push({it.second->next->data, it.second->next});
    }

    return dummyNode->next;
}

int main()
{
    vector<int> arr1 = {3,4,8,10};
    // convert arr to LL
    Node* head1 = convertArr2LL(arr1);
    cout<<"\nLL1: ";
    print(head1);
    vector<int> arr2 = {1,3,3,6,11,14};
    // convert arr to LL
    Node* head2 = convertArr2LL(arr2);
    cout<<"\nLL2: ";
    print(head2);
    vector<int> arr3 = {2,4,8};
    // convert arr to LL
    Node* head3 = convertArr2LL(arr3);
    cout<<"\nLL3: ";
    print(head3);
    vector<int> arr4 = {5,7,9};
    // convert arr to LL
    Node* head4 = convertArr2LL(arr4);
    cout<<"\nLL4: ";
    print(head4);

    // vector of heads of LLs
    vector<Node*> v;
    v.push_back(head1);
    v.push_back(head2);
    v.push_back(head3);
    v.push_back(head4);

    Node* head = mergeKsortedLL(v);
    cout<<"\nMergedLL: ";
    print(head);

    // commented as it will update the links already for next function
    // Node* headnew = mergeKsortedLLop(v);
    // cout<<"\nMergedLLop: ";
    // print(headnew);

    Node* headnew2 = mergeKsortedLLop(v);
    cout<<"\nMergedLLsop: ";
    print(headnew2);
    return 0;
}