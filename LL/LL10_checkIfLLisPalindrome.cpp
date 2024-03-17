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

Node* reverseLLop(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    Node* prev = NULL;
    Node* temp = head;
    while(temp != NULL) {
        Node* front = temp->next; // store front
        temp->next = prev; // update next
        prev = temp; // move prev ahead
        temp = front; // move temp ahead
    }
    // new head as now temp is NULL
    return prev;
}

// T : O(2N) ... 2 iterations
// S : O(N) ... stack space
bool checkPalindrome(Node* head) {
    if(head == NULL || head->next == NULL) return true;

    stack<int> st;
    Node* temp = head;
    // insert in stack
    while(temp != NULL) {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    // check palindrome
    while(temp != NULL) {
        if(temp->data != st.top()) return false;
        st.pop();
        temp = temp->next;
    }
    return true;
}

// T : O(2N) ... N/2-fast/slow, N/2-reverse, N/2-first/second, N/2-reverse
// S : O(1)
bool checkPalindromeOP(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    Node* slow = head;
    Node* fast = head;
    // for odd and even length cases
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // newHead is the tail of the given LL
    Node* newHead = reverseLLop(slow->next);
    Node* first = head;
    Node* second = newHead;
    while(second != NULL) {
        if(first->data != second->data) {
            // reverse again before returning
            reverseLLop(newHead);
            return false;
        }
        // move first and second
        first = first->next;
        second = second->next;
    }

    // reverse again before returning
    reverseLLop(newHead);
    return true;
}

int main()
{
    vector<int> arr = {1,2,3,2,1};
    // convert arr to LL
    Node* head = convertArr2LL(arr);
    cout<<"\nLL: ";
    print(head);

    cout<<"\nisPalindrome: ";
    cout<<checkPalindrome(head);

    cout<<"\nisPalindromeOP: ";
    cout<<checkPalindromeOP(head);

    return 0;
}