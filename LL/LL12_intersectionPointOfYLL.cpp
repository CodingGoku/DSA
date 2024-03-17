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

Node* collisionPoint(Node* t1, Node* t2, int d) {
    // get to the same level
    while(d) {
        d--;
        t2 = t2->next;
    }

    // compare nodes
    while(t1 != t2) {
        t1 = t1->next;
        t2 = t2->next;
    }
    // return the intersecting node
    return t1;
}

// T : O(N1 + N2) for iterations, + O(N2-N1) till collisionPoint + O(N1) shorter LL
// S : O(1)
Node* intersectionPointOfYLL(Node* head1, Node* head2) {
    Node* t1 = head1;
    Node* t2 = head2;
    int n1=0, n2=0;

    // calculate size of LL1
    while(t1 != NULL) {
        n1++;
        t1 = t1->next;
    }

    // calculate size of LL2
    while(t2 != NULL) {
        n2++;
        t2 = t2->next;
    }

    if(n1 < n2) return collisionPoint(head1, head2, n2-n1);
    else return collisionPoint(head2, head1, n1-n2);
}

// T : O(N1+N2) ... if not found it traverses both LL
// S : O(1)
Node* intersectionPointOfYLLop(Node* head1, Node* head2) {
    Node* t1 = head1;
    Node* t2 = head2;

    while(t1 != t2) {
        t1 = t1->next;
        t2 = t2->next;
    }

    if(t1 == t2) return t1;

    if(t1 == NULL) t1 = head2;
    if(t2 == NULL) t2 = head1;

    // if none coincide then they t1 and t2 both will
    // point to NULL at the end and hence we return null
    // and if first element coincides, it won't go in the
    // while loop and we are returning it
    return t1;
}

int main()
{
    Node* head1;
    Node* head2;


    return 0;
}