//循环
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
    ListNode* middleNode(ListNode* head) {
        ListNode* end = head, *ret = head;
        int size = 0;
        while(end != nullptr){
            size++;
            end = end->next;
        }

        size /= 2;
        while(size > 0){
            ret = ret->next;
            size--;
        }

        return ret;
    }
};


//快慢指针
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
    ListNode* middleNode(ListNode* head) {
        ListNode* curr = head, *end = head;

        while(end->next != nullptr){
            end = end->next;
            curr = curr->next;

            if(end->next != nullptr){
                end = end->next;
            }
        }

        return curr;
    }
};
