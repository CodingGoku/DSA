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
    Node* mover = head;
    for(int i=1; i<arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover=temp;
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

int lengthOfLL(Node* head) {
    int cnt=0;
    Node* temp = head;
    while(temp)
    {
        //cout<<temp->data<<" ";
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

bool checkIfPresent(Node* head, int val) {
    Node* temp = head;
    while(temp)
    {
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
}

Node* removeHead(Node* head) {
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* removeTail(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;

    Node* temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* removePos(Node* head, int pos)
{
    // if head is null return head
    if(head == NULL) return head;

    // if deleting head
    if(pos == 1) {
        Node* temp = head;
        head=head->next;
        delete temp;
        return head;
    }

    // if deleting any other element
    int cnt=0;
    Node* temp = head;
    Node* prev = NULL;
    // if pos is out of bound then it will just return
    // the head and not go in the `if` to delete anything
    while(temp != NULL) {
        cnt++;
        if(cnt == pos) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* removeEl(Node* head, int el)
{
    // if head is null return head
    if(head == NULL) return head;

    // if deleting head
    if(head->data == el) {
        Node* temp = head;
        head=head->next;
        delete temp;
        return head;
    }

    // if deleting any other element
    Node* temp = head;
    Node* prev = NULL;
    // if pos is out of bound then it will just return
    // the head and not go in the `if` to delete anything
    while(temp != NULL) {

        if(temp->data == el) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* insertHead(Node* head, int val)
{
    Node* temp = new Node(val, head);
    return temp; // returning the new head
}

Node* insertTail(Node* head, int val)
{
    if(head == NULL) return new Node(val);

    Node* temp = head;
    while(temp->next != NULL) {
        temp=temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}

Node* insertPos(Node* head, int val, int pos)
{
    if(head == NULL) {
        // we can only add at pos 1 if LL is empty
        if(pos == 1) return new Node(val);
        else return head;
    }

    // inserting at head
    if(pos == 1) return new Node(val, head);

    // inserting at other positions
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL) {
        cnt++;
        if(cnt == pos-1) {
            Node* x = new Node(val, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node* insertBeforeValue(Node* head, int el,int val)
{
    if(head == NULL) {
        // if there is no value, so before WHAT will you insert
        return NULL;
    }

    // inserting at head
    if(head->data == val) return new Node(el, head);

    // inserting at other positions
    Node* temp = head;
    while(temp != NULL) {
        if(temp->next->data == val) {
            Node* x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {2, 5, 8, 7};
    // y is a pointer to the new Node
    //Node* y = new Node(arr[0]);
    //cout<< y->data;

    Node* head = convertArr2LL(arr);
    print(head);

    cout<<"\nLength of LL : "<<lengthOfLL(head);
    cout<<"\nIs 6 present : "<<checkIfPresent(head, 6);
    cout<<"\nIs 7 present : "<<checkIfPresent(head, 7);

    head = removeHead(head);
    cout<<"After removing head : ";
    print(head);

    head = removeTail(head);
    cout<<"\nAfter removing tail : ";
    print(head);

    // Remove at a given position
    vector<int> arr2 = {1,2,3,4,5};
    head = convertArr2LL(arr2);
    head = removePos(head, 3);
    cout<<"\nRemove pos 3 : ";
    print(head);

    // Remove a given element
    head = convertArr2LL(arr2);
    head = removeEl(head, 4);
    cout<<"\nRemove Element 4 : ";
    print(head);

    // Insert head
    head = insertHead(head, 100);
    cout<<"\nInsert Element 100 at head : ";
    print(head);

    // Insert tail
    head = insertTail(head, 200);
    cout<<"\nInsert Element 200 at tail : ";
    print(head);

    // Insert at a given Position
    head = insertPos(head, 7, 3);
    cout<<"\nInsert Element 7 at Pos 3 : ";
    print(head);

    // Insert before value
    head = insertBeforeValue(head, 8, 3);
    cout<<"\nInsert Element 8 before 3 : ";
    print(head);
    return 0;
}