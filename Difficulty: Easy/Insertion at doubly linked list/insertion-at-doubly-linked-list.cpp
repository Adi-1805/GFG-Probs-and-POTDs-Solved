/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        // code here
        Node *newNode = new Node(x);
        Node *prevNode = head;
        while(p--){
            prevNode = prevNode -> next;
        }
        if(prevNode -> next == NULL) {
            newNode -> prev = prevNode;
            prevNode -> next = newNode;
            newNode -> next = NULL;
        } else {
            Node* nextNode = prevNode -> next;
            newNode -> next = nextNode;
            nextNode -> prev = newNode;
            prevNode -> next = newNode;
            newNode -> prev = prevNode;
        }
        return head;
    }
};