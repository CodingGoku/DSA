#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;

    //constructor
    Node(int val1, Node* next1, Node* prev1) {
        val = val1;
        next = next1;
        prev = prev1;
    }
    //constructor if next not given
    Node(int val1) {
        val = val1;
        next = nullptr;
        prev = nullptr;
    }
};

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

void print(Node* head) {
    Node* temp = head;
    while(temp) // or while temp != null (same thing)
    {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}

// T : O(N)
// S : O(1)
Node* deleteAllOccurencesOfAKey(Node* head, int key) {
    Node* temp = head;
    while(temp != NULL) {
        if(temp->val == key) {
            if(temp == head) {
                head = head->next;
            }

            Node* prevNode = temp->prev;
            Node* nextNode = temp->next;

            // VERY IMP CONDITIONS
            if(prevNode) prevNode->next = nextNode;
            if(nextNode) nextNode->prev = prevNode;
            // delete that node and move to next
            free(temp);
            temp = nextNode;
        }
        else temp = temp->next;
    }

    return head;
}

int main()
{
    vector<int> arr = {10,4,10,10,6,10};
    // convert arr to LL
    Node* head = convertArr2DLL(arr);
    cout<<"\nDLL :";
    print(head);

    head = deleteAllOccurencesOfAKey(head, 10);
    cout<<"\nAfter deleting all occurences of 10: ";
    print(head);
    return 0;
}