Node* findLastNode(Node* head, int c) {
    c--;
    Node* temp = head;
    while(temp != NULL) {
        if(c == 0) return temp;
        temp = temp->next;
        c--;
    }
    return temp;
}