/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// Function to insert a node in the middle of the linked list.
class Solution {
    int getLen(Node* head){
        Node* temp = head;
        int cnt = 0;
        while(temp != NULL){
            temp = temp -> next;
            cnt++;
        }
        return cnt;
    }
  public:
    Node *insertInMiddle(Node *head, int x) {
        // Code Here
        // int len = getLen(head)/2;
        int len = (getLen(head)&1) ? getLen(head)/2+1 : getLen(head)/2;
        if(len <= 0){
            Node* temp = new Node(x);
            head = temp;
            return head;
        } 
        Node* temp = new Node(x);
        Node* prev = head;
        while(prev != NULL){
            if(len == 1){
                temp -> next = prev -> next;
                prev -> next = temp;
                return head;
            }
            prev = prev -> next;
            len--;
        }
    }
};