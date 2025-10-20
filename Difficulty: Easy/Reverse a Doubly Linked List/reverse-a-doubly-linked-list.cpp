/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        int length = 1;
        Node *left = head;
        Node *right = head;
        while(right -> next != NULL){
            right = right -> next;
            length++;
        }
        for(int i = 0; i < length/2; i++){
            swap(left -> data, right -> data);
            left = left -> next;
            right = right -> prev;
        }
        return head;
    }
};