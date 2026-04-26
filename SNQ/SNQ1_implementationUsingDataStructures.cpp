#include <bits/stdc++.h>
using namespace std;

// T : O(1) ... for each function
// S : O(N) ... for array
class stackUsingArray {
    int st[10]; // size of stack
    int top=-1;

    void push(int x) {
        if(top >= 9) { // last index was 9
            cout<<"Stack Overflow";
            return;
        }

        top++;
        st[top] = x;
    }

    int top() {
        if(top == -1) {
            cout<<"Stack is Empty!";
            return -1;
        }

        return st[top];
    }

    void pop() {
        if(top == -1) {
            cout<<"Stack Underflow!";
            return;
        }
        
        top--;
    }

    int size() {
        return top+1;
    }
};

// T : O(1) ... for each function
// S : O(N) ... for array
class queueUsingArray {
    int size=10;
    int q[10];
    int currSize=0, start=-1, end=-1;

    void push(int x) {
        if(currSize == size) {
            cout<< "Queue Overflow!";
            return;
        }

        if(currSize == 0) {
            start=0;
            end=0;
        }
        else {
            end = (end+1)%size;
        }

        q[end] = x;
        currSize++;
    }

    int pop() {
        if(currSize == 0) {
            cout<<"Queue Underflow!";
            return;
        }

        int d = q[start];
        if(currSize == 1) {
            start = end = -1;
        }
        else {
            start = (start+1)%size;
        }

        currSize--;
        return d;
    }

    int front() {
        if(currSize == 0) {
            cout<<"Queue is Empty!";
            return -1;
        }

        return q[start];
    }

    int size() {
        return currSize;
    }
};

// T : O(1) ... for each function
// S : dynamic
class stackUsingLL {
    struct Node {
        int data;
        Node* next;

        Node(int d) {
            data = d;
            next = NULL;
        }
    };

    Node* top = NULL;
    int size = 0;

    void push(int x) {
        Node* temp = new Node(x);
        temp->next = top;
        top = temp; // update top element of stack
        size++;
    }

    void pop() {
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    int top() {
        return top->data;
    }

    int size() {
        return size;
    }
};

// T : O(1) ... for each function
// S : dynamic
class queueUsingLL {
    struct Node {
        int data;
        Node* next;

        Node(int d) {
            data = d;
            next = NULL;
        }
    };

    Node* start = NULL;
    Node* end = NULL;
    int size = 0;

    void push(int x) {
        Node* temp = new Node(x);
        if(start==NULL) { // inserting the first element
            start = end = temp;
        }
        else {
            end = temp;
        }
        size++;
    }

    void pop() {
        if(start == NULL) {
            cout<<"Queue Underflow!";
            return;
        }

        Node* temp = start;
        start = start->next;
        delete temp;
        size--;
    }

    int top() {
        if(start == NULL) {
            cout<<"Queue is Empty!";
            return;
        }

        return start->data;
    }

    int size() {
        return size;
    }
};

// T : O(N) for push function, others O(1)
// S : dynamic
class stackUsingQueue {
    queue<int> q;

    void push(int x) {
        int s = q.size();
        q.push(x);

        // to get the new element in the front of queue
        for(int i=0; i<s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        q.pop();
    }

    int top() {
        return q.front();
    }
};

// T : O(2N) for push function, others O(1)
// S : 2 x dynamic
class queueUsingStack {
    stack<int> st1, st2;

    void push(int x) {
        // st1 -> st2
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        // push x to st1
        st1.push(x);
        // st2 -> st1
        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }

    void pop() {
        st1.pop();
    }

    int front() {
        return st1.top();
    }
};

int main()
{
    return 0;
}