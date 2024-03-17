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

Node* reverse(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    // recursion
    Node* newHead = reverse(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

Node* findKthNode(Node* temp, int k) {
    k--;
    while(temp != NULL && k > 0) {
        k--;
        temp = temp->next;
    }
    // if we cannot find Kth Node, temp reaches NULL
    // and we return NULL
    return temp;
}

Node* reverseNodesInKGroupSize(Node* head, int k) {
    if(head == NULL || head->next == NULL) return head;

    Node* temp = head;
    Node* prevLast;
    while(temp != NULL) {
        Node* KthNode = findKthNode(temp, k);
        if(KthNode == NULL) {
            if(prevLast) prevLast->next = temp;
            break;
        }
        // if found Kth Node
        Node* nextNode = KthNode->next;
        KthNode->next = NULL;
        reverse(temp);
        if(temp == head) {
            head = KthNode;
        }
        else {
            prevLast->next = KthNode;
        }

        prevLast = temp;
        temp = nextNode;
    }
    return head;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8};
    // convert arr to LL
    Node* head = convertArr2LL(arr);
    cout<<"\nLL: ";
    print(head);

    head = reverseNodesInKGroupSize(head, 3);
    cout<<"\nreverseNodesInKthGroup: ";
    print(head);
    return 0;
}