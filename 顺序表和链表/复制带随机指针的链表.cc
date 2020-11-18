/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //判空
        if(head == nullptr){
            return head;
        }

        //复制节点
        Node* curr = head;
        while(curr != nullptr){
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;

            curr = newNode->next;
        }

        //复制random指针
        curr = head;
        while(curr != nullptr){
            if(curr->random != nullptr){
                curr->next->random = curr->random->next;
            }

            curr = curr->next->next;
        }

        //分离新链表
        curr = head;
        Node* newHead = head->next, *temp = head->next; 
        while(curr != nullptr){
            curr->next = temp->next;
            curr = temp->next;

            if(curr != nullptr){
                temp->next = curr->next;
                temp = curr->next;
            }
        }

        return newHead;
    }
};
