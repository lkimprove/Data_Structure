//双指针
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
    bool hasCycle(ListNode *head) {
        if(head == nullptr){
            return false;
        }

        ListNode* slow = head, *quick = head->next;
        while(quick != nullptr){
            if(slow == quick){
                return true;
            }

            quick = quick->next;
            slow = slow->next;

            if(quick != nullptr){
                quick = quick->next;
            }
        }

        return false;
    }
};


//哈希表
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
    bool hasCycle(ListNode *head) {
        if(head == nullptr){
            return false;
        }

        unordered_set<ListNode*> s;
        ListNode* curr = head;
        while(curr != nullptr){
            if(s.count(curr)){
                return true;
            }
            
            s.insert(curr);
            curr = curr->next;
        }

        return false;
    }
};
