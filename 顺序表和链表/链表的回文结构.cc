//使用vector储存链表节点数据
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        // write code here
        if(A == nullptr){
            return true;
        }
        
        ListNode* curr = A;
        vector<int> v;
        while(curr != nullptr){
            v.push_back(curr->val);
            curr = curr->next;
        }
        
        if(v.size() % 2 != 0){
            return false;
        }
        
        int start = 0, end = v.size() - 1;
        
        while(start < end){
            if(v[start] == v[end]){
                start++;
                end--;
            }
            else{
                return false;
            }
        }
        
        return true;
    }
};


//空间复杂度为O(1)
//利用快慢指针+反转链表
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        // write code here
        if(A == nullptr || A->next == nullptr){
            return true;
        }
        
        ListNode* quick = A, *slow = A;
        int size = 1;
        while(quick->next != nullptr){
            quick = quick->next;
            size++;
            slow = slow->next;
            
            if(quick->next != nullptr){
                quick = quick->next;
                size++;
            }
        }
        
        //回文链表的节点数必为偶数
        if(size % 2 != 0){
            return false;
        }
        
        //从slow位置开始反转链表
        ListNode* prev = nullptr, *curr = slow;
        while(curr != nullptr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        //判断是否为回文链表
        curr = A;
        while(quick != nullptr){
            if(quick->val == curr->val){
                quick = quick->next;
                curr = curr->next;
            }
            else{
                return false;
            }
        }
        
        return true;
    }
};



