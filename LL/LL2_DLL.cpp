#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* back;

    //constructor
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }
    //constructor if next not given
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

void print(Node* head) {
    Node* temp = head;
    while(temp) // or while temp != null (same thing)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

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

Node* deleteHead(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;

    Node* prev = head;
    head = head->next;
    head->back = NULL;
    prev->next = NULL;

    delete prev;
    return head;
}

Node* deleteTail(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;

    Node* tail = head;
    // move to the last node
    while(tail->next != NULL) {
        tail = tail->next;
    }
    Node* newTail = tail->back;
    newTail->next = NULL;
    tail->back = NULL;
    delete tail;

    return head;
}

Node* removeElementAtPos(Node* head, int pos) {
    if(head == NULL) return NULL;

    int cnt = 0;
    Node* posNode = head;
    while(posNode != NULL) {
        cnt++;
        if(cnt == pos) break;
        posNode = posNode->next;
    }
    Node* prev = posNode->back;
    Node* front = posNode->next;

    // single node is present in DLL
    if(prev == NULL && front == NULL) {
        delete posNode;
        return NULL;
    }
    // head is to be deleted
    if(prev == NULL) {
        return deleteHead(head);
    }
    // tail is to be deleted
    if(front == NULL) {
        return deleteTail(head);
    }
    // delete any middle element
    prev->next = front;
    front->back = prev;
    posNode->next = NULL;
    posNode->back = NULL;
    delete posNode;

    return head;
}

void deleteNode(Node* temp) {
    Node* prev = temp->back;
    Node* front = temp->next;

    // you will not be asked to delete the head
    // as here we are not returning the head
    // and if we delete the head, then we won't
    // be able to access the new head

    // delete the tail
    if(front == NULL) {
        prev->next = NULL;
        temp->back = NULL;
        delete temp;
        return;
    }
    // if the node is in the middle
    prev->next = front;
    front->back = prev;

    temp->next = temp->back = NULL;
    delete temp;
}

Node* insertBeforeHead(Node* head, int val) {
    Node* newHead = new Node(val, head, nullptr); // next is head, back is nullptr
    head->back = newHead;

    return newHead;
}

Node* insertBeforeTail(Node* head, int val) {
    // if only one node
    if(head->next == NULL) {
        return insertBeforeHead(head, val);
    }

    Node* tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* newNode = new Node(val, tail, prev);
    prev->next = newNode;
    tail->back = newNode;

    return head;
}

Node* insertBeforePos(Node* head, int val, int pos) {
    if(pos == 1) {
        return insertBeforeHead(head, val);
    }

    Node* temp = head;
    int cnt = 0;
    while(temp!= NULL) {
        cnt++;
        if(cnt == pos) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;

    return head;
}

void insertBeforeNode(Node* node, int val) {
    // here also we are not inserting at head
    // as question doesnt want to change the head
    Node* prev = node->back;
    Node* newNode = new Node(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
}

int main()
{
    vector<int> arr = {2, 5, 8, 7};

    // convert arr to DLL
    Node* head = convertArr2DLL(arr);
    print(head);

    // delete head
    head = deleteHead(head);
    cout<<"\nDelete head : ";
    print(head);

    // delete tail
    head = deleteTail(head);
    cout<<"\nDelete tail : ";
    print(head);

    head = convertArr2DLL(arr);
    cout<<"\n";
    print(head);

    // delete element at pos
    head = removeElementAtPos(head, 3);
    cout<<"\nDelete at pos 3 : ";
    print(head);


    // delete node
    deleteNode(head->next);
    cout<<"\nDelete 2nd node : ";
    print(head);

    // insert before head
    head = insertBeforeHead(head, 1);
    cout<<"\nInsert 1 before head : ";
    print(head);

    // insert before tail
    head = insertBeforeTail(head, 9);
    cout<<"\nInsert 9 before tail : ";
    print(head);

    // insert before pos
    head = insertBeforePos(head, 4, 3);
    cout<<"\nInsert 4 before pos 3 : ";
    print(head);

    // insert before node
    insertBeforeNode(head->next->next, 6);
    cout<<"\nInsert 6 before 3rd node : ";
    print(head);
    return 0;
}