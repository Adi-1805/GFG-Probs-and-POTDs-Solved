/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node *slow = head, *fast = head;
        // detecting cycle
        bool cycle = 0; // assuming no cycle
        while(fast != NULL and fast->next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) { cycle = 1; break; }
        }
        if(!cycle) return 0;
        // finding where cycle begins
        int length = 1;
        fast = fast -> next;
        while(slow != fast){
            fast = fast -> next;
            length++;
        }
        return length;
    }
};