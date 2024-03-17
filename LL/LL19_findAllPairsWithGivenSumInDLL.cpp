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

// T : ~O(N^2) ... near about N^2 but not N^2
// S : O(1)
vector<pair<int, int>> findAllPairsWithGivenSum(Node* head, int sum) {
    if(head == NULL || head->next == NULL) return {{}};

    vector<pair<int, int>> vec;
    Node* temp1 = head;
    Node* temp2;

    while(temp1 != NULL) {
        temp2 = temp1->next;
        // if it is greater than sum then we cannot find it ahead
        // as it will be further greater given DLL is sorted
        while(temp2 != NULL && (temp1->val + temp2->val) <= sum) {
            if((temp1->val + temp2->val) == sum) vec.push_back({temp1->val, temp2->val});

            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return vec;
}

// T : O(N) ... O(N) to get rightmost node + O(N) we either move left or right and visit each node
// S : O(1)
vector<pair<int, int>> findAllPairsWithGivenSumOP(Node* head, int sum) {
    if(head == NULL || head->next == NULL) return {{}};

    vector<pair<int, int>> vec;
    Node* left = head;
    Node* right = head;
    while(right->next != NULL) right = right->next;

    while(right->val > left->val) {
        if((left->val + right->val) == sum) {
            vec.push_back({left->val, right->val});
            // move both left and right
            left = left->next;
            right = right->prev;
        }

        else if((left->val + right->val) > sum) right = right->prev;

        // if((left->val + right->val) < sum)
        else left = left->next;
    }
    return vec;
}

int main()
{
    vector<int> arr = {1,2,3,4,9};
    // convert arr to DLL
    Node* head = convertArr2DLL(arr);
    cout<<"\nDLL :";
    print(head);

    vector<pair<int, int>> vec = findAllPairsWithGivenSum(head, 5);
    cout<<"\n";
    for(auto& p : vec) {
        cout<<p.first<<", "<<p.second<<"\n";
    }

    vec = findAllPairsWithGivenSumOP(head, 5);
    cout<<"\n";
    for(auto& p : vec) {
        cout<<p.first<<", "<<p.second<<"\n";
    }
    return 0;
}