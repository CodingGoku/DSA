#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* prev;
    Node* next;
    int key;
    int value;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = next = NULL;
    }
};

class LRUcache
{
    public:
    unordered_map<int, Node*> mp;
    int capacity;
    Node* head;
    Node* tail;

    LRUcache(int c) {
        capacity = c;
        mp.clear();
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) return -1; // not found

        Node* node = mp[key];
        deleteNode(node);
        insertAfterHead(node);

        return node->value;
    }

    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];
            deleteNode(node);
            node->value = value; // change node->value to new value
            insertAfterHead(node);
        }
        else {
            if(mp.size() == capacity) { // delete last node if capacity reached
                Node* node = tail->prev;
                deleteNode(node);
                mp.erase(node->key);
            }

            // insert new node, update in map
            Node* newNode = new Node(key, value);
            insertAfterHead(newNode);
            mp[key] = newNode;
        }
    }

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->next = temp;
        node->prev = head;
        temp->prev = node;
    }
};

int main()
{

}