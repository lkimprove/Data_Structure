/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr){
            return l2;
        }
        else if(l2 == nullptr){
            return l1;
        }

        ListNode* curr1 = l1, *curr2 = l2, *head = nullptr;
        if(curr1->val < curr2->val){
            head = curr1;
            curr1 = curr1->next;
        }
        else{
            head = curr2;
            curr2 = curr2->next;
        }

        ListNode* temp = head;
        while(curr1 != nullptr && curr2 != nullptr){
            if(curr1->val < curr2->val){
                temp->next = curr1;
                curr1 = curr1->next;
            }
            else{
                temp->next = curr2;
                curr2 = curr2->next;
            }
            temp = temp->next;
        }

        if(curr1 != nullptr){
            temp->next = curr1;
        }
        if(curr2 != nullptr){
            temp->next = curr2;
        }

        return head;
    }
};



//利用哨兵节点进行优化
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;

        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2->val){
                curr->next = l1;
                l1 = l1->next;
            }
            else{
                curr->next = l2;
                l2 = l2->next;
            }

            curr = curr->next;
        }

        curr->next = (l1 == nullptr ? l2 : l1);

        curr = head->next;
        delete head;
        return curr;
    }
};

