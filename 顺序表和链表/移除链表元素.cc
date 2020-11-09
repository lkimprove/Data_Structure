/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //判空
        if(head == nullptr){
            return head;
        }

        //创建一个在头节点前的临时变量
        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* curr = head, *prev = temp, *toDelete = nullptr;

        while(curr != nullptr){
            if(curr->val == val){
                prev->next = curr->next;
                toDelete = curr;
            }
            else{
                prev = curr;
            }
            curr = curr->next;

            //删除元素
            if(toDelete != nullptr){
                delete toDelete;
                toDelete = nullptr;
            }
        }

        head = temp->next;
        delete temp;

        return head;
    }
};
