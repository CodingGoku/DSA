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

Node* findLastNode(Node* temp, int c) {
    c--;
    while(temp != NULL) {
        if(c == 0) return temp;
        temp = temp->next;
        c--;
    }
    return temp;
}

// Node* findLastNode(Node* temp, int k) {
//     int cnt = 1;
//     while(temp != NULL) {
//         if(cnt == k) return temp;
//         cnt++;
//         temp = temp->next;
//     }
//     return temp;
// }

Node* rotateLL(Node* head, int k) {
    if(head == NULL || k == 0) return head;

    Node* tail = head;
    int len = 1;
    while(tail->next != NULL) {
        len++;
        tail = tail->next;
    }
    cout<<"len "<<len;

    // no change if rotation is multiple of size of LL
    if(k % len == 0) return head;

    // if k value is very large
    k = k % len;

    tail->next = head;
    Node* newLastNode = findLastNode(head, len-k);
    head = newLastNode->next;
    newLastNode->next = NULL;

    return head;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8};
    // convert arr to LL
    Node* head = convertArr2LL(arr);
    cout<<"\nLL: ";
    print(head);

    head = rotateLL(head, 2);
    cout<<"\nRotate by 2: ";
    print(head);
    return 0;
}