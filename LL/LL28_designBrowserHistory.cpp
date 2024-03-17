#include <bits/stdc++.h>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node* back;

    //constructor
    Node(string data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }
    //constructor if next not given
    Node(string data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

class Browser {
    Node* currentPage;
    public:

    //constructor
    Browser(string &homepage)
    {
        // at the beginning we have homepage as head of LL
        currentPage = new Node(homepage);
    }

    void visit(string &url)
    {
        Node* newNode = new Node(url);
        currentPage->next = newNode;
        newNode->back = currentPage;
        currentPage = newNode;
    }

    string back(int steps)
    {
        while(steps) {
            // go back if back is not NULL
            if(currentPage->back) currentPage = currentPage->back;
            else break;

            steps--;
        }
        return currentPage->data;
    }

    string forward(int steps)
    {
        while(steps) {
            // go forward if forward is not NULL
            if(currentPage->next) currentPage = currentPage->next;
            else break;

            steps--;
        }
        return currentPage->data;
    }
};

int main()
{
    return 0;
}