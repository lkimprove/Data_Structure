/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        if(pHead == nullptr){
            return pHead;
        }
        
        ListNode* small = new ListNode(0);
        ListNode* big = new ListNode(0);
        ListNode* ps = small, *pb = big, *curr = pHead;
        
        while(curr != nullptr){
            if(curr->val < x){
                ps->next = curr;
                ps = ps->next;
            }
            else{
                pb->next = curr;
                pb = pb->next;
            }
            curr = curr->next;
        }
        
        ps->next = big->next;
        pb->next = nullptr;
        pHead = small->next;
        
        delete small;
        delete big;
        
        
        return pHead;
    }
};
