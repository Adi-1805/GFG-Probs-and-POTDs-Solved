/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* delPos(Node* head, int x) {
        // code here
        Node* curNode = head;
        int count = 1;
        while(count < x){
            curNode = curNode -> next; count++;
        }
        if(curNode == head){
            head = curNode -> next;
            head -> prev = NULL;
        }else if(curNode -> next == NULL){
            Node* prevNode = curNode -> prev;
            prevNode -> next = NULL;
        }else{
            Node* prevNode = curNode -> prev;
            Node* nextNode = curNode -> next;
            
            prevNode -> next = curNode -> next;
            nextNode -> prev = curNode -> prev;
        }
        delete(curNode);
        return head;
    }
};