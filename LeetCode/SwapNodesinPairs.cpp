Swap Nodes in Pairs


Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.


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
    ListNode *swapPairs(ListNode *head) {
        ListNode * l = NULL;
        ListNode * r = NULL;
        ListNode * h = NULL;
        ListNode * pre = NULL;
        
        if(!head || !head->next) //we must have more than two nodes;
            return head;
            
        l = head;
        r = l->next;
        
        while(l && r)
        {
            
            l->next = r->next;
            r->next = l;
            
            if(!h)
                h = r;
                
            if(pre)
                pre->next = r;
     
            pre = l;
            
            l = l->next;
            
            if(l)
                r = l->next;
            else
                r = NULL;
        }
        
        return h;
    }
};



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
    ListNode *swapPairs(ListNode *head) {
        ListNode * l = NULL;
        ListNode * r = NULL;
        
        if(!head || !head->next) //we must have more than two nodes;
            return head;
            
        l = head;
        r = l->next;
        
        while(l && r)
        {
            int temp = l->val;
            l->val   = r->val;
            r->val   = temp;
            
            l = r->next;
            
            if(l)
                r = l->next;
            else
                r = NULL;
        }
        
        return head;
    }
};
